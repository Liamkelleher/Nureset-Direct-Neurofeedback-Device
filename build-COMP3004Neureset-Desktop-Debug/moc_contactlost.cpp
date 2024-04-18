/****************************************************************************
** Meta object code from reading C++ file 'contactlost.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../COMP3004/FinalProject/COMP3004Neureset/contactlost.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactlost.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ContactLost_t {
    QByteArrayData data[7];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ContactLost_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ContactLost_t qt_meta_stringdata_ContactLost = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ContactLost"
QT_MOC_LITERAL(1, 12, 14), // "sessionExpired"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 22), // "toggleContactLostLight"
QT_MOC_LITERAL(4, 51, 2), // "on"
QT_MOC_LITERAL(5, 54, 14), // "contactWarning"
QT_MOC_LITERAL(6, 69, 13) // "pausedWarning"

    },
    "ContactLost\0sessionExpired\0\0"
    "toggleContactLostLight\0on\0contactWarning\0"
    "pausedWarning"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContactLost[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ContactLost::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContactLost *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sessionExpired(); break;
        case 1: _t->toggleContactLostLight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->contactWarning(); break;
        case 3: _t->pausedWarning(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ContactLost::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ContactLost::sessionExpired)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ContactLost::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ContactLost::toggleContactLostLight)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ContactLost::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ContactLost.data,
    qt_meta_data_ContactLost,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ContactLost::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactLost::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ContactLost.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ContactLost::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ContactLost::sessionExpired()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ContactLost::toggleContactLostLight(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
