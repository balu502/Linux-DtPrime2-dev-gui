/****************************************************************************
** Meta object code from reading C++ file 'protocol_program.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "protocol_program.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocol_program.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Plot_ProgramAmpl_t {
    QByteArrayData data[5];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot_ProgramAmpl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot_ProgramAmpl_t qt_meta_stringdata_Plot_ProgramAmpl = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Plot_ProgramAmpl"
QT_MOC_LITERAL(1, 17, 13), // "clear_Program"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "draw_Program"
QT_MOC_LITERAL(4, 45, 12) // "rt_Protocol*"

    },
    "Plot_ProgramAmpl\0clear_Program\0\0"
    "draw_Program\0rt_Protocol*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot_ProgramAmpl[] = {

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

void Plot_ProgramAmpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plot_ProgramAmpl *_t = static_cast<Plot_ProgramAmpl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clear_Program(); break;
        case 1: _t->draw_Program((*reinterpret_cast< rt_Protocol*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Plot_ProgramAmpl::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_Plot_ProgramAmpl.data,
      qt_meta_data_Plot_ProgramAmpl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Plot_ProgramAmpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot_ProgramAmpl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Plot_ProgramAmpl.stringdata0))
        return static_cast<void*>(const_cast< Plot_ProgramAmpl*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int Plot_ProgramAmpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_Protocol_Program_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Protocol_Program_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Protocol_Program_t qt_meta_stringdata_Protocol_Program = {
    {
QT_MOC_LITERAL(0, 0, 16) // "Protocol_Program"

    },
    "Protocol_Program"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Protocol_Program[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Protocol_Program::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Protocol_Program::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_Protocol_Program.data,
      qt_meta_data_Protocol_Program,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Protocol_Program::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Protocol_Program::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Protocol_Program.stringdata0))
        return static_cast<void*>(const_cast< Protocol_Program*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int Protocol_Program::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
