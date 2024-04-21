# Neurset
Neurset is a direct neurofeedback EEG device designed and developed by Josh, Aleksey, Liam, and Ryan

Demo Video - [Watch on YouTube](https://www.youtube.com/watch?v=EnQjXWVbXbM)

## Contributors
- **Josh Saikali**
- **Aleksey Dosov**
- **Liam Kelleher**
- **Ryan McDonald**

## Launching and Building Instructions
- The .pro file is located in the COMP3004Neureset folder.
- Execute the COMP3004Neureset.pro file and Qt creator will open with all components loaded.

- If you want to launch the executable file outside Qt creator, navigate to the build-COMP3004Neureset-Desktop-Debug folder.
- Execute the COMP3004Neureset file and the program will launch outside of Qt creator.

- Ensure that the build-COMP3004Neureset-Desktop-Debug folder and the COMP3004Neureset folder are in the same directory just as presented in compressed folder.

- Note: Running the program outside the Qt creator will remove access to the console output provided by QtDebug.
- Most NDC information is printed to the console output.

## Contributions

### Josh:
Use Case and Use Case Diagram,
Sequence Diagrams (Low Battery and PC viewing),
PCDevice,
EEGHeadset,
EEGNode,
Session,
SessionLog,
SessionManager,
Waveform,
Treatment,
NeuroDeviceController,
MainWindow,
Wave Graph Display,
Wave Generation

### Aleksey:
UML Class Diagrams,
Scenario Demo Video,
Traceability Matrix,
Sequence Diagrams (Normal Operation),
Display,
Treatment,
ContactLost,
NeuroDeviceController,
MainWindow

### Liam:
Use Case Diagrams, 
Sequence Diagram (Contact Lost),
Session,
SessionLog,
SessionManager,
Waveform,
LightIndicator,
Treatment,
NeuroDeviceController,
MainWindow

### Ryan:
State Diagram (NeuroDeviceController),
State Diagram (Session Manager),
Session Mangager,
Session

## MainWindow:
Handles user input and all UI components outside the main device

## PCDevice:
External UI that shows detailed information on uploaded session logs

## NeuroDeviceController:
Contains the main communication paths between all other components

## Display:
Handles updating the main device display

## Display:
Handles updating the main device display

## LightIndicator:
Handles updating the main device lights

## Treatment:
Handles the treatment logic and execution

## EEGHeadset:
Contains all the nodes and communicates with the NeuroDeviceController

## EEGNode:
Handle generating and returning the EEG signals

## Waveform:
Contains the EEG signals and their components

## SessionManager:
Manages the sessions and session logs

## SessionLog:
Contains all past sessions

## Session:
Contains information about the treatment
