/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../COMP3004/FinalProject/COMP3004Neureset/display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Display_t {
    QByteArrayData data[13];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Display_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Display_t qt_meta_stringdata_Display = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Display"
QT_MOC_LITERAL(1, 8, 13), // "uploadSession"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "updateDateTime"
QT_MOC_LITERAL(4, 38, 13), // "upArrowButton"
QT_MOC_LITERAL(5, 52, 15), // "downArrowButton"
QT_MOC_LITERAL(6, 68, 11), // "startButton"
QT_MOC_LITERAL(7, 80, 10), // "connection"
QT_MOC_LITERAL(8, 91, 10), // "stopButton"
QT_MOC_LITERAL(9, 102, 14), // "powerOnDisplay"
QT_MOC_LITERAL(10, 117, 15), // "powerOffDisplay"
QT_MOC_LITERAL(11, 133, 10), // "menuButton"
QT_MOC_LITERAL(12, 144, 15) // "sessionComplete"

    },
    "Display\0uploadSession\0\0updateDateTime\0"
    "upArrowButton\0downArrowButton\0startButton\0"
    "connection\0stopButton\0powerOnDisplay\0"
    "powerOffDisplay\0menuButton\0sessionComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Display[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   70,    2, 0x0a /* Public */,
       5,    0,   71,    2, 0x0a /* Public */,
       6,    1,   72,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QDateTime,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Display *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->uploadSession((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateDateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 2: _t->upArrowButton(); break;
        case 3: _t->downArrowButton(); break;
        case 4: _t->startButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->stopButton(); break;
        case 6: _t->powerOnDisplay(); break;
        case 7: _t->powerOffDisplay(); break;
        case 8: _t->menuButton(); break;
        case 9: _t->sessionComplete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Display::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Display::uploadSession)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Display::*)(QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Display::updateDateTime)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Display::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Display.data,
    qt_meta_data_Display,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Display::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Display.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Display::uploadSession(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Display::updateDateTime(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
