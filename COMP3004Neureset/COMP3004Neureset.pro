QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    eegnodelist.cpp \
    main.cpp \
    mainwindow.cpp \
    neurodevicecontroller.cpp \
    sessionlog.cpp \
    sessionmanager.cpp \
    pcdevice.cpp

HEADERS += \
    LightIndicator.h \
    Session.h \
    defs.h \
    display.h \
    eegheadset.h \
    eegnode.h \
    eegnodelist.h \
    mainwindow.h \
    neurodevicecontroller.h \
    sessionlog.h \
    sessionmanager.h \
    pcdevice.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
