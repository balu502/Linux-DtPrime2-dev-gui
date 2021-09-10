/****************************************************************************
** Meta object code from reading C++ file 'protocol_info.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "protocol_info.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocol_info.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlateTableWidget_t {
    QByteArrayData data[5];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlateTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlateTableWidget_t qt_meta_stringdata_PlateTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PlateTableWidget"
QT_MOC_LITERAL(1, 17, 11), // "clear_Plate"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "fill_Plate"
QT_MOC_LITERAL(4, 41, 12) // "rt_Protocol*"

    },
    "PlateTableWidget\0clear_Plate\0\0fill_Plate\0"
    "rt_Protocol*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlateTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void PlateTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlateTableWidget *_t = static_cast<PlateTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clear_Plate(); break;
        case 1: _t->fill_Plate((*reinterpret_cast< rt_Protocol*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PlateTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_PlateTableWidget.data,
      qt_meta_data_PlateTableWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlateTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlateTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlateTableWidget.stringdata0))
        return static_cast<void*>(const_cast< PlateTableWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int PlateTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_Protocol_Info_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Protocol_Info_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Protocol_Info_t qt_meta_stringdata_Protocol_Info = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Protocol_Info"
QT_MOC_LITERAL(1, 14, 10), // "clear_Info"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "fill_Info"
QT_MOC_LITERAL(4, 36, 12) // "rt_Protocol*"

    },
    "Protocol_Info\0clear_Info\0\0fill_Info\0"
    "rt_Protocol*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Protocol_Info[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void Protocol_Info::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Protocol_Info *_t = static_cast<Protocol_Info *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clear_Info(); break;
        case 1: _t->fill_Info((*reinterpret_cast< rt_Protocol*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Protocol_Info::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_Protocol_Info.data,
      qt_meta_data_Protocol_Info,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Protocol_Info::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Protocol_Info::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Protocol_Info.stringdata0))
        return static_cast<void*>(const_cast< Protocol_Info*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int Protocol_Info::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
