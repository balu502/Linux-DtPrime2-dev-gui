/****************************************************************************
** Meta object code from reading C++ file 'protocol_list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "protocol_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocol_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChoiceType_Dialog_t {
    QByteArrayData data[6];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChoiceType_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChoiceType_Dialog_t qt_meta_stringdata_ChoiceType_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ChoiceType_Dialog"
QT_MOC_LITERAL(1, 18, 17), // "sRejimeDevButtons"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 9), // "sKeyPress"
QT_MOC_LITERAL(4, 47, 12), // "close_Choice"
QT_MOC_LITERAL(5, 60, 16) // "QAbstractButton*"

    },
    "ChoiceType_Dialog\0sRejimeDevButtons\0"
    "\0sKeyPress\0close_Choice\0QAbstractButton*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChoiceType_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       3,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void ChoiceType_Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChoiceType_Dialog *_t = static_cast<ChoiceType_Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sRejimeDevButtons((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sKeyPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->close_Choice((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            typedef void (ChoiceType_Dialog::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChoiceType_Dialog::sRejimeDevButtons)) {
                *result = 0;
            }
        }
        {
            typedef void (ChoiceType_Dialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChoiceType_Dialog::sKeyPress)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ChoiceType_Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChoiceType_Dialog.data,
      qt_meta_data_ChoiceType_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChoiceType_Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChoiceType_Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChoiceType_Dialog.stringdata0))
        return static_cast<void*>(const_cast< ChoiceType_Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChoiceType_Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ChoiceType_Dialog::sRejimeDevButtons(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChoiceType_Dialog::sKeyPress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_Protocol_List_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Protocol_List_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Protocol_List_t qt_meta_stringdata_Protocol_List = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Protocol_List"
QT_MOC_LITERAL(1, 14, 9), // "sKeyPress"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "Load_Protocols"
QT_MOC_LITERAL(4, 40, 22), // "QMap<QString,QString>*"
QT_MOC_LITERAL(5, 63, 9), // "use_files"
QT_MOC_LITERAL(6, 73, 18), // "Change_CurrentItem"
QT_MOC_LITERAL(7, 92, 5), // "Apply"
QT_MOC_LITERAL(8, 98, 16), // "Down_CurrentItem"
QT_MOC_LITERAL(9, 115, 14) // "Up_CurrentItem"

    },
    "Protocol_List\0sKeyPress\0\0Load_Protocols\0"
    "QMap<QString,QString>*\0use_files\0"
    "Change_CurrentItem\0Apply\0Down_CurrentItem\0"
    "Up_CurrentItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Protocol_List[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   52,    2, 0x0a /* Public */,
       3,    1,   57,    2, 0x2a /* Public | MethodCloned */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    2,    5,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Protocol_List::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Protocol_List *_t = static_cast<Protocol_List *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sKeyPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Load_Protocols((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->Load_Protocols((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 3: _t->Change_CurrentItem(); break;
        case 4: _t->Apply(); break;
        case 5: _t->Down_CurrentItem(); break;
        case 6: _t->Up_CurrentItem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Protocol_List::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Protocol_List::sKeyPress)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Protocol_List::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Protocol_List.data,
      qt_meta_data_Protocol_List,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Protocol_List::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Protocol_List::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Protocol_List.stringdata0))
        return static_cast<void*>(const_cast< Protocol_List*>(this));
    return QDialog::qt_metacast(_clname);
}

int Protocol_List::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Protocol_List::sKeyPress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
