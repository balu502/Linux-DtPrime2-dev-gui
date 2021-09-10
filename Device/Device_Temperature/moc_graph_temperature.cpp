/****************************************************************************
** Meta object code from reading C++ file 'graph_temperature.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graph_temperature.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph_temperature.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphTemperaturePlot_t {
    QByteArrayData data[9];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphTemperaturePlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphTemperaturePlot_t qt_meta_stringdata_GraphTemperaturePlot = {
    {
QT_MOC_LITERAL(0, 0, 20), // "GraphTemperaturePlot"
QT_MOC_LITERAL(1, 21, 15), // "slotRefreshData"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 22), // "QMap<QString,QString>*"
QT_MOC_LITERAL(4, 61, 9), // "clearPlot"
QT_MOC_LITERAL(5, 71, 17), // "slot_ChangeRejime"
QT_MOC_LITERAL(6, 89, 18), // "slot_WarningRejime"
QT_MOC_LITERAL(7, 108, 20), // "slot_MeasuringRejime"
QT_MOC_LITERAL(8, 129, 10) // "set_Enable"

    },
    "GraphTemperaturePlot\0slotRefreshData\0"
    "\0QMap<QString,QString>*\0clearPlot\0"
    "slot_ChangeRejime\0slot_WarningRejime\0"
    "slot_MeasuringRejime\0set_Enable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphTemperaturePlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       6,    0,   51,    2, 0x0a /* Public */,
       7,    0,   52,    2, 0x0a /* Public */,
       8,    1,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void GraphTemperaturePlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphTemperaturePlot *_t = static_cast<GraphTemperaturePlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRefreshData((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 1: _t->clearPlot(); break;
        case 2: _t->slot_ChangeRejime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_WarningRejime(); break;
        case 4: _t->slot_MeasuringRejime(); break;
        case 5: _t->set_Enable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GraphTemperaturePlot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_GraphTemperaturePlot.data,
      qt_meta_data_GraphTemperaturePlot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphTemperaturePlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphTemperaturePlot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphTemperaturePlot.stringdata0))
        return static_cast<void*>(const_cast< GraphTemperaturePlot*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int GraphTemperaturePlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
