/****************************************************************************
** Meta object code from reading C++ file 'protocol_samples.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "protocol_samples.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocol_samples.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Protocol_Samples_t {
    QByteArrayData data[6];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Protocol_Samples_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Protocol_Samples_t qt_meta_stringdata_Protocol_Samples = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Protocol_Samples"
QT_MOC_LITERAL(1, 17, 13), // "clear_Samples"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "fill_Samples"
QT_MOC_LITERAL(4, 45, 12), // "rt_Protocol*"
QT_MOC_LITERAL(5, 58, 15) // "change_Expanded"

    },
    "Protocol_Samples\0clear_Samples\0\0"
    "fill_Samples\0rt_Protocol*\0change_Expanded"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Protocol_Samples[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

       0        // eod
};

void Protocol_Samples::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Protocol_Samples *_t = static_cast<Protocol_Samples *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clear_Samples(); break;
        case 1: _t->fill_Samples((*reinterpret_cast< rt_Protocol*(*)>(_a[1]))); break;
        case 2: _t->change_Expanded(); break;
        default: ;
        }
    }
}

const QMetaObject Protocol_Samples::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_Protocol_Samples.data,
      qt_meta_data_Protocol_Samples,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Protocol_Samples::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Protocol_Samples::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Protocol_Samples.stringdata0))
        return static_cast<void*>(const_cast< Protocol_Samples*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int Protocol_Samples::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
