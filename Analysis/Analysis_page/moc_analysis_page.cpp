/****************************************************************************
** Meta object code from reading C++ file 'analysis_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "analysis_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysis_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Analysis_page_t {
    QByteArrayData data[20];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Analysis_page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Analysis_page_t qt_meta_stringdata_Analysis_page = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Analysis_page"
QT_MOC_LITERAL(1, 14, 13), // "sWait_Process"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "Wait_state"
QT_MOC_LITERAL(4, 40, 21), // "sFinished_WaitProcess"
QT_MOC_LITERAL(5, 62, 17), // "sRejimeDevButtons"
QT_MOC_LITERAL(6, 80, 9), // "sKeyPress"
QT_MOC_LITERAL(7, 90, 13), // "open_Manually"
QT_MOC_LITERAL(8, 104, 13), // "open_Protocol"
QT_MOC_LITERAL(9, 118, 2), // "fn"
QT_MOC_LITERAL(10, 121, 22), // "open_ProtocolCompleted"
QT_MOC_LITERAL(11, 144, 7), // "id_prot"
QT_MOC_LITERAL(12, 152, 16), // "open_USBProtocol"
QT_MOC_LITERAL(13, 169, 13), // "save_Manually"
QT_MOC_LITERAL(14, 183, 13), // "save_Protocol"
QT_MOC_LITERAL(15, 197, 16), // "save_USBProtocol"
QT_MOC_LITERAL(16, 214, 12), // "load_fromXML"
QT_MOC_LITERAL(17, 227, 14), // "clear_Protocol"
QT_MOC_LITERAL(18, 242, 19), // "check_SaveProcedure"
QT_MOC_LITERAL(19, 262, 13) // "slot_KeyPress"

    },
    "Analysis_page\0sWait_Process\0\0Wait_state\0"
    "sFinished_WaitProcess\0sRejimeDevButtons\0"
    "sKeyPress\0open_Manually\0open_Protocol\0"
    "fn\0open_ProtocolCompleted\0id_prot\0"
    "open_USBProtocol\0save_Manually\0"
    "save_Protocol\0save_USBProtocol\0"
    "load_fromXML\0clear_Protocol\0"
    "check_SaveProcedure\0slot_KeyPress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Analysis_page[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   99,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    2,  107,    2, 0x06 /* Public */,
       6,    1,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  115,    2, 0x0a /* Public */,
       8,    1,  116,    2, 0x0a /* Public */,
       8,    0,  119,    2, 0x2a /* Public | MethodCloned */,
      10,    1,  120,    2, 0x0a /* Public */,
      10,    0,  123,    2, 0x2a /* Public | MethodCloned */,
      12,    0,  124,    2, 0x0a /* Public */,
      13,    0,  125,    2, 0x0a /* Public */,
      14,    0,  126,    2, 0x0a /* Public */,
      15,    0,  127,    2, 0x0a /* Public */,
      16,    1,  128,    2, 0x0a /* Public */,
      17,    0,  131,    2, 0x0a /* Public */,
      18,    0,  132,    2, 0x0a /* Public */,
      19,    1,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Analysis_page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Analysis_page *_t = static_cast<Analysis_page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sWait_Process((*reinterpret_cast< Wait_state(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->sFinished_WaitProcess(); break;
        case 2: _t->sRejimeDevButtons((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sKeyPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->open_Manually(); break;
        case 5: _t->open_Protocol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->open_Protocol(); break;
        case 7: _t->open_ProtocolCompleted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->open_ProtocolCompleted(); break;
        case 9: _t->open_USBProtocol(); break;
        case 10: _t->save_Manually(); break;
        case 11: _t->save_Protocol(); break;
        case 12: _t->save_USBProtocol(); break;
        case 13: { bool _r = _t->load_fromXML((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: _t->clear_Protocol(); break;
        case 15: _t->check_SaveProcedure(); break;
        case 16: _t->slot_KeyPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Analysis_page::*_t)(Wait_state , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Analysis_page::sWait_Process)) {
                *result = 0;
            }
        }
        {
            typedef void (Analysis_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Analysis_page::sFinished_WaitProcess)) {
                *result = 1;
            }
        }
        {
            typedef void (Analysis_page::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Analysis_page::sRejimeDevButtons)) {
                *result = 2;
            }
        }
        {
            typedef void (Analysis_page::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Analysis_page::sKeyPress)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Analysis_page::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Analysis_page.data,
      qt_meta_data_Analysis_page,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Analysis_page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analysis_page::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Analysis_page.stringdata0))
        return static_cast<void*>(const_cast< Analysis_page*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Analysis_page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Analysis_page::sWait_Process(Wait_state _t1, int _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Analysis_page::sFinished_WaitProcess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Analysis_page::sRejimeDevButtons(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Analysis_page::sKeyPress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
