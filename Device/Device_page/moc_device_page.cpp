/****************************************************************************
** Meta object code from reading C++ file 'device_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "device_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Device_page_t {
    QByteArrayData data[65];
    char stringdata0[1083];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Device_page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Device_page_t qt_meta_stringdata_Device_page = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Device_page"
QT_MOC_LITERAL(1, 12, 8), // "sRefresh"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 22), // "QMap<QString,QString>*"
QT_MOC_LITERAL(4, 45, 13), // "sRefreshFluor"
QT_MOC_LITERAL(5, 59, 18), // "sRefreshInfoDevice"
QT_MOC_LITERAL(6, 78, 14), // "sDeviceRequest"
QT_MOC_LITERAL(7, 93, 16), // "sRequestProtocol"
QT_MOC_LITERAL(8, 110, 18), // "sRequestCloseBlock"
QT_MOC_LITERAL(9, 129, 11), // "sChangePage"
QT_MOC_LITERAL(10, 141, 18), // "sChangeStateDevice"
QT_MOC_LITERAL(11, 160, 12), // "sNewProtocol"
QT_MOC_LITERAL(12, 173, 12), // "rt_Protocol*"
QT_MOC_LITERAL(13, 186, 21), // "sOpenProtocolAfterRun"
QT_MOC_LITERAL(14, 208, 21), // "sSaveProtocolToServer"
QT_MOC_LITERAL(15, 230, 10), // "sRun_Start"
QT_MOC_LITERAL(16, 241, 9), // "sRun_Stop"
QT_MOC_LITERAL(17, 251, 13), // "sPause_rejime"
QT_MOC_LITERAL(18, 265, 12), // "sRun_Process"
QT_MOC_LITERAL(19, 278, 11), // "sRun_rejime"
QT_MOC_LITERAL(20, 290, 13), // "sWait_Process"
QT_MOC_LITERAL(21, 304, 10), // "Wait_state"
QT_MOC_LITERAL(22, 315, 21), // "sFinished_WaitProcess"
QT_MOC_LITERAL(23, 337, 17), // "sMeasureTubeHeiht"
QT_MOC_LITERAL(24, 355, 12), // "sSendPicture"
QT_MOC_LITERAL(25, 368, 25), // "QMap<QString,QByteArray>*"
QT_MOC_LITERAL(26, 394, 12), // "sSendLogData"
QT_MOC_LITERAL(27, 407, 18), // "sLoad_USB_Protocol"
QT_MOC_LITERAL(28, 426, 21), // "sLoad_LastRunProtocol"
QT_MOC_LITERAL(29, 448, 9), // "sShutDown"
QT_MOC_LITERAL(30, 458, 17), // "sRejimeDevButtons"
QT_MOC_LITERAL(31, 476, 13), // "slotConnected"
QT_MOC_LITERAL(32, 490, 13), // "slotReadyRead"
QT_MOC_LITERAL(33, 504, 16), // "slotSendToServer"
QT_MOC_LITERAL(34, 521, 9), // "slotError"
QT_MOC_LITERAL(35, 531, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(36, 560, 14), // "slot_OpenBlock"
QT_MOC_LITERAL(37, 575, 15), // "slot_CloseBlock"
QT_MOC_LITERAL(38, 591, 30), // "slot_CheckExpozition_BeforeRun"
QT_MOC_LITERAL(39, 622, 8), // "slot_Run"
QT_MOC_LITERAL(40, 631, 9), // "slot_Stop"
QT_MOC_LITERAL(41, 641, 10), // "slot_Pause"
QT_MOC_LITERAL(42, 652, 12), // "slot_LastRun"
QT_MOC_LITERAL(43, 665, 19), // "slotSendRequestInfo"
QT_MOC_LITERAL(44, 685, 17), // "slotGetInfoDevice"
QT_MOC_LITERAL(45, 703, 18), // "slot_MeasureHeight"
QT_MOC_LITERAL(46, 722, 22), // "slot_MeasuredTubeHeiht"
QT_MOC_LITERAL(47, 745, 15), // "slot_GetPicture"
QT_MOC_LITERAL(48, 761, 18), // "slot_DeviceRequest"
QT_MOC_LITERAL(49, 780, 22), // "slot_RequestCloseBlock"
QT_MOC_LITERAL(50, 803, 16), // "slot_RequestExit"
QT_MOC_LITERAL(51, 820, 19), // "slot_RefreshMeasure"
QT_MOC_LITERAL(52, 840, 22), // "slot_RefreshInfoDevice"
QT_MOC_LITERAL(53, 863, 15), // "slot_GetMeasure"
QT_MOC_LITERAL(54, 879, 22), // "slot_ChangeStateDevice"
QT_MOC_LITERAL(55, 902, 13), // "slot_SaveExpo"
QT_MOC_LITERAL(56, 916, 26), // "slot_Processing_ReadSector"
QT_MOC_LITERAL(57, 943, 22), // "QMap<QString,QString>&"
QT_MOC_LITERAL(58, 966, 18), // "slot_Exec_Commaand"
QT_MOC_LITERAL(59, 985, 19), // "slot_StatusProtocol"
QT_MOC_LITERAL(60, 1005, 15), // "slot_ChangeLink"
QT_MOC_LITERAL(61, 1021, 12), // "slot_InfoUSB"
QT_MOC_LITERAL(62, 1034, 16), // "change_FirstTime"
QT_MOC_LITERAL(63, 1051, 17), // "change_SecondTime"
QT_MOC_LITERAL(64, 1069, 13) // "again_connect"

    },
    "Device_page\0sRefresh\0\0QMap<QString,QString>*\0"
    "sRefreshFluor\0sRefreshInfoDevice\0"
    "sDeviceRequest\0sRequestProtocol\0"
    "sRequestCloseBlock\0sChangePage\0"
    "sChangeStateDevice\0sNewProtocol\0"
    "rt_Protocol*\0sOpenProtocolAfterRun\0"
    "sSaveProtocolToServer\0sRun_Start\0"
    "sRun_Stop\0sPause_rejime\0sRun_Process\0"
    "sRun_rejime\0sWait_Process\0Wait_state\0"
    "sFinished_WaitProcess\0sMeasureTubeHeiht\0"
    "sSendPicture\0QMap<QString,QByteArray>*\0"
    "sSendLogData\0sLoad_USB_Protocol\0"
    "sLoad_LastRunProtocol\0sShutDown\0"
    "sRejimeDevButtons\0slotConnected\0"
    "slotReadyRead\0slotSendToServer\0slotError\0"
    "QAbstractSocket::SocketError\0"
    "slot_OpenBlock\0slot_CloseBlock\0"
    "slot_CheckExpozition_BeforeRun\0slot_Run\0"
    "slot_Stop\0slot_Pause\0slot_LastRun\0"
    "slotSendRequestInfo\0slotGetInfoDevice\0"
    "slot_MeasureHeight\0slot_MeasuredTubeHeiht\0"
    "slot_GetPicture\0slot_DeviceRequest\0"
    "slot_RequestCloseBlock\0slot_RequestExit\0"
    "slot_RefreshMeasure\0slot_RefreshInfoDevice\0"
    "slot_GetMeasure\0slot_ChangeStateDevice\0"
    "slot_SaveExpo\0slot_Processing_ReadSector\0"
    "QMap<QString,QString>&\0slot_Exec_Commaand\0"
    "slot_StatusProtocol\0slot_ChangeLink\0"
    "slot_InfoUSB\0change_FirstTime\0"
    "change_SecondTime\0again_connect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Device_page[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      25,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  299,    2, 0x06 /* Public */,
       4,    0,  302,    2, 0x06 /* Public */,
       5,    0,  303,    2, 0x06 /* Public */,
       6,    1,  304,    2, 0x06 /* Public */,
       7,    1,  307,    2, 0x06 /* Public */,
       8,    1,  310,    2, 0x06 /* Public */,
       9,    1,  313,    2, 0x06 /* Public */,
      10,    1,  316,    2, 0x06 /* Public */,
      11,    1,  319,    2, 0x06 /* Public */,
      13,    1,  322,    2, 0x06 /* Public */,
      14,    0,  325,    2, 0x06 /* Public */,
      15,    0,  326,    2, 0x06 /* Public */,
      16,    0,  327,    2, 0x06 /* Public */,
      17,    1,  328,    2, 0x06 /* Public */,
      18,    2,  331,    2, 0x06 /* Public */,
      19,    1,  336,    2, 0x06 /* Public */,
      20,    3,  339,    2, 0x06 /* Public */,
      22,    0,  346,    2, 0x06 /* Public */,
      23,    1,  347,    2, 0x06 /* Public */,
      24,    1,  350,    2, 0x06 /* Public */,
      26,    1,  353,    2, 0x06 /* Public */,
      27,    0,  356,    2, 0x06 /* Public */,
      28,    0,  357,    2, 0x06 /* Public */,
      29,    0,  358,    2, 0x06 /* Public */,
      30,    2,  359,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      31,    0,  364,    2, 0x0a /* Public */,
      32,    0,  365,    2, 0x0a /* Public */,
      33,    1,  366,    2, 0x0a /* Public */,
      34,    1,  369,    2, 0x0a /* Public */,
      36,    0,  372,    2, 0x0a /* Public */,
      37,    0,  373,    2, 0x0a /* Public */,
      38,    0,  374,    2, 0x0a /* Public */,
      39,    0,  375,    2, 0x0a /* Public */,
      40,    0,  376,    2, 0x0a /* Public */,
      41,    0,  377,    2, 0x0a /* Public */,
      42,    0,  378,    2, 0x0a /* Public */,
      43,    0,  379,    2, 0x0a /* Public */,
      44,    0,  380,    2, 0x0a /* Public */,
      45,    0,  381,    2, 0x0a /* Public */,
      46,    1,  382,    2, 0x0a /* Public */,
      47,    3,  385,    2, 0x0a /* Public */,
      48,    1,  392,    2, 0x0a /* Public */,
      49,    1,  395,    2, 0x0a /* Public */,
      50,    1,  398,    2, 0x0a /* Public */,
      51,    1,  401,    2, 0x0a /* Public */,
      52,    1,  404,    2, 0x0a /* Public */,
      53,    1,  407,    2, 0x0a /* Public */,
      54,    1,  410,    2, 0x0a /* Public */,
      55,    2,  413,    2, 0x0a /* Public */,
      56,    1,  418,    2, 0x0a /* Public */,
      58,    1,  421,    2, 0x0a /* Public */,
      59,    1,  424,    2, 0x0a /* Public */,
      60,    1,  427,    2, 0x0a /* Public */,
      61,    1,  430,    2, 0x0a /* Public */,
      62,    1,  433,    2, 0x0a /* Public */,
      63,    1,  436,    2, 0x0a /* Public */,
      64,    0,  439,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 25,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 35,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Bool, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 57,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void Device_page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Device_page *_t = static_cast<Device_page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sRefresh((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 1: _t->sRefreshFluor(); break;
        case 2: _t->sRefreshInfoDevice(); break;
        case 3: _t->sDeviceRequest((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 4: _t->sRequestProtocol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sRequestCloseBlock((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 6: _t->sChangePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sChangeStateDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sNewProtocol((*reinterpret_cast< rt_Protocol*(*)>(_a[1]))); break;
        case 9: _t->sOpenProtocolAfterRun((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->sSaveProtocolToServer(); break;
        case 11: _t->sRun_Start(); break;
        case 12: _t->sRun_Stop(); break;
        case 13: _t->sPause_rejime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->sRun_Process((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->sRun_rejime((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->sWait_Process((*reinterpret_cast< Wait_state(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 17: _t->sFinished_WaitProcess(); break;
        case 18: _t->sMeasureTubeHeiht((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->sSendPicture((*reinterpret_cast< QMap<QString,QByteArray>*(*)>(_a[1]))); break;
        case 20: _t->sSendLogData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->sLoad_USB_Protocol(); break;
        case 22: _t->sLoad_LastRunProtocol(); break;
        case 23: _t->sShutDown(); break;
        case 24: _t->sRejimeDevButtons((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->slotConnected(); break;
        case 26: _t->slotReadyRead(); break;
        case 27: _t->slotSendToServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 29: _t->slot_OpenBlock(); break;
        case 30: _t->slot_CloseBlock(); break;
        case 31: _t->slot_CheckExpozition_BeforeRun(); break;
        case 32: _t->slot_Run(); break;
        case 33: _t->slot_Stop(); break;
        case 34: _t->slot_Pause(); break;
        case 35: _t->slot_LastRun(); break;
        case 36: _t->slotSendRequestInfo(); break;
        case 37: _t->slotGetInfoDevice(); break;
        case 38: _t->slot_MeasureHeight(); break;
        case 39: _t->slot_MeasuredTubeHeiht((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->slot_GetPicture((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 41: _t->slot_DeviceRequest((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 42: _t->slot_RequestCloseBlock((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 43: _t->slot_RequestExit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->slot_RefreshMeasure((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 45: _t->slot_RefreshInfoDevice((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 46: { bool _r = _t->slot_GetMeasure((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 47: _t->slot_ChangeStateDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->slot_SaveExpo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 49: _t->slot_Processing_ReadSector((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 50: _t->slot_Exec_Commaand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 51: _t->slot_StatusProtocol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 52: _t->slot_ChangeLink((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->slot_InfoUSB((*reinterpret_cast< QMap<QString,QString>*(*)>(_a[1]))); break;
        case 54: _t->change_FirstTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->change_SecondTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->again_connect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Device_page::*_t)(QMap<QString,QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRefresh)) {
                *result = 0;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRefreshFluor)) {
                *result = 1;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRefreshInfoDevice)) {
                *result = 2;
            }
        }
        {
            typedef void (Device_page::*_t)(QMap<QString,QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sDeviceRequest)) {
                *result = 3;
            }
        }
        {
            typedef void (Device_page::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRequestProtocol)) {
                *result = 4;
            }
        }
        {
            typedef void (Device_page::*_t)(QMap<QString,QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRequestCloseBlock)) {
                *result = 5;
            }
        }
        {
            typedef void (Device_page::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sChangePage)) {
                *result = 6;
            }
        }
        {
            typedef void (Device_page::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sChangeStateDevice)) {
                *result = 7;
            }
        }
        {
            typedef void (Device_page::*_t)(rt_Protocol * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sNewProtocol)) {
                *result = 8;
            }
        }
        {
            typedef void (Device_page::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sOpenProtocolAfterRun)) {
                *result = 9;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sSaveProtocolToServer)) {
                *result = 10;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRun_Start)) {
                *result = 11;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRun_Stop)) {
                *result = 12;
            }
        }
        {
            typedef void (Device_page::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sPause_rejime)) {
                *result = 13;
            }
        }
        {
            typedef void (Device_page::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRun_Process)) {
                *result = 14;
            }
        }
        {
            typedef void (Device_page::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRun_rejime)) {
                *result = 15;
            }
        }
        {
            typedef void (Device_page::*_t)(Wait_state , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sWait_Process)) {
                *result = 16;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sFinished_WaitProcess)) {
                *result = 17;
            }
        }
        {
            typedef void (Device_page::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sMeasureTubeHeiht)) {
                *result = 18;
            }
        }
        {
            typedef void (Device_page::*_t)(QMap<QString,QByteArray> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sSendPicture)) {
                *result = 19;
            }
        }
        {
            typedef void (Device_page::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sSendLogData)) {
                *result = 20;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sLoad_USB_Protocol)) {
                *result = 21;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sLoad_LastRunProtocol)) {
                *result = 22;
            }
        }
        {
            typedef void (Device_page::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sShutDown)) {
                *result = 23;
            }
        }
        {
            typedef void (Device_page::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device_page::sRejimeDevButtons)) {
                *result = 24;
            }
        }
    }
}

const QMetaObject Device_page::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Device_page.data,
      qt_meta_data_Device_page,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Device_page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Device_page::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Device_page.stringdata0))
        return static_cast<void*>(const_cast< Device_page*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Device_page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    }
    return _id;
}

// SIGNAL 0
void Device_page::sRefresh(QMap<QString,QString> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Device_page::sRefreshFluor()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Device_page::sRefreshInfoDevice()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Device_page::sDeviceRequest(QMap<QString,QString> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Device_page::sRequestProtocol(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Device_page::sRequestCloseBlock(QMap<QString,QString> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Device_page::sChangePage(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Device_page::sChangeStateDevice(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Device_page::sNewProtocol(rt_Protocol * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Device_page::sOpenProtocolAfterRun(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Device_page::sSaveProtocolToServer()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void Device_page::sRun_Start()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void Device_page::sRun_Stop()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void Device_page::sPause_rejime(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Device_page::sRun_Process(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Device_page::sRun_rejime(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Device_page::sWait_Process(Wait_state _t1, int _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Device_page::sFinished_WaitProcess()
{
    QMetaObject::activate(this, &staticMetaObject, 17, Q_NULLPTR);
}

// SIGNAL 18
void Device_page::sMeasureTubeHeiht(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Device_page::sSendPicture(QMap<QString,QByteArray> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Device_page::sSendLogData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Device_page::sLoad_USB_Protocol()
{
    QMetaObject::activate(this, &staticMetaObject, 21, Q_NULLPTR);
}

// SIGNAL 22
void Device_page::sLoad_LastRunProtocol()
{
    QMetaObject::activate(this, &staticMetaObject, 22, Q_NULLPTR);
}

// SIGNAL 23
void Device_page::sShutDown()
{
    QMetaObject::activate(this, &staticMetaObject, 23, Q_NULLPTR);
}

// SIGNAL 24
void Device_page::sRejimeDevButtons(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}
QT_END_MOC_NAMESPACE
