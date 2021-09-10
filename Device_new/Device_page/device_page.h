#ifndef DEVICE_PAGE_H
#define DEVICE_PAGE_H

#include <QMainWindow>

#include <QObject>
#include <QGroupBox>
#include <QBoxLayout>
#include <QFont>
#include <QSettings>
#include <QTextCodec>
#include <QPoint>
#include <QToolBar>
#include <QPushButton>
#include <QButtonGroup>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>
#include <QSplashScreen>
#include <QPixmap>
#include <QDateTime>
#include <QLabel>
#include <QStatusBar>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QPalette>
#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QEventLoop>
#include <QEvent>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QCloseEvent>
#include <QTranslator>
#include <QProcess>
#include <QTemporaryFile>
#include <QThread>
#include <QGraphicsDropShadowEffect>
#include <QMovie>
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>
#include <QUrl>
#include <QDialog>
#include <QQueue>
#include <QDateTime>

#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDataStream>
#include <QByteArray>

#include "graph_fluor.h"
#include "graph_temperature.h"
#include "request_dev.h"
#include "protocol_lib.h"
#include "device_info.h"
#include "worker_wait.h"

#include "device_page_global.h"

enum DevState {sUnknown = -1, sNothing, sRun, sPause, sHold, sWarming_up};


//-----------------------------------------------------------------------------

class DEVICE_PAGESHARED_EXPORT Device_page: public QMainWindow

{
    Q_OBJECT

public:
    Device_page(QWidget *parent = 0);
    ~Device_page();

    rt_Protocol *Prot;

    //... flags ...
    bool flag_Compatibility;
    bool flag_SavingResult;
    bool flag_CloseRun;

    QGroupBox   *DeviceGroupBox;
    //QGroupBox   *Control_Dev;
    QTabWidget  *Tab_Dev;
    //QGroupBox   *Information_Dev;

    //... Temperature ...
    QGroupBox               *Temperature_Box;
    GraphTemperaturePlot    *plot_temperature;

    //... Fluor ...
    QGroupBox               *Fluor_Box;
    GraphFluorPlot          *plot_fluor;

    //... RunTime ...
    QGroupBox   *RunTime_Box;

    //... Info about Device ...
    QGroupBox   *Information_Box;
    Device_Info *Info;

    //... Information ...
    QLabel  *Device_Name;
    QLabel  *Protocol_Name;
    //QPushButton *Clear_Dev;
    QWidget *box_Dev;
    //QLabel  *Temperature_Block;
    //QLabel  *FN_label;
    //QLabel  *Status_LoadProtocol;
    //QLabel  *Name_Protocol;

    //... Information.time ...
    QLabel      *label_Time;
    /*QComboBox   *time_first;
    QLabel      *label_first;
    QGroupBox   *box_first;
    QComboBox   *time_second;
    QLabel      *label_second;
    QGroupBox   *box_second;
    */


    QPushButton *RunDev;
    QPushButton *StopDev;
    QPushButton *PauseDev;
    QPushButton *open_Block;
    QPushButton *close_Block;

    QTimer dev_timer;
    DevState getDevState(void) { return Dev_State; } //SSE

    QMessageBox *Message;
    QString barcode;

    //... parameters Protocols ...
    int FN;                         // fn in protocol
    int fn_dev;                     // fn in device
    double T_hold;
    double T_current;
    int active_ch;                  // active_channels

    //... device parameters ...
    QVector<QString> SpectralCoeff;
    QVector<QString> OpticCoeff;
    QVector<QString> UnequalCoeff;

    QVector<short> XY;          // centers
    qint16 Rx;                  // radius_x
    qint16 Ry;                  // radius_y
    QVector<qint8> offset_XY;   // offsts for channel

    QVector<quint16> Expozition;    // 2 expt for channel: 2*CountMax = 2*8
    //...

    //... NetWork ...
    QTcpSocket  *m_pTcpSocket;          // socket for check connection status for every Server_Dev's
    quint32      m_nNextBlockSize;

    QVector<QString> Client_Net;        // [0] - command [1...] - parameters
    QList<QString> List_Requests;
    QMap<QString, QBasicTimer*> Map_TimerRequest;
    QStringList Catalogue_Requests;

    QMap<QString,QString> map_InfoDevice;
    QMap<QString,QString> map_InfoData;
    QMap<QString,QString> map_Run;
    QMap<QString,QByteArray> map_Measure;
    QMap<QString,QString> map_CMD;
    QMap<QString,QString> map_Picture;
    QMap<QString,QByteArray> map_PictureData;
    QMap<QString,QString> map_SavePar;
    QMap<QString,QString> map_temp;
    QMap<QString,QString> map_Device;
    QMap<QString,QString> map_Closed;
    QMap<QString,QString> map_Sector;
    QMap<QString,QString> map_Median;
    QMap<QString,QString> map_Default;
    QMap<QString,QString> map_Exit;

    QMap<QString,QString> *map_TMP;



    QQueue<int> Queue_State;
    DevState    Dev_State;

    void connect_Device();
    bool Check_ChangeDevice(int);
    bool Load_Expozition();
    bool CopyToInput(QString, rt_Protocol*);
    bool CopyToOutput(QString, rt_Protocol*);
    void Limit_Dir(QString dir, int lim = 10);
    bool Create_RunProtocol(QString);               // IN + Device
    bool Create_MeasureProtocol(QString text = ""); // create Measure protocol (RUN + Measure)
    bool Load_SpectralCoeff();                      // load spectral coefficients
    bool Load_OpticCoeff();                         // load optic coefficients
    bool Load_UnequalCoeff();                       // load unequal coefficients
    bool Load_Mask();                               //
    QString Load_OpticMask();                       // load optical mask: status auto,radius,offset,mask(x,y)


    void TIM_info(QString);
    QString TIM_state;
    QDateTime prot_Start;
    QStringList list_Time;

    // Lanquage
    void readsettings();
    QTranslator translator;
    QTranslator qt_translator;

public slots:
    void slotConnected();
    void slotReadyRead();
    void slotSendToServer(QString);
    void slotError(QAbstractSocket::SocketError);

    void slot_OpenBlock();
    void slot_CloseBlock();
    void slot_Run();
    void slot_Stop();
    void slotSendRequestInfo();
    void slotGetInfoDevice();

    void slot_DeviceRequest(QMap<QString,QString>*);
    void slot_RequestCloseBlock(QMap<QString,QString>*);
    void slot_RequestExit(int);
    void slot_RefreshMeasure(QMap<QString, QString>*);
    void slot_RefreshInfoDevice(QMap<QString, QString>*);
    bool slot_GetMeasure(int);
    void slot_ChangeStateDevice(int);

    void slot_StatusProtocol(QString);

    void change_FirstTime(int);
    void change_SecondTime(int);

    void again_connect();


signals:
    void sRefresh(QMap<QString,QString>*);
    void sRefreshFluor(void);
    //void finished_WaitProcess();
    void sDeviceRequest(QMap<QString,QString>*);
    void sRequestProtocol(QString);
    void sRequestCloseBlock(QMap<QString,QString>*);
    void sChangePage(int);
    void sChangeStateDevice(int);
    void sNewProtocol(rt_Protocol*);
    void sOpenProtocolAfterRun(QString);

    void sWait_Process(Wait_state, int ,QString);
    void sFinished_WaitProcess();

    void sSendLogData(QString);

};

#endif // DEVICE_PAGE_H
