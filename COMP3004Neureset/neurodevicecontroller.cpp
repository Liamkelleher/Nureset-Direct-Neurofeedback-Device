#include "neurodevicecontroller.h"
#include <QDebug>


/*
 *
 * Description:
 * This is the initialization for the Main Controler for the EEG Device
 *
*/

NeuroDeviceController::NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd, QProgressBar* progressBar, QProgressBar* batteryCharge, QComboBox* dropdown)
{
    //Default Values
    deviceOn = false;
    sesActive = false;
    sesPaused = false;
    connection = false;
    sessionCreated = false;
    roundsCompleted = 0;
    currStep = 0;
    isExpired = false;

    //Light indicatior initilization
    contactLightIndicator = new LightIndicator(contactInd);
    treatmentLightIndicator = new LightIndicator(treatmentInd);
    contactLostLightIndicator = new LightIndicator(contactLostInd);


    manager = new SessionManager();

    display = new Display(stackedWidget);

    headset = new EEGHeadset();

    this->dropdown = dropdown;

    //Initilizes and sets time
    deviceTime = QDateTime::currentDateTime();

    //Timer Setup
    timer = new QTimer(this);
    elTimer = new QElapsedTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUiTimer()));
    savedTime = 0;

    progBar = progressBar;
    batCharge = batteryCharge;

    treatment = new Treatment();

    contactLost = new ContactLost();

    connect(this, &NeuroDeviceController::setValueBat, batCharge, &QProgressBar::setValue);
    connect(this, &NeuroDeviceController::setValueProg, progBar, &QProgressBar::setValue);
    connect(this, &NeuroDeviceController::upArrowButton, display, &Display::upArrowButton);
    connect(this, &NeuroDeviceController::downArrowButton, display, &Display::downArrowButton);
    connect(this, &NeuroDeviceController::startButton, display, &Display::startButton);
    connect(this, &NeuroDeviceController::stopButton, display, &Display::stopButton);
    connect(this, &NeuroDeviceController::menuButton, display, &Display::menuButton);
    connect(this, &NeuroDeviceController::powerOffDisplay, display, &Display::powerOffDisplay);
    connect(this, &NeuroDeviceController::powerOnDisplay, display, &Display::powerOnDisplay);
    connect(display, &Display::uploadSession, this, &NeuroDeviceController::uploadSession);
    connect(display, &Display::updateDateTime, this, &NeuroDeviceController::setDateTime);
    connect(this, &NeuroDeviceController::sessionComplete, display, &Display::sessionComplete);
    connect(this, &NeuroDeviceController::applyTreatment, treatment, &Treatment::applyTreatment);
    connect(this, &NeuroDeviceController::togglePause, treatment, &Treatment::togglePauseTreatment);
    connect(this, &NeuroDeviceController::resumeTreatment, treatment, &Treatment::resumeTreatment);
    connect(treatment, &Treatment::beforeDominantFreq, this, &NeuroDeviceController::addBeforeDominant);
    connect(treatment, &Treatment::afterDominantFreq, this, &NeuroDeviceController::addAfterDominant);
    connect(treatment, &Treatment::beforeBase, this, &NeuroDeviceController::addBeforeBase);
    connect(treatment, &Treatment::afterBase, this, &NeuroDeviceController::addAfterBase);
    connect(treatment, &Treatment::avgAmp, this, &NeuroDeviceController::addAvgAmp);
    connect(treatment, &Treatment::sendFeedback, this, &NeuroDeviceController::getFeedbackFreq);
    connect(treatment, &Treatment::captureAllWaves, this, &NeuroDeviceController::captureAllWaves);
    connect(treatment, &Treatment::endAnalysis, this, &NeuroDeviceController::endAnalysis);
    connect(treatment, &Treatment::toggleTreatmentLight, this, &NeuroDeviceController::toggleTreatmentLight);
    connect(this, &NeuroDeviceController::getInitialBaseline, headset, &EEGHeadset::getInitialBaseline);
    connect(headset, &EEGHeadset::startAnalysis, this, &NeuroDeviceController::startAnalysis);
    connect(this, &NeuroDeviceController::pausedWarning, contactLost, &ContactLost::pausedWarning);
    connect(this, &NeuroDeviceController::contactWarning, contactLost, &ContactLost::contactWarning);
    connect(contactLost, &ContactLost::toggleContactLostLight, this, &NeuroDeviceController::toggleContactLostLight);
    connect(contactLost, &ContactLost::sessionExpired, this, &NeuroDeviceController::sessionExpired);

    //moves the display, headset, treatment, and contact lost classes to new threads
    display->moveToThread(&_DISThread);
    headset->moveToThread(&_HeadSetThread);
    treatment->moveToThread(&_TreatThread);
    contactLost->moveToThread(&_CLThread);

    _DISThread.start();
    _HeadSetThread.start();
    _TreatThread.start();
    _CLThread.start();
}

