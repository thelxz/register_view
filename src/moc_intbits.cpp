/****************************************************************************
** Meta object code from reading C++ file 'intbits.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "intbits.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'intbits.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Intbits_t {
    QByteArrayData data[5];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Intbits_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Intbits_t qt_meta_stringdata_Intbits = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Intbits"
QT_MOC_LITERAL(1, 8, 13), // "value_changed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "changed_num"
QT_MOC_LITERAL(4, 35, 14) // "click_bits_btn"

    },
    "Intbits\0value_changed\0\0changed_num\0"
    "click_bits_btn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Intbits[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::ULongLong,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Intbits::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Intbits *_t = static_cast<Intbits *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->value_changed((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 1: _t->click_bits_btn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Intbits::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Intbits::value_changed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Intbits::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Intbits.data,
      qt_meta_data_Intbits,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Intbits::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Intbits::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Intbits.stringdata0))
        return static_cast<void*>(const_cast< Intbits*>(this));
    return QWidget::qt_metacast(_clname);
}

int Intbits::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Intbits::value_changed(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
