#ifndef MAIN_RT_H
#define MAIN_RT_H

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
#include <QStyleFactory>
#include <QDialog>
#include <QTextCodec>
#include <QProgressBar>
#include <QFontDatabase>
#include <QDomDocument>
#include <QTextEdit>
#include <QScreen>


//... Qml, Qt_script...
#include <QtScript>
#include <QQuickWidget>
#include <QQmlEngine>
#include <QQmlContext>
#include <QMetaObject>
#include <QVariant>

#include "worker_wait.h"

#include <sp.h>
#include <device_page.h>
#include <graph_fluor.h>
#include <graph_temperature.h>
#include <device_info.h>
#include <protocol_page.h>
#include <protocol_samples.h>
#include <settings_page.h>
#include <analysis_page.h>



#define SLEEP_INTERVAL 3000

//-----------------------------------------------------------------------------
class Web_Interface: public QObject
{
    Q_OBJECT

public:
    Web_Interface(QWidget *parent = 0);
    ~Web_Interface();

    Q_PROPERTY(bool connection_Server READ get_connection WRITE set_connection NOTIFY connection_Changed)
    Q_PROPERTY(QString url_Server WRITE set_url)

    bool connection_Server;
    QString url_Server;
    QMap<QString,QString> list_Protocols;
    QMap<QString,QString> list_ProtocolsCompleted;

    void set_connection(const bool&);
    bool get_connection() const;
    void set_url(const QString&);

signals:
    void connection_Changed(bool);
    void listProtocols_Changed();
    void message_FromServer(QString);
    void message_ToServer(QString);

    void send_ProtocolToSetup(QString,bool);
    void send_ProtocolToScenario(QString);

    void change_SocketState(bool);
    void send_ExecCommand(QString);
    void AnswerRequest_ToServer(QString);

public slots:
    void change_connection(bool);
    void get_ListProtocols(QString, QString);
    void get_ListCompleted(QString, QString);
    void get_Protocol(QString);
    void get_Message(QString);
    void send_Message(QString);
    void exec_Command(QString);

};

//-----------------------------------------------------------------------------
class Exit_Dialog: public QDialog
{
    Q_OBJECT

public:
    Exit_Dialog(QWidget *parent = 0);
    ~Exit_Dialog();

    QPushButton *cancel_Button;
    QPushButton *shutdown_Button;
    QPushButton *standby_Button;
    QPushButton *restart_Button;
    QButtonGroup *group_Exit;

    int *status;

    //QMessageBox *message;

private slots:
    void close_Exit(QAbstractButton*);
};

//-----------------------------------------------------------------------------
class Main_RT : public QMainWindow
{
    Q_OBJECT

public:
    Main_RT(QWidget *parent = 0);
    ~Main_RT();

    Exit_Dialog     *EXIT;
    Web_Interface   *Web;
    QQuickWidget    *pweb;

    int exit_status;

    QGroupBox *MainGroupBox;        // Main Box
    QHBoxLayout *main_layout;       // Main Layout
    QProgressBar *main_Progress;    // ProgressBar
    QLabel *PrBar_status;           // Label -> ProgressBar

    QToolBar *main_ToolBar;         //
    QGroupBox *box_ToolBar;
    QPushButton *protocol_Button;
    QPushButton *device_Button;
    QPushButton *analysis_Button;
    QPushButton *preference_Button;
    QPushButton *exit_Button;

    QGroupBox   *buttons_DeviceGroup;
    QPushButton *Dev_0;
    QPushButton *Dev_1;
    QPushButton *Dev_2;
    QPushButton *Dev_3;
    QPushButton *Dev_4;
    QButtonGroup    *Dev_Buttons;
    QTimer      *timer_DevButtons;

    QTimer      *timer_StandBy;
    QTimer      *timer_ShutDown;

    QGroupBox   *group_PB;

    QLabel *rejime_label;           // Rejime label
    QMovie *rejime_gif;
    QLabel *type_Connection;        // Type connection: Ethernet or USB
    QLabel *socket_State;           // socket state: active or disactive

    QStackedWidget *pagesWidget;    // Pages Widget
    QSplashScreen *splash_screen;
    //QLabel        *StandBy_Label;

    //QWidget *statusBar_widget;      // statusBar
    QLabel *mode_label;
    QTimer *timer;
    QButtonGroup *group_Buttons;
    QMessageBox *message_main;
    QLabel  *label_Attention;

    // Web Timer
    QTimer *timer_Web;


    // methods
    void create_MainGroupBox();
    void create_ToolBar();    
    void create_PagesWidget();
    void create_StatusBar();

    // pages
    Device_page *Device;
    Protocol_page *Protocol;
    Analysis_page *Analysis;
    Settings_page *Settings;

    // Lanquage & Settings
    QStringList Web_Parameters;
    QString Language;
    bool read_WebSettings(QString);
    void readsettings();
    QTranslator translator;
    QTranslator qt_translator;

private:
    int sleepInterval;
    void create_Splash(void);

private slots:
    void WebConnect();
    void check_WebConnection();     // Web connection
    void update_DateTime();         // Data&Time
    void clicked_Buttons(QAbstractButton*);
    void slot_RequestProtocol(QString);
    void slot_Exit();
    void slot_Exit_next();
    //void slot_ChInt(bool);
    //void slot_ChInt(int);
    void slot_ChangePage(int);
    void slot_ChangeStateDevice(int);
    void slot_ChangeLink(int);
    void slot_UpdateSoftware();
    void slot_ChangeSocketState(bool);

public slots:
    void wait_process(Wait_state, int ,QString); // run wait process
    void slot_DisplayProcess(int, QString);
    void slot_Finishing_WaitProcess();

    void slot_RunStart();
    void slot_RunStop();    
    void slot_AnswerRequest(QString);

    void slot_EnableButtonExit(bool);

    void slot_PrintScreen();

    void slot_AllChilds();
    void slot_TimerDevButtons();

    void slot_StandBy();
    void slot_ShutDown();

    //... for Dev_Buttons ...
    void slot_PressDevButtons(int);
    void slot_RejimeDevButtons(int, int sub_widget = 0);

    void TempTimer();

signals:
    void sExit(int);
    void sExit_next();
    void finished_WaitProcess();
    void send_IP(QString);

    void sStandBy(QString);
    void sShutDown(QString);

    //...
    void sProtocolOpen();


protected:
    void showEvent(QShowEvent *e) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
  //bool event(QEvent *);

};

#endif // MAIN_RT_H