NeuroDeviceController::~NeuroDeviceController()
{
    _DISThread.exit();
    _DISThread.wait();

    _HeadSetThread.exit();
    _HeadSetThread.wait();

    _TreatThread.exit();
    _TreatThread.wait();

    _CLThread.exit();
    _CLThread.wait();

    delete contactLightIndicator;
    delete contactLostLightIndicator;
    delete treatmentLightIndicator;
    delete manager;
    delete display;
    delete headset;
    delete treatment;
    delete contactLost;
}

//Extends button handlers from MainWindow
void NeuroDeviceController::upArrowButtonPressed() { if (deviceOn) { emit upArrowButton(); } }
void NeuroDeviceController::downArrowButtonPressed() { if (deviceOn) { emit downArrowButton(); } }

/*
 *
 * Description:
 * Communicates to the necessary components when the start button is pressed in the Main Menu
 *
 * Given:
 * None
 *
 * Returns:
 * None
 *
*/

void NeuroDeviceController::startButtonPressed()
{
    if (deviceOn)
    {
        emit startButton(connection);

        //Checks which UI is being displayed to user
        //Case 1 : Start Session
        if (display->getCurrentMenuSelect() == 0)
        {
            if (!connection)
            {
                qDebug() << "\n\nINFO: Cannot start session. Please re-establish connection.\n\n";
            }
            else
            {
                if (!sesActive && connection)
                {
                    checkBatteryLevel(0);     
                    startSession();
                }
            }
        }
        //Case 2: Check session history
        if (display->getCurrentMenuSelect() == 1)
        {
            display->populateSessionLogs(manager->getSessionLog());
        }

        //Check if session is in progress but paused and resume it.
        if (sesActive && sesPaused && connection)
        {
            resumeSession();
        }
    }
}

//Handle communicating information between the headset and the session manager
void NeuroDeviceController::getFeedbackFreq() { nodeTreated(); }

void NeuroDeviceController::captureAllWaves() { headset->captureAllWaves(); }

void NeuroDeviceController::addBeforeDominant(QVector<double> freq) { manager->addBeforeDF(freq); }
void NeuroDeviceController::addAfterDominant(QVector<double> freq) { manager->addAfterDF(freq); }
void NeuroDeviceController::addBeforeBase(double freq) { manager->updateBeforeBaseline(freq); }
void NeuroDeviceController::addAfterBase(double freq) { manager->updateAfterBaseline(freq); }
void NeuroDeviceController::addAvgAmp(double amp) { manager->updateAvgAmp(amp); }

/*
 *
 * Description:
 *  Checks if usage would NOT drain the battery. I
 *  If the battery would be drained calls powerOFF to shut off device.
 *
 * Given:
 * Takes in a intager representing power usage
 *
 * Returns:
 * True if battery is not drained
 * False if battery is drained
 *
*/
bool NeuroDeviceController::checkBatteryLevel(int btDrain)
{
    //Handles the battery would fall to 0 or below
    if (batCharge->value() - btDrain <= 0)
    {
        qDebug() << "\nINFO: Device battery has died";
        updateBattery(batCharge->minimum());
        powerOff();
        return false;
    }
    //Sends warning if battery below 30%
    if (batCharge->value() - 30 <= 0)
    {
        qDebug() << "WARNING: Battery is low";
    }
    return true;
}

