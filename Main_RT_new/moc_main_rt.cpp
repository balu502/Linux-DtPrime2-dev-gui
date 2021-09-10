/****************************************************************************
** Meta object code from reading C++ file 'main_rt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_rt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_rt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Web_Interface_t {
    QByteArrayData data[16];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Web_Interface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Web_Interface_t qt_meta_stringdata_Web_Interface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Web_Interface"
QT_MOC_LITERAL(1, 14, 18), // "connection_Changed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "listProtocols_Changed"
QT_MOC_LITERAL(4, 56, 18), // "message_FromServer"
QT_MOC_LITERAL(5, 75, 16), // "message_ToServer"
QT_MOC_LITERAL(6, 92, 20), // "send_ProtocolToSetup"
QT_MOC_LITERAL(7, 113, 23), // "send_ProtocolToScenario"
QT_MOC_LITERAL(8, 137, 17), // "change_connection"
QT_MOC_LITERAL(9, 155, 17), // "get_ListProtocols"
QT_MOC_LITERAL(10, 173, 17), // "get_ListCompleted"
QT_MOC_LITERAL(11, 191, 12), // "get_Protocol"
QT_MOC_LITERAL(12, 204, 11), // "get_Message"
QT_MOC_LITERAL(13, 216, 12), // "send_Message"
QT_MOC_LITERAL(14, 229, 17), // "connection_Server"
QT_MOC_LITERAL(15, 247, 10) // "url_Server"

    },
    "Web_Interface\0connection_Changed\0\0"
    "listProtocols_Changed\0message_FromServer\0"
    "message_ToServer\0send_ProtocolToSetup\0"
    "send_ProtocolToScenario\0change_connection\0"
    "get_ListProtocols\0get_ListCompleted\0"
    "get_Protocol\0get_Message\0send_Message\0"
    "connection_Server\0url_Server"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Web_Interface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       2,  112, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,
       4,    1,   78,    2, 0x06 /* Public */,
       5,    1,   81,    2, 0x06 /* Public */,
       6,    1,   84,    2, 0x06 /* Public */,
       7,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   90,    2, 0x0a /* Public */,
       9,    2,   93,    2, 0x0a /* Public */,
      10,    2,   98,    2, 0x0a /* Public */,
      11,    1,  103,    2, 0x0a /* Public */,
      12,    1,  106,    2, 0x0a /* Public */,
      13,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // properties: name, type, flags
      14, QMetaType::Bool, 0x00495003,
      15, QMetaType::QString, 0x00095002,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

