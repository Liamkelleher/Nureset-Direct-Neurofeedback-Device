QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Session.cpp \
    display.cpp \
    LightIndicator.cpp \
    eegheadset.cpp \
    eegnode.cpp \
    main.cpp \
    mainwindow.cpp \
    neurodevicecontroller.cpp \
    qcustomplot.cpp \
    sessionlog.cpp \
    sessionmanager.cpp \
    pcdevice.cpp \
    waveform.cpp

HEADERS += \
    LightIndicator.h \
    Session.h \
    defs.h \
    display.h \
    eegheadset.h \
    eegnode.h \
    mainwindow.h \
    neurodevicecontroller.h \
    qcustomplot.h \
    sessionlog.h \
    sessionmanager.h \
    pcdevice.h \
    waveform.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