/*
 *
 * Description:
 * Updates Proress bar to a new level, Splits the change into smaller increments over time
 *
 * Given:
 * Takes in a intager value of the new progress level
 *
 * Returns:
 * None
 *
*/
void NeuroDeviceController::updateProgressBar(int value)
{
    //Calculates a 10th of the new difference between the new value and old
    int increment = (value - progBar->value()) / 10;

    // The QTimer's timeout signal will call the lambda function
    QTimer *timer = new QTimer(this);
    timer->start(50);

    connect(timer, &QTimer::timeout, this, [this, value, increment, timer]() {
        // Increment the progress bar's value
        int newValue = progBar->value() + increment;

        // Ensure the new value does not exceed the final value
        if ((increment > 0 && newValue > value) ||
            (increment < 0 && newValue < value)) {
            newValue = value;
        }

        // Update the progress bar and check if we've reached the final value
        emit setValueProg(newValue);
        if (newValue == value) {
            timer->stop();
            timer->deleteLater();

            if (newValue == progBar->maximum())
            {
                sesActive = false;
                emit sessionComplete();

            }
        }
    });
}
/*
 *
 * Description:
 * Updates battery to a new level, Splits the change into smaller increments over time
 *
 * Given:
 * Takes in a intager value of the new battery level
 *
 * Returns:
 * None
 *
*/

void NeuroDeviceController::updateBattery(int value)
{
    int currentValue = batCharge->value();

    //Calculates a 10th of the Difference in new value to old
    int increment = (value - currentValue) / 10;
    //Bounds check
    if (increment == 0) {
        increment = (value != currentValue) ? (value > currentValue ? 1 : -1) : 0;
    }
    //Sets timer for process
    QTimer *timer = new QTimer(this);
    timer->start(50);

    connect(timer, &QTimer::timeout, this, [this, timer, value, increment]() mutable {
        int newValue = batCharge->value() + increment;

        //Check if bounds of new battery level
        //stops timer and sets to exatly given value if newValue would take it over target.
        if ((increment > 0 && newValue >= value) || (increment < 0 && newValue <= value)) {
            newValue = value;
            emit setValueBat(newValue);
            timer->stop();
            timer->deleteLater();
        } else {
            emit setValueBat(newValue);
        }
    });
}

/*
 * Description:
 * After retrieving the initial baseline, the device begins
 * its analasis by capturing every individual node and applying
 * the treatment based on the baseline in the treatment calss
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::startAnalysis()
{
    if (!sesActive || sesPaused) { return; }
    updateProgressBar(progBar->value() + 30);

    //Check if battery has enough charge remaing exit if no
    if (!checkBatteryLevel(15))
        return;
    updateBattery(batCharge->value() - 15);

    for (int i = 0; i < NUM_NODES; ++i)
    {
        (*headset)[i].captureWave();
    }

    emit updateGraph(&(*headset)[dropdown->currentIndex()]);
    emit applyTreatment(headset);
    ++currStep;
}

/*
 * Description:
 * After treating a node during a round of treatment,
 * the NDC updates the graph of the treated node and
 * and progresses the next round of treatment
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::nodeTreated()
{
    if (!sesActive || sesPaused) { return; }

    roundsCompleted += 1;
    updateProgressBar((progBar->value() + 10));
    if (!checkBatteryLevel(5))
        return;
    updateBattery(batCharge->value() - 5);
    emit updateGraph(&(*headset)[dropdown->currentIndex()]);

    if (roundsCompleted == 4)
    {
        ++currStep;
    }
}

/*
 * Description:
 * After all nodes have undergone all 4 rounds of treatment
 * and the final baseline is documented, the NDC stops the
 * internal timer and concludes the session
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::endAnalysis()
{
    if (!sesActive || sesPaused) { return; }
    qDebug() << "INFO: Therapy has finished\n\n";
    updateProgressBar(progBar->value() + (progBar->maximum() - progBar->value()));
    if (!checkBatteryLevel(15))
        return;
    updateBattery(batCharge->value() - 15);
    QTimer::singleShot(1500, this, SLOT(endSession()));
}

/*
 * Description:
 * Handles the when the stop button is pressed while in a session
 * Ends the session and cancels the treatment
 *
 * Input:
 * None
 *
 * Output:
 * None
*/

void NeuroDeviceController::stopButtonPressed()
{
    if (deviceOn && sesActive)
    {
        qDebug() << "\n\nINFO: Therapy has been cancelled\n\n";
        endSession();
        sesActive = false;
        emit stopButton();
        treatment->cancelTreatment();
        contactLost->setPausedState(false);
    }
}

