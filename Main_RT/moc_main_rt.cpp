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
    QByteArrayData data[20];
    char stringdata0[330];
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
QT_MOC_LITERAL(8, 137, 18), // "change_SocketState"
QT_MOC_LITERAL(9, 156, 16), // "send_ExecCommand"
QT_MOC_LITERAL(10, 173, 22), // "AnswerRequest_ToServer"
QT_MOC_LITERAL(11, 196, 17), // "change_connection"
QT_MOC_LITERAL(12, 214, 17), // "get_ListProtocols"
QT_MOC_LITERAL(13, 232, 17), // "get_ListCompleted"
QT_MOC_LITERAL(14, 250, 12), // "get_Protocol"
QT_MOC_LITERAL(15, 263, 11), // "get_Message"
QT_MOC_LITERAL(16, 275, 12), // "send_Message"
QT_MOC_LITERAL(17, 288, 12), // "exec_Command"
QT_MOC_LITERAL(18, 301, 17), // "connection_Server"
QT_MOC_LITERAL(19, 319, 10) // "url_Server"

    },
    "Web_Interface\0connection_Changed\0\0"
    "listProtocols_Changed\0message_FromServer\0"
    "message_ToServer\0send_ProtocolToSetup\0"
    "send_ProtocolToScenario\0change_SocketState\0"
    "send_ExecCommand\0AnswerRequest_ToServer\0"
    "change_connection\0get_ListProtocols\0"
    "get_ListCompleted\0get_Protocol\0"
    "get_Message\0send_Message\0exec_Command\0"
    "connection_Server\0url_Server"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Web_Interface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       2,  146, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    0,   97,    2, 0x06 /* Public */,
       4,    1,   98,    2, 0x06 /* Public */,
       5,    1,  101,    2, 0x06 /* Public */,
       6,    2,  104,    2, 0x06 /* Public */,
       7,    1,  109,    2, 0x06 /* Public */,
       8,    1,  112,    2, 0x06 /* Public */,
       9,    1,  115,    2, 0x06 /* Public */,
      10,    1,  118,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  121,    2, 0x0a /* Public */,
      12,    2,  124,    2, 0x0a /* Public */,
      13,    2,  129,    2, 0x0a /* Public */,
      14,    1,  134,    2, 0x0a /* Public */,
      15,    1,  137,    2, 0x0a /* Public */,
      16,    1,  140,    2, 0x0a /* Public */,
      17,    1,  143,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // properties: name, type, flags
      18, QMetaType::Bool, 0x00495003,
      19, QMetaType::QString, 0x00095002,

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
        case 4: _t->send_ProtocolToSetup((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->send_ProtocolToScenario((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->change_SocketState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->send_ExecCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->AnswerRequest_ToServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->change_connection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->get_ListProtocols((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->get_ListCompleted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->get_Protocol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->get_Message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->send_Message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->exec_Command((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
            typedef void (Web_Interface::*_t)(QString , bool );
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
        {
            typedef void (Web_Interface::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::change_SocketState)) {
                *result = 6;
            }
        }
        {
            typedef void (Web_Interface::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::send_ExecCommand)) {
                *result = 7;
            }
        }
        {
            typedef void (Web_Interface::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Web_Interface::AnswerRequest_ToServer)) {
                *result = 8;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
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
void Web_Interface::send_ProtocolToSetup(QString _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Web_Interface::send_ProtocolToScenario(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Web_Interface::change_SocketState(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Web_Interface::send_ExecCommand(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Web_Interface::AnswerRequest_ToServer(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
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
    QByteArrayData data[39];
    char stringdata0[595];
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
QT_MOC_LITERAL(6, 55, 8), // "sStandBy"
QT_MOC_LITERAL(7, 64, 9), // "sShutDown"
QT_MOC_LITERAL(8, 74, 13), // "sProtocolOpen"
QT_MOC_LITERAL(9, 88, 10), // "WebConnect"
QT_MOC_LITERAL(10, 99, 19), // "check_WebConnection"
QT_MOC_LITERAL(11, 119, 15), // "update_DateTime"
QT_MOC_LITERAL(12, 135, 15), // "clicked_Buttons"
QT_MOC_LITERAL(13, 151, 16), // "QAbstractButton*"
QT_MOC_LITERAL(14, 168, 20), // "slot_RequestProtocol"
QT_MOC_LITERAL(15, 189, 9), // "slot_Exit"
QT_MOC_LITERAL(16, 199, 14), // "slot_Exit_next"
QT_MOC_LITERAL(17, 214, 15), // "slot_ChangePage"
QT_MOC_LITERAL(18, 230, 22), // "slot_ChangeStateDevice"
QT_MOC_LITERAL(19, 253, 15), // "slot_ChangeLink"
QT_MOC_LITERAL(20, 269, 19), // "slot_UpdateSoftware"
QT_MOC_LITERAL(21, 289, 22), // "slot_ChangeSocketState"
QT_MOC_LITERAL(22, 312, 12), // "wait_process"
QT_MOC_LITERAL(23, 325, 10), // "Wait_state"
QT_MOC_LITERAL(24, 336, 19), // "slot_DisplayProcess"
QT_MOC_LITERAL(25, 356, 26), // "slot_Finishing_WaitProcess"
QT_MOC_LITERAL(26, 383, 13), // "slot_RunStart"
QT_MOC_LITERAL(27, 397, 12), // "slot_RunStop"
QT_MOC_LITERAL(28, 410, 18), // "slot_AnswerRequest"
QT_MOC_LITERAL(29, 429, 21), // "slot_EnableButtonExit"
QT_MOC_LITERAL(30, 451, 16), // "slot_PrintScreen"
QT_MOC_LITERAL(31, 468, 14), // "slot_AllChilds"
QT_MOC_LITERAL(32, 483, 20), // "slot_TimerDevButtons"
QT_MOC_LITERAL(33, 504, 12), // "slot_StandBy"
QT_MOC_LITERAL(34, 517, 13), // "slot_ShutDown"
QT_MOC_LITERAL(35, 531, 20), // "slot_PressDevButtons"
QT_MOC_LITERAL(36, 552, 21), // "slot_RejimeDevButtons"
QT_MOC_LITERAL(37, 574, 10), // "sub_widget"
QT_MOC_LITERAL(38, 585, 9) // "TempTimer"

    },
    "Main_RT\0sExit\0\0sExit_next\0"
    "finished_WaitProcess\0send_IP\0sStandBy\0"
    "sShutDown\0sProtocolOpen\0WebConnect\0"
    "check_WebConnection\0update_DateTime\0"
    "clicked_Buttons\0QAbstractButton*\0"
    "slot_RequestProtocol\0slot_Exit\0"
    "slot_Exit_next\0slot_ChangePage\0"
    "slot_ChangeStateDevice\0slot_ChangeLink\0"
    "slot_UpdateSoftware\0slot_ChangeSocketState\0"
    "wait_process\0Wait_state\0slot_DisplayProcess\0"
    "slot_Finishing_WaitProcess\0slot_RunStart\0"
    "slot_RunStop\0slot_AnswerRequest\0"
    "slot_EnableButtonExit\0slot_PrintScreen\0"
    "slot_AllChilds\0slot_TimerDevButtons\0"
    "slot_StandBy\0slot_ShutDown\0"
    "slot_PressDevButtons\0slot_RejimeDevButtons\0"
    "sub_widget\0TempTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_RT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  189,    2, 0x06 /* Public */,
       3,    0,  192,    2, 0x06 /* Public */,
       4,    0,  193,    2, 0x06 /* Public */,
       5,    1,  194,    2, 0x06 /* Public */,
       6,    1,  197,    2, 0x06 /* Public */,
       7,    1,  200,    2, 0x06 /* Public */,
       8,    0,  203,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  204,    2, 0x08 /* Private */,
      10,    0,  205,    2, 0x08 /* Private */,
      11,    0,  206,    2, 0x08 /* Private */,
      12,    1,  207,    2, 0x08 /* Private */,
      14,    1,  210,    2, 0x08 /* Private */,
      15,    0,  213,    2, 0x08 /* Private */,
      16,    0,  214,    2, 0x08 /* Private */,
      17,    1,  215,    2, 0x08 /* Private */,
      18,    1,  218,    2, 0x08 /* Private */,
      19,    1,  221,    2, 0x08 /* Private */,
      20,    0,  224,    2, 0x08 /* Private */,
      21,    1,  225,    2, 0x08 /* Private */,
      22,    3,  228,    2, 0x0a /* Public */,
      24,    2,  235,    2, 0x0a /* Public */,
      25,    0,  240,    2, 0x0a /* Public */,
      26,    0,  241,    2, 0x0a /* Public */,
      27,    0,  242,    2, 0x0a /* Public */,
      28,    1,  243,    2, 0x0a /* Public */,
      29,    1,  246,    2, 0x0a /* Public */,
      30,    0,  249,    2, 0x0a /* Public */,
      31,    0,  250,    2, 0x0a /* Public */,
      32,    0,  251,    2, 0x0a /* Public */,
      33,    0,  252,    2, 0x0a /* Public */,
      34,    0,  253,    2, 0x0a /* Public */,
      35,    1,  254,    2, 0x0a /* Public */,
      36,    2,  257,    2, 0x0a /* Public */,
      36,    1,  262,    2, 0x2a /* Public | MethodCloned */,
      38,    0,  265,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 23, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,   37,
    QMetaType::Void, QMetaType::Int,    2,
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
        case 4: _t->sStandBy((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sShutDown((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sProtocolOpen(); break;
        case 7: _t->WebConnect(); break;
        case 8: _t->check_WebConnection(); break;
        case 9: _t->update_DateTime(); break;
        case 10: _t->clicked_Buttons((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 11: _t->slot_RequestProtocol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slot_Exit(); break;
        case 13: _t->slot_Exit_next(); break;
        case 14: _t->slot_ChangePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->slot_ChangeStateDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->slot_ChangeLink((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->slot_UpdateSoftware(); break;
        case 18: _t->slot_ChangeSocketState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->wait_process((*reinterpret_cast< Wait_state(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 20: _t->slot_DisplayProcess((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: _t->slot_Finishing_WaitProcess(); break;
        case 22: _t->slot_RunStart(); break;
        case 23: _t->slot_RunStop(); break;
        case 24: _t->slot_AnswerRequest((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->slot_EnableButtonExit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->slot_PrintScreen(); break;
        case 27: _t->slot_AllChilds(); break;
        case 28: _t->slot_TimerDevButtons(); break;
        case 29: _t->slot_StandBy(); break;
        case 30: _t->slot_ShutDown(); break;
        case 31: _t->slot_PressDevButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->slot_RejimeDevButtons((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: _t->slot_RejimeDevButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->TempTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
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
        {
            typedef void (Main_RT::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_RT::sStandBy)) {
                *result = 4;
            }
        }
        {
            typedef void (Main_RT::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_RT::sShutDown)) {
                *result = 5;
            }
        }
        {
            typedef void (Main_RT::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_RT::sProtocolOpen)) {
                *result = 6;
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
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
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

// SIGNAL 4
void Main_RT::sStandBy(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Main_RT::sShutDown(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Main_RT::sProtocolOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