void Web_Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Web_Interface *_t = static_cast<Web_Interface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connection_Changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->listProtocols_Changed(); break;
        case 2: _t->message_FromServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->message_ToServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->send_ProtocolToSetup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->send_ProtocolToScenario((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->change_connection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->get_ListProtocols((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->get_ListCompleted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->get_Protocol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->get_Message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->send_Message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Web_Interface::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::connection_Changed)) {
                *result = 0;
            }
        }
        {
            typedef void (Web_Interface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::listProtocols_Changed)) {
                *result = 1;
            }
        }
        {
            typedef void (Web_Interface::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::message_FromServer)) {
                *result = 2;
            }
        }
        {
            typedef void (Web_Interface::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::message_ToServer)) {
                *result = 3;
            }
        }
        {
            typedef void (Web_Interface::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::send_ProtocolToSetup)) {
                *result = 4;
            }
        }
        {
            typedef void (Web_Interface::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::send_ProtocolToScenario)) {
                *result = 5;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Web_Interface *_t = static_cast<Web_Interface *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->get_connection(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Web_Interface *_t = static_cast<Web_Interface *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_connection(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->set_url(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Web_Interface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Web_Interface.data,
      qt_meta_data_Web_Interface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Web_Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Web_Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Web_Interface.stringdata0))
        return static_cast<void*>(const_cast< Web_Interface*>(this));
    return QObject::qt_metacast(_clname);
}

int Web_Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Web_Interface::connection_Changed(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Web_Interface::listProtocols_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Web_Interface::message_FromServer(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Web_Interface::message_ToServer(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Web_Interface::send_ProtocolToSetup(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Web_Interface::send_ProtocolToScenario(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_Exit_Dialog_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Exit_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Exit_Dialog_t qt_meta_stringdata_Exit_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Exit_Dialog"
QT_MOC_LITERAL(1, 12, 10), // "close_Exit"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16) // "QAbstractButton*"

    },
    "Exit_Dialog\0close_Exit\0\0QAbstractButton*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Exit_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void Exit_Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Exit_Dialog *_t = static_cast<Exit_Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->close_Exit((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Exit_Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Exit_Dialog.data,
      qt_meta_data_Exit_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Exit_Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Exit_Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Exit_Dialog.stringdata0))
        return static_cast<void*>(const_cast< Exit_Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Exit_Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Main_RT_t {
    QByteArrayData data[19];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Main_RT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Main_RT_t qt_meta_stringdata_Main_RT = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Main_RT"
QT_MOC_LITERAL(1, 8, 5), // "sExit"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 10), // "sExit_next"
QT_MOC_LITERAL(4, 26, 20), // "finished_WaitProcess"
QT_MOC_LITERAL(5, 47, 7), // "send_IP"
QT_MOC_LITERAL(6, 55, 15), // "update_DateTime"
QT_MOC_LITERAL(7, 71, 15), // "clicked_Buttons"
QT_MOC_LITERAL(8, 87, 16), // "QAbstractButton*"
QT_MOC_LITERAL(9, 104, 20), // "slot_RequestProtocol"
QT_MOC_LITERAL(10, 125, 9), // "slot_Exit"
QT_MOC_LITERAL(11, 135, 14), // "slot_Exit_next"
QT_MOC_LITERAL(12, 150, 15), // "slot_ChangePage"
QT_MOC_LITERAL(13, 166, 22), // "slot_ChangeStateDevice"
QT_MOC_LITERAL(14, 189, 15), // "slot_ChangeLink"
QT_MOC_LITERAL(15, 205, 12), // "wait_process"
QT_MOC_LITERAL(16, 218, 10), // "Wait_state"
QT_MOC_LITERAL(17, 229, 19), // "slot_DisplayProcess"
QT_MOC_LITERAL(18, 249, 26) // "slot_Finishing_WaitProcess"

    },
    "Main_RT\0sExit\0\0sExit_next\0"
    "finished_WaitProcess\0send_IP\0"
    "update_DateTime\0clicked_Buttons\0"
    "QAbstractButton*\0slot_RequestProtocol\0"
    "slot_Exit\0slot_Exit_next\0slot_ChangePage\0"
    "slot_ChangeStateDevice\0slot_ChangeLink\0"
    "wait_process\0Wait_state\0slot_DisplayProcess\0"
    "slot_Finishing_WaitProcess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_RT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    0,   92,    2, 0x06 /* Public */,
       4,    0,   93,    2, 0x06 /* Public */,
       5,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   97,    2, 0x08 /* Private */,
       7,    1,   98,    2, 0x08 /* Private */,
       9,    1,  101,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    1,  106,    2, 0x08 /* Private */,
      13,    1,  109,    2, 0x08 /* Private */,
      14,    1,  112,    2, 0x08 /* Private */,
      15,    3,  115,    2, 0x0a /* Public */,
      17,    2,  122,    2, 0x0a /* Public */,
      18,    0,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,

       0        // eod
};

void Main_RT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Main_RT *_t = static_cast<Main_RT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sExit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sExit_next(); break;
        case 2: _t->finished_WaitProcess(); break;
        case 3: _t->send_IP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->update_DateTime(); break;
        case 5: _t->clicked_Buttons((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 6: _t->slot_RequestProtocol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->slot_Exit(); break;
        case 8: _t->slot_Exit_next(); break;
        case 9: _t->slot_ChangePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slot_ChangeStateDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slot_ChangeLink((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->wait_process((*reinterpret_cast< Wait_state(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 13: _t->slot_DisplayProcess((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->slot_Finishing_WaitProcess(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Main_RT::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_RT::sExit)) {
                *result = 0;
            }
        }
        {
            typedef void (Main_RT::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_RT::sExit_next)) {
                *result = 1;
            }
        }
        {
            typedef void (Main_RT::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_RT::finished_WaitProcess)) {
                *result = 2;
            }
        }
        {
            typedef void (Main_RT::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_RT::send_IP)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Main_RT::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Main_RT.data,
      qt_meta_data_Main_RT,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Main_RT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_RT::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Main_RT.stringdata0))
        return static_cast<void*>(const_cast< Main_RT*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Main_RT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Main_RT::sExit(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Main_RT::sExit_next()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Main_RT::finished_WaitProcess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Main_RT::send_IP(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