/*
 * Description:
 * Handles the when the power button is pressed.
 * Turning on if enough power or off if on
 *
 * Input:
 * None
 *
 * Output:
 * None
*/

void NeuroDeviceController::powerButtonPressed()
{
    if (batCharge->value() <= 0) { return; }
    //

    if(deviceOn)
    {
        powerOff();
    }
    else
    {
        emit powerOnDisplay();
        if (connection)
            contactLightIndicator->updateState(LightIndicatorState::ContactEstablished);
        deviceOn = true;
    }
}

/*
 * Description:
 * If any sessions are active, the device ends the sessions,
 * after which the device updates the light indicators, informs
 * the treatment class to cancel any ongoing treatments, and
 * powers off the dispaly
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::powerOff()
{
    if(sesActive)
    {
        endSession();
        sesActive = false;
    }

    //Shutdown Protocols
    contactLightIndicator->updateState(LightIndicatorState::Off);
    treatmentLightIndicator->updateState(LightIndicatorState::Off);

    treatment->cancelTreatment();
    contactLost->setContactState(false);
    contactLost->setPausedState(false);

    emit powerOffDisplay();

    sesPaused = false;
    deviceOn = false;
}

//Extends button handlers from MainWindow
void NeuroDeviceController::menuButtonPressed() { if (deviceOn && !sesActive) { emit menuButton(); } }

/*
 * Description:
 * Sends selected session info to the PC for display
 *
 * Input:
 * Intager representing a selection from the menu
 *
 * Output:
 * None
*/
void NeuroDeviceController::uploadSession(int index)
{
    SessionLog *log = manager->getSessionLog();
    Session *session = &(*log)[index];
    emit uploadToPC(session);
}

/*
 * Description:
 * The NDC sets the session active status to true, resets the
 * current step in the LENS process, resets the treatment and
 * graphs and timer to their defaults, checks for the contact
 * between the NDC and the nodes, creates a new session, and
 * initialises the LENS protocol
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::startSession()
{
    sesActive = true;
    sesPaused = false;
    currStep = 0;
    roundsCompleted = 0;
    display->updateTimer(0);
    emit setValueProg(0);
    emit updateGraph(nullptr);
    headset->clearNodes();
    resetTimer();
    if (connection)
        contactLightIndicator->updateState(LightIndicatorState::ContactEstablished);
    manager->createSession(deviceTime);
    isExpired = false;
    QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 1000));
    elTimer->start();
    ++currStep;
    qDebug() << "\n\nINFO: Therapy has started\n";
    qDebug() << "TREATMENT: Processing input wave signals";
    emit getInitialBaseline();
}

/*
 * Description:
 * Similar to start session, resets the current step in the LENS
 * process, resets the timer to its default, informs the session
 * manager to end the session and returns the display to the menu
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::endSession()
{
    roundsCompleted = 0;
    currStep = 0;
    qint64 finalTime = savedTime;
    if (!sesPaused)
        finalTime += elTimer->elapsed();
    manager->endSession(QTime(0,0).addMSecs(static_cast<int>(finalTime - 1500)), !isExpired);
    isExpired = false;
    sesActive = false;
    sesPaused = true;
    treatmentLightIndicator->updateState(LightIndicatorState::Off);
    resetTimer();
    emit setValueProg(progBar->minimum());
    display->updateTimer(0);
    emit menuButton();
}

/*
 * Description:
 * When the pause button is selected during a active session this handles informing all other components
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::pauseSession()
{
    if (sesPaused)
        return;
    if (sesActive)
    {
        if (connection)
        {
            contactLost->setPausedState(true);
            treatment->togglePauseTreatment(true);
            emit pausedWarning();
        } else {
            treatment->togglePauseTreatment(true);
        }
        qDebug() << "INFO: Therapy paused";
        sesPaused = true;
        savedTime += elTimer->elapsed();
        QMetaObject::invokeMethod(timer, "stop", Qt::QueuedConnection);
        elTimer->invalidate();
    }
}

/*
 * Description:
 * Handles resuming a paused session.
 * Checks if a session can be resumed and handles resuming the session
 * and allerting all components.
 *
 * Input:
 * None
 *
 * Output:
 * None
*/

