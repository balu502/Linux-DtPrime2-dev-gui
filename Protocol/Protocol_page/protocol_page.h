#ifndef PROTOCOL_PAGE_H
#define PROTOCOL_PAGE_H

#include <QMainWindow>

#include <QObject>
#include <QGroupBox>
#include <QBoxLayout>
#include <QFont>
#include <QFontMetrics>
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
#include <QQuickWidget>
#include <QSplitter>
#include <QDialog>
#include <QVector>
#include <QFileDialog>
#include <QDomDocument>

#include "protocol_page_global.h"

#include "protocol_lib.h"
#include "protocol_list.h"
#include "protocol_info.h"
#include "protocol_program.h"
#include "protocol_samples.h"
#include "worker_wait.h"

#define ToleranceMinLevel 5

class PROTOCOL_PAGESHARED_EXPORT Protocol_page: public QMainWindow
{
    Q_OBJECT

public:
    Protocol_page(QWidget *parent = 0);
    ~Protocol_page();

    rt_Protocol     *Prot;
    Protocol_List   *List_Protocols;
    ChoiceType_Dialog *Choice_Type;
    QQuickWidget    *pweb;

    QGroupBox   *ProtocolGroupBox;
    QGroupBox   *Control_Pro;
    QTabWidget  *Tab_Pro;

    //... Tabs ...
    QGroupBox   *Program_group;
    QGroupBox   *Plate_group;
    QGroupBox   *Sample_group;
    QGroupBox   *TestSample_group;
    QGroupBox   *Info_group;

    Protocol_Info       *Info;    
    Protocol_Program    *Program_scheme;
    Plot_ProgramAmpl    *Plot_Program;
    PlateTableWidget    *Plate;
    Protocol_Samples    *Samples;

    QMovie  *obj_gif;
    QLabel  *label_gif;
    QMessageBox *message_pro;


    //... Control ...
    QLabel  *Name_Pro;
    QPushButton *Open_Pro;
    QPushButton *Clear_Pro;
    QPushButton *Last_Pro;
    //QPushButton *OpenUSB_Pro;

    QMap<QString,QString>   *list_protocols;
    QMap<QString,QString>   *map_InfoDevice;
    QVector<quint16>        *Expozition_dev;
    QVector<quint16>        *Expozition_Def;
    QVector<double>         *expozition_Coeff;

    void readsettings();
    QTranslator translator;

    //QLabel *protocol_Label;
    QLabel *ERROR_Label;

    //... Methods ...
    bool Check_ValidityProtocol(QString&);          // checking validity protocol - tests program,expo,
    bool Check_Compatibility(QString&);             // checking compatibility device and protocol
    void SetPpoperty_WebProtocol(rt_Protocol*, bool);

signals:
    void sStatusProtocol(QString);

    void sWait_Process(Wait_state, int ,QString);
    void sFinished_WaitProcess();

    void sRejimeDevButtons(int,int);
    void sKeyPress(int);

public slots:
    void open_Manually();
    void open_Protocol(QString id_prot = "");
    void open_USBProtocol();
    void open_localProtocol();
    bool open_localLastRun();
    void find_Protocol(QString);
    void clear_Protocol();
    bool load_fromXML(QString, bool web_pro = false);
    void slot_ChangeStateDevice(int);
    void slot_LoadUSBProtocol();
    void slot_ChangeLink(int);

    void slot_KeyPress(int);

protected:
    //void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;

};

#endif //PROTOCOL_PAGE_H
