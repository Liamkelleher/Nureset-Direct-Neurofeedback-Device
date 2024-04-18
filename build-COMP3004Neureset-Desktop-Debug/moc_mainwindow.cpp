/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../COMP3004/FinalProject/COMP3004Neureset/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[30];
    char stringdata0[601];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "upArrowButtonPressed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 22), // "downArrowButtonPressed"
QT_MOC_LITERAL(4, 56, 18), // "startButtonPressed"
QT_MOC_LITERAL(5, 75, 17), // "stopButtonPressed"
QT_MOC_LITERAL(6, 93, 18), // "powerButtonPressed"
QT_MOC_LITERAL(7, 112, 17), // "menuButtonPressed"
QT_MOC_LITERAL(8, 130, 18), // "pauseButtonPressed"
QT_MOC_LITERAL(9, 149, 18), // "nodeDisplayChanged"
QT_MOC_LITERAL(10, 168, 5), // "index"
QT_MOC_LITERAL(11, 174, 19), // "terminateConnection"
QT_MOC_LITERAL(12, 194, 19), // "establishConnection"
QT_MOC_LITERAL(13, 214, 24), // "on_upArrowButton_clicked"
QT_MOC_LITERAL(14, 239, 26), // "on_downArrowButton_clicked"
QT_MOC_LITERAL(15, 266, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(16, 289, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(17, 311, 22), // "on_powerButton_clicked"
QT_MOC_LITERAL(18, 334, 21), // "on_menuButton_clicked"
QT_MOC_LITERAL(19, 356, 27), // "on_batteryUseButton_clicked"
QT_MOC_LITERAL(20, 384, 28), // "on_batteryFullButton_clicked"
QT_MOC_LITERAL(21, 413, 13), // "uploadSession"
QT_MOC_LITERAL(22, 427, 8), // "Session*"
QT_MOC_LITERAL(23, 436, 22), // "on_pauseButton_pressed"
QT_MOC_LITERAL(24, 459, 11), // "updateGraph"
QT_MOC_LITERAL(25, 471, 8), // "EEGNode*"
QT_MOC_LITERAL(26, 480, 35), // "on_nodeDropDown_currentIndexC..."
QT_MOC_LITERAL(27, 516, 30), // "on_terminateConnection_clicked"
QT_MOC_LITERAL(28, 547, 30), // "on_establishConnection_clicked"
QT_MOC_LITERAL(29, 578, 22) // "on_pcClearData_clicked"

    },
    "MainWindow\0upArrowButtonPressed\0\0"
    "downArrowButtonPressed\0startButtonPressed\0"
    "stopButtonPressed\0powerButtonPressed\0"
    "menuButtonPressed\0pauseButtonPressed\0"
    "nodeDisplayChanged\0index\0terminateConnection\0"
    "establishConnection\0on_upArrowButton_clicked\0"
    "on_downArrowButton_clicked\0"
    "on_startButton_clicked\0on_stopButton_clicked\0"
    "on_powerButton_clicked\0on_menuButton_clicked\0"
    "on_batteryUseButton_clicked\0"
    "on_batteryFullButton_clicked\0uploadSession\0"
    "Session*\0on_pauseButton_pressed\0"
    "updateGraph\0EEGNode*\0"
    "on_nodeDropDown_currentIndexChanged\0"
    "on_terminateConnection_clicked\0"
    "on_establishConnection_clicked\0"
    "on_pcClearData_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  139,    2, 0x06 /* Public */,
       3,    0,  140,    2, 0x06 /* Public */,
       4,    0,  141,    2, 0x06 /* Public */,
       5,    0,  142,    2, 0x06 /* Public */,
       6,    0,  143,    2, 0x06 /* Public */,
       7,    0,  144,    2, 0x06 /* Public */,
       8,    0,  145,    2, 0x06 /* Public */,
       9,    1,  146,    2, 0x06 /* Public */,
      11,    0,  149,    2, 0x06 /* Public */,
      12,    0,  150,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  151,    2, 0x08 /* Private */,
      14,    0,  152,    2, 0x08 /* Private */,
      15,    0,  153,    2, 0x08 /* Private */,
      16,    0,  154,    2, 0x08 /* Private */,
      17,    0,  155,    2, 0x08 /* Private */,
      18,    0,  156,    2, 0x08 /* Private */,
      19,    0,  157,    2, 0x08 /* Private */,
      20,    0,  158,    2, 0x08 /* Private */,
      21,    1,  159,    2, 0x08 /* Private */,
      23,    0,  162,    2, 0x08 /* Private */,
      24,    1,  163,    2, 0x08 /* Private */,
      26,    1,  166,    2, 0x08 /* Private */,
      27,    0,  169,    2, 0x08 /* Private */,
      28,    0,  170,    2, 0x08 /* Private */,
      29,    0,  171,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,    2,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->upArrowButtonPressed(); break;
        case 1: _t->downArrowButtonPressed(); break;
        case 2: _t->startButtonPressed(); break;
        case 3: _t->stopButtonPressed(); break;
        case 4: _t->powerButtonPressed(); break;
        case 5: _t->menuButtonPressed(); break;
        case 6: _t->pauseButtonPressed(); break;
        case 7: _t->nodeDisplayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->terminateConnection(); break;
        case 9: _t->establishConnection(); break;
        case 10: _t->on_upArrowButton_clicked(); break;
        case 11: _t->on_downArrowButton_clicked(); break;
        case 12: _t->on_startButton_clicked(); break;
        case 13: _t->on_stopButton_clicked(); break;
        case 14: _t->on_powerButton_clicked(); break;
        case 15: _t->on_menuButton_clicked(); break;
        case 16: _t->on_batteryUseButton_clicked(); break;
        case 17: _t->on_batteryFullButton_clicked(); break;
        case 18: _t->uploadSession((*reinterpret_cast< Session*(*)>(_a[1]))); break;
        case 19: _t->on_pauseButton_pressed(); break;
        case 20: _t->updateGraph((*reinterpret_cast< EEGNode*(*)>(_a[1]))); break;
        case 21: _t->on_nodeDropDown_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_terminateConnection_clicked(); break;
        case 23: _t->on_establishConnection_clicked(); break;
        case 24: _t->on_pcClearData_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EEGNode* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::upArrowButtonPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::downArrowButtonPressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startButtonPressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::stopButtonPressed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::powerButtonPressed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::menuButtonPressed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::pauseButtonPressed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::nodeDisplayChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::terminateConnection)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::establishConnection)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::upArrowButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::downArrowButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::startButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::stopButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::powerButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::menuButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::pauseButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::nodeDisplayChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::terminateConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MainWindow::establishConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