//Returns the NDC and all other components into their previous states
void NeuroDeviceController::resumeSession()
{
    if (!sesPaused)
        return;
    sesPaused = false;
    contactLost->setPausedState(false);
    treatment->togglePauseTreatment(false);

    if (!elTimer->isValid())
    {
        elTimer->restart();
    }
    QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 1000));

    switch (currStep){
        case 1:
        // restart analysis from begining
            qDebug() << "\nINFO: Restarting treatment\n";
            qDebug() << "TREATMENT: Processing input wave signals";
            emit getInitialBaseline();
            break;
        case 2:
        // resume to current round
            qDebug() << "INFO: Resuming treatment at round " << roundsCompleted + 1 << "\n";
            emit resumeTreatment(currStep, roundsCompleted + 1);
            break;
        case 3:
        // restart after baseline calculation
            qDebug("\nINFO: Resuming treatment at after baseline calculation\n");
            emit resumeTreatment(currStep, -1);
            break;
        default:
            break;
        }

}

/*
 * Description:
 * Resets internal device timer
 *
 * Input:
 * None
 *
 * Output:
 * None
*/

void NeuroDeviceController::resetTimer()
{
    if (timer->isActive()) {
        QMetaObject::invokeMethod(timer, "stop", Qt::QueuedConnection); // Ensures timer is stopped before resetting
    }

    elTimer->invalidate();
    savedTime = 0;
    pausedTime = 0;
}


//Updates ui timer based on the timeout() signal from QTimer
void NeuroDeviceController::updateUiTimer()
{
    qint64 msecsElapsed = savedTime + elTimer->elapsed();
    display->updateTimer(msecsElapsed);
}

void NeuroDeviceController::setDateTime(QDateTime newDateTime) { this->deviceTime = newDateTime; }

void NeuroDeviceController::nodeDisplayChanged(int index) { emit updateGraph(&(*headset)[index]); }

/*
 * Description:
 * Sets the treatment light to a given state
 *
 * Input:
 * Bool representing light status
 *
 * Output:
 * None
*/
void NeuroDeviceController::toggleTreatmentLight(bool on)
{
    if (on && sesActive && !sesPaused)
    {
        treatmentLightIndicator->updateState(LightIndicatorState::TreatmentInProgress);
    }
    else
    {
        treatmentLightIndicator->updateState(LightIndicatorState::Off);
    }
}
/*
 * Description:
 * Sets the contact light to a given state
 *
 * Input:
 * Bool representing light status
 *
 * Output:
 * None
*/
void NeuroDeviceController::toggleContactLostLight(bool on)
{
    if (on)
    {
        contactLostLightIndicator->updateState(LightIndicatorState::ContactLost);
    }

    else
    {
        contactLostLightIndicator->updateState(LightIndicatorState::Off);
    }
}

/*
 * Description:
 * Handles when connection is lost between the EEG headset and the LENSE device
 * Pauses a session if one is active.
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::terminateConnection()
{
    if (connection == true && deviceOn)
    {
        connection = false;
        contactLost->setContactState(true);
        contactLightIndicator->updateState(LightIndicatorState::Off);
        qDebug() << "\nINFO: Contact Lost\n";
        if (sesPaused)
            contactLost->setPausedState(false);
        emit contactWarning();
        if (sesActive && !sesPaused)
        {
            pauseSession();
        }
    }
}

/*
 * Description:
 * Handles when connection is re-established between the EEG headset and the LENSE device
 * Updates all the components of a session if one is paused.
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::establishConnection()
{
    if (connection == false && deviceOn)
    {
        connection = true;
        contactLost->setContactState(false);
        contactLightIndicator->updateState(LightIndicatorState::ContactEstablished);
        qDebug() << "\nINFO: Contact Re-established\n";
        if (sesActive && sesPaused)
            resumeSession();
    }
}

/*
 * Description:
 * Handles when a session expires. This happens from test button in controll panel.
 *
 * Input:
 * None
 *
 * Output:
 * None
*/
void NeuroDeviceController::sessionExpired()
{
    qDebug() << "\n\nINFO: Session Expired, device turned off.\n\n";
    isExpired = true;
    powerOff();
}
