/****************************************************************************
** Meta object code from reading C++ file 'neurodevicecontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../COMP3004Neureset/neurodevicecontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'neurodevicecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NeuroDeviceController_t {
    QByteArrayData data[15];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NeuroDeviceController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NeuroDeviceController_t qt_meta_stringdata_NeuroDeviceController = {
    {
QT_MOC_LITERAL(0, 0, 21), // "NeuroDeviceController"
QT_MOC_LITERAL(1, 22, 13), // "upArrowButton"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "downArrowButton"
QT_MOC_LITERAL(4, 53, 11), // "startButton"
QT_MOC_LITERAL(5, 65, 10), // "stopButton"
QT_MOC_LITERAL(6, 76, 11), // "powerButton"
QT_MOC_LITERAL(7, 88, 8), // "deviceOn"
QT_MOC_LITERAL(8, 97, 10), // "menuButton"
QT_MOC_LITERAL(9, 108, 20), // "upArrowButtonPressed"
QT_MOC_LITERAL(10, 129, 22), // "downArrowButtonPressed"
QT_MOC_LITERAL(11, 152, 18), // "startButtonPressed"
QT_MOC_LITERAL(12, 171, 17), // "stopButtonPressed"
QT_MOC_LITERAL(13, 189, 18), // "powerButtonPressed"
QT_MOC_LITERAL(14, 208, 17) // "menuButtonPressed"

    },
    "NeuroDeviceController\0upArrowButton\0"
    "\0downArrowButton\0startButton\0stopButton\0"
    "powerButton\0deviceOn\0menuButton\0"
    "upArrowButtonPressed\0downArrowButtonPressed\0"
    "startButtonPressed\0stopButtonPressed\0"
    "powerButtonPressed\0menuButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NeuroDeviceController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    1,   78,    2, 0x06 /* Public */,
       8,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NeuroDeviceController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NeuroDeviceController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->upArrowButton(); break;
        case 1: _t->downArrowButton(); break;
        case 2: _t->startButton(); break;
        case 3: _t->stopButton(); break;
        case 4: _t->powerButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->menuButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->upArrowButtonPressed(); break;
        case 7: _t->downArrowButtonPressed(); break;
        case 8: _t->startButtonPressed(); break;
        case 9: _t->stopButtonPressed(); break;
        case 10: _t->powerButtonPressed(); break;
        case 11: _t->menuButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NeuroDeviceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NeuroDeviceController::upArrowButton)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NeuroDeviceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NeuroDeviceController::downArrowButton)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NeuroDeviceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NeuroDeviceController::startButton)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NeuroDeviceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NeuroDeviceController::stopButton)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NeuroDeviceController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NeuroDeviceController::powerButton)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NeuroDeviceController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NeuroDeviceController::menuButton)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NeuroDeviceController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NeuroDeviceController.data,
    qt_meta_data_NeuroDeviceController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NeuroDeviceController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NeuroDeviceController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NeuroDeviceController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NeuroDeviceController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void NeuroDeviceController::upArrowButton()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NeuroDeviceController::downArrowButton()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NeuroDeviceController::startButton()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NeuroDeviceController::stopButton()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void NeuroDeviceController::powerButton(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NeuroDeviceController::menuButton(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
