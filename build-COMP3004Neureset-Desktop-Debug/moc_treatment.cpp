/****************************************************************************
** Meta object code from reading C++ file 'treatment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../COMP3004/FinalProject/COMP3004Neureset/treatment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'treatment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Treatment_t {
    QByteArrayData data[18];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Treatment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Treatment_t qt_meta_stringdata_Treatment = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Treatment"
QT_MOC_LITERAL(1, 10, 18), // "beforeDominantFreq"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 46, 17), // "afterDominantFreq"
QT_MOC_LITERAL(5, 64, 10), // "beforeBase"
QT_MOC_LITERAL(6, 75, 9), // "afterBase"
QT_MOC_LITERAL(7, 85, 6), // "avgAmp"
QT_MOC_LITERAL(8, 92, 12), // "sendFeedback"
QT_MOC_LITERAL(9, 105, 15), // "captureAllWaves"
QT_MOC_LITERAL(10, 121, 11), // "endAnalysis"
QT_MOC_LITERAL(11, 133, 20), // "toggleTreatmentLight"
QT_MOC_LITERAL(12, 154, 2), // "on"
QT_MOC_LITERAL(13, 157, 14), // "applyTreatment"
QT_MOC_LITERAL(14, 172, 11), // "EEGHeadset*"
QT_MOC_LITERAL(15, 184, 5), // "nodes"
QT_MOC_LITERAL(16, 190, 15), // "cancelTreatment"
QT_MOC_LITERAL(17, 206, 15) // "resumeTreatment"

    },
    "Treatment\0beforeDominantFreq\0\0"
    "QVector<double>\0afterDominantFreq\0"
    "beforeBase\0afterBase\0avgAmp\0sendFeedback\0"
    "captureAllWaves\0endAnalysis\0"
    "toggleTreatmentLight\0on\0applyTreatment\0"
    "EEGHeadset*\0nodes\0cancelTreatment\0"
    "resumeTreatment"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Treatment[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    1,   80,    2, 0x06 /* Public */,
       6,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
       8,    0,   89,    2, 0x06 /* Public */,
       9,    0,   90,    2, 0x06 /* Public */,
      10,    0,   91,    2, 0x06 /* Public */,
      11,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   95,    2, 0x0a /* Public */,
      16,    0,   98,    2, 0x0a /* Public */,
      17,    2,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    1,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void Treatment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Treatment *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->beforeDominantFreq((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->afterDominantFreq((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 2: _t->beforeBase((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->afterBase((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->avgAmp((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->sendFeedback(); break;
        case 6: _t->captureAllWaves(); break;
        case 7: _t->endAnalysis(); break;
        case 8: _t->toggleTreatmentLight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->applyTreatment((*reinterpret_cast< EEGHeadset*(*)>(_a[1]))); break;
        case 10: _t->cancelTreatment(); break;
        case 11: _t->resumeTreatment((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EEGHeadset* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Treatment::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::beforeDominantFreq)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Treatment::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::afterDominantFreq)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Treatment::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::beforeBase)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Treatment::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::afterBase)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Treatment::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::avgAmp)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Treatment::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::sendFeedback)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Treatment::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::captureAllWaves)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Treatment::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::endAnalysis)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Treatment::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Treatment::toggleTreatmentLight)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Treatment::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Treatment.data,
    qt_meta_data_Treatment,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Treatment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Treatment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Treatment.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Treatment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Treatment::beforeDominantFreq(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Treatment::afterDominantFreq(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Treatment::beforeBase(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Treatment::afterBase(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Treatment::avgAmp(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Treatment::sendFeedback()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Treatment::captureAllWaves()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Treatment::endAnalysis()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Treatment::toggleTreatmentLight(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
