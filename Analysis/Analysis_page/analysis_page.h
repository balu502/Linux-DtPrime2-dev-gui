#ifndef ANALYSIS_PAGE_H
#define ANALYSIS_PAGE_H

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
#include <QVariant>

#include "protocol_lib.h"
#include "protocol_info.h"
#include "protocol_program.h"
#include "protocol_samples.h"
#include "protocol_list.h"
#include "graph_fluor.h"
#include "worker_wait.h"


#include "analysis_page_global.h"

class ANALYSIS_PAGESHARED_EXPORT Analysis_page: public QMainWindow
{
    Q_OBJECT

public:
    Analysis_page(QWidget *parent = 0);
    ~Analysis_page();

    rt_Protocol     *Prot;
    QQuickWidget    *pweb;
    Protocol_List   *List_Protocols;
    ChoiceType_Dialog *Choice_Type;

    QMap<QString,QString>   *list_protocolsCompleted;

    QString current_Protocol;
    QString current_ID;
    QMessageBox *message_analysis;

    QGroupBox   *AnalysisGroupBox;
    QGroupBox   *Control_Analysis;
    QTabWidget  *Tab_Analysis;

    //... Tabs ...
    QGroupBox   *Fluor_Box;
    QGroupBox   *Program_group;
    QGroupBox   *Plate_group;
    QGroupBox   *Sample_group;
    //QGroupBox   *TestSample_group;
    QGroupBox   *Info_group;

    Protocol_Info       *Info;
    Protocol_Program    *Program_scheme;
    Plot_ProgramAmpl    *Plot_Program;
    GraphFluorPlot      *Plot_fluor;
    Protocol_Samples    *Samples;
    PlateTableWidget    *Plate;


    //... Control ...
    QLabel  *Name_Analysis;
    QPushButton *Clear_Analysis;
    QPushButton *Open_Analysis;
    QPushButton *Save_Analysis;
    QPushButton *OpenUSB_Analysis;
    QPushButton *SaveUSB_Analysis;

    void readsettings();
    QTranslator translator;


public slots:
    void open_Manually();
    void open_Protocol(QString fn = "");
    void open_ProtocolCompleted(QString id_prot = "");
    void open_USBProtocol();
    void save_Manually();
    void save_Protocol();
    void save_USBProtocol();
    bool load_fromXML(QString);
    void clear_Protocol();
    void check_SaveProcedure();

    void slot_KeyPress(int);

signals:
    void sWait_Process(Wait_state, int ,QString);
    void sFinished_WaitProcess();

    void sRejimeDevButtons(int,int);
    void sKeyPress(int);

};

#endif // ANALYSIS_PAGE_H
