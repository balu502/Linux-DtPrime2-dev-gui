#include "main_rt.h"


//-----------------------------------------------------------------------------
//--- Exit
//-----------------------------------------------------------------------------
Exit_Dialog::Exit_Dialog(QWidget *parent)
    : QDialog(parent)
{
    setFixedSize(380,100);

    //Qt::WindowFlags flags = 0;
    //setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint);
    //setWindowFlags(Qt::Popup);
    setWindowFlags(Qt::ToolTip);
    setStyleSheet("border: 1px solid #777");


    group_Exit = new QButtonGroup(this);
    shutdown_Button = new QPushButton(QIcon(":/images/shutdown.png"),"", this);
    standby_Button = new QPushButton(QIcon(":/images/standby.png"),"", this);
    restart_Button = new QPushButton(QIcon(":/images/restart-32.png"),"", this);
    cancel_Button = new QPushButton(QIcon(":/images/back.png"),"", this);


    shutdown_Button->setFixedSize(64,64);
    standby_Button->setFixedSize(64,64);
    restart_Button->setFixedSize(64,64);
    cancel_Button->setFixedSize(64,64);

    shutdown_Button->setIconSize(QSize(32,32));
    standby_Button->setIconSize(QSize(32,32));
    restart_Button->setIconSize(QSize(32,32));
    cancel_Button->setIconSize(QSize(32,32));

    QHBoxLayout *layout = new QHBoxLayout;
    setLayout(layout);
    layout->addWidget(shutdown_Button);
    layout->addWidget(restart_Button);
    layout->addWidget(standby_Button);    
    layout->addStretch(1);
    layout->addWidget(cancel_Button);

    status = &((Main_RT*)parent)->exit_status;

    group_Exit->addButton(shutdown_Button);
    group_Exit->addButton(standby_Button);
    group_Exit->addButton(restart_Button);
    group_Exit->addButton(cancel_Button);
    connect(group_Exit, SIGNAL(buttonReleased(QAbstractButton*)), this, SLOT(close_Exit(QAbstractButton*)));

    //message = new QMessageBox(this);

}
//-----------------------------------------------------------------------------
//--- ~Exit
//-----------------------------------------------------------------------------
Exit_Dialog::~Exit_Dialog()
{
    delete shutdown_Button;
    delete standby_Button;
    delete cancel_Button;

    //delete message;
}
//-----------------------------------------------------------------------------
//--- Exit
//-----------------------------------------------------------------------------
void Exit_Dialog::close_Exit(QAbstractButton *button)
{

    if(button == shutdown_Button)
    {
        *status = 0;
        /*message->setStandardButtons(QMessageBox::Ok| QMessageBox::Cancel);
        message->setIcon(QMessageBox::Question);
        message->setText(tr("Attention! Do you want to off the device?"));
        if(message->exec() == QMessageBox::Cancel)
        {
            *status = 2;
        }*/
    }

    if(button == standby_Button)   *status = 1;
    if(button == cancel_Button)   *status = 2;
    if(button == restart_Button)   *status = 5;



    hide();
}

//-----------------------------------------------------------------------------
//--- Main_RT
//-----------------------------------------------------------------------------
Main_RT::Main_RT(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(800,480);
    QFontDatabase::addApplicationFont(":/images/times.ttf");
    QFont Font("Times New Roman", 14);
    qApp->setFont(Font);
    readsettings();

    //... Text Codec ...
    QTextCodec *russianCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(russianCodec);

    Qt::WindowFlags flags = 0;
    setWindowFlags(flags | Qt::FramelessWindowHint);

    qApp->setStyle(QStyleFactory::create("Fusion"));
    setStyleSheet(
                "QGroupBox {margin-top: 1ex; background: #FAFAFA; border: 1px solid #ddd;}"
                "QGroupBox#Transparent {border: 1px solid transparent;}"
                "QPushButton::hover {background-color: #fff;}"
                "QPushButton::disabled {background-color: #DADADA;}"
                //"QPushButton::enabled {background-color: #FAFAFA;}"
                "QPushButton::enabled {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC);}"
                "QPushButton::focused {background-color: #FAFAFA;}"
                //"QPushButton::pressed {background-color: #ccc;}"
                "QPushButton::pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ccc, stop: 1 #777);}"
                //"QPushButton::checked {background-color: #999;}"
                "QPushButton::checked {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #999, stop: 1 #555);}"
                "QPushButton {text-align: center;}"
                //"QPushButton {min-width: 80px; min-height: 30px;}"
                "QPushButton {min-width: 2.5em; margin:1; padding:5;}"
                "QPushButton {border: 1px solid #777; border-radius: 0px;}"
                "QPushButton#Transparent {border: 0px solid #aaa; min-width: 1em; margin:0; padding: 2;}"
                "QListWidget {background-color: #ffffff; selection-background-color: #d7d7ff; selection-color: black;}"
                "QComboBox {background-color: #ffffff; selection-background-color: #d7d7ff; selection-color: black;}"
                "QComboBox::down-arrow {image: url(:/images/down_arrow_width.png);}"
                "QComboBox::down-arrow:on {top: 1px; left: 1px;}"
                "QComboBox::drop-down {subcontrol-origin: padding; subcontrol-position: top right; width: 30px; background-color: #ffffff; border: 1px solid #777; min-width: 30px;}"
                "QStatusBar {background: #FAFAFA; border: 1px solid #ddd;}"
                //"QTabBar::tab:!selected {background: #FAFAFA; border: 1px solid #777; border-radius: 2px;}"
                //"QTabBar::tab:disabled {background: #eee; border: 1px solid #aaa; border-radius: 2px;}"
                "QTabBar::tab:!selected {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC); border: 1px solid #777; border-radius: 2px;}"
                "QTabBar::tab:selected {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #999, stop: 1 #555); border: 1px solid #777; border-radius: 2px;}"
                "QMessageBox QPushButton {min-width: 80px; min-height: 30px; border: 1px solid #111; color: black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC);}"
                "QMessageBox {border: 1px solid #111; background-color: #ffffff;}"
                "QTreeWidget {selection-background-color: #d7d7ff; selection-color: black;}"

                /*"QTreeView::branch:open:has-children:!has-siblings,"
                "QTreeView::branch:open:has-children:has-siblings  {"
                        "border-image: none;"
                        "image: url(:/images/closed.png);}"
                "QTreeView::branch:has-children:!has-siblings:closed,"
                "QTreeView::branch:closed:has-children:has-siblings {"
                        "border-image: none;"
                        "image: url(:/images/opened.png);}"*/


                "QHeaderView::section {background-color: #FFFFFF; border: 1px solid gray; border-left: 0px; border-top: 0px; padding:3; margin:0;}"
                "QProgressBar:horizontal {border: 1px solid gray; background: #FAFAFA; padding: 2px;}"
                "QProgressBar::chunk:horizontal {background: qlineargradient(x1: 0, y1: 0.1, x2: 1, y2: 0.1, stop: 0 #B5D8E6, stop: 1 #409BBD);}"

                "QScrollBar:vertical {border: 1px solid black; width: 35px; margin: 30px 0 30px 0; background-color: white;}"
                "QScrollBar::handle:vertical {min-height: 30px; background-color: #ccc; border: 1px solid black;}"
                "QScrollBar::add-line:vertical {border: 1px solid black; height: 30px; subcontrol-position: bottom;subcontrol-origin: margin;}"
                "QScrollBar::sub-line:vertical {border: 1px solid black; height: 30px; subcontrol-position: top; subcontrol-origin: margin;}"
                "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {border: 1px solid black; min-width: 20px; min-height: 20px; background: white;}"
                "QScrollBar::down-arrow:vertical {image: url(:/images/down_arrow.png);}"
                "QScrollBar::up-arrow:vertical {image: url(:/images/up_arrow.png);}"
                "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;}"
                "QDialog {background-color: #ffffff; border: 1px solid black; border: 1px solid #777;}"
                );


    create_MainGroupBox();    
    create_ToolBar();
    create_PagesWidget();
    create_StatusBar();
    //create_Splash();

    device_Button->click();
    //protocol_Button->click();

    //Message.setWindowIcon(QIcon(":/images/dna_2.ico"));

    //... Data&Time ...
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_DateTime()));
    update_DateTime();
    timer->start(1000);
    sleepInterval=0;

    //... Timer Web ...
    timer_Web = new QTimer(this);
    connect(timer_Web, SIGNAL(timeout()), this, SLOT(check_WebConnection()));
    timer_Web->start(10000);

    //... WEB ...
    Web = new Web_Interface(this);
    pweb = new QQuickWidget(this);
    pweb->rootContext()->setContextProperty("Web", Web);
    pweb->setSource(QUrl::fromLocalFile(qApp->applicationDirPath() + "/qml/web_30sep.qml"));

    connect(Web, SIGNAL(send_ProtocolToSetup(QString,bool)), Protocol, SLOT(load_fromXML(QString,bool)));
    connect(Web, SIGNAL(change_SocketState(bool)), this, SLOT(slot_ChangeSocketState(bool)));
    connect(Web, SIGNAL(send_ExecCommand(QString)), Device, SLOT(slot_Exec_Commaand(QString)));
    connect(Web, SIGNAL(AnswerRequest_ToServer(QString)), this, SLOT(slot_AnswerRequest(QString)));

    Protocol->list_protocols = &Web->list_Protocols;
    Analysis->list_protocolsCompleted = &Web->list_ProtocolsCompleted;
    Protocol->pweb = pweb;
    Analysis->pweb = pweb;
    //pweb->show();

    message_main = new QMessageBox(this);

    label_Attention = new QLabel(tr("Do not turn off the power of the device before the end of the program..."), this);
    label_Attention->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label_Attention->setAlignment(Qt::AlignCenter);
    label_Attention->setStyleSheet("QLabel{border: 1px solid #111; background-color: white; color: red};");
    label_Attention->setFixedWidth(700);
    label_Attention->move(50,220);
    label_Attention->setVisible(false);    

    EXIT = new Exit_Dialog(this);
    EXIT->setVisible(false);

    timer_StandBy = new QTimer(this);
    timer_ShutDown = new QTimer(this);
    connect(timer_StandBy, SIGNAL(timeout()), this, SLOT(slot_StandBy()));
    connect(this, SIGNAL(sStandBy(QString)), splash_screen, SLOT(Set_StandBy(QString)));
    connect(timer_ShutDown, SIGNAL(timeout()), this, SLOT(slot_ShutDown()));
    connect(this, SIGNAL(sShutDown(QString)), splash_screen, SLOT(Set_ShutDown(QString)));

    //QTimer::singleShot(1000, this, SLOT(slot_AllChilds()));
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Main_RT::slot_AllChilds()
{
    QObjectList children = this->children();
    foreach(QObject * child, children)
    {
        QWidget *w = qobject_cast<QWidget*> (child);
        if(w)
        {
            qDebug() << "child: " <<  w->pos() << w->size() << w->metaObject()->className();
        }
    }
}

//-----------------------------------------------------------------------------
//--- ~Main_RT()
//-----------------------------------------------------------------------------
Main_RT::~Main_RT()
{

    qDebug() << "Destructor...";

    //exit_status = 1;
    //slot_Exit_next();

    delete Web;
    delete pweb;

    delete message_main;
    delete EXIT;

    delete Device;
    delete Protocol;
    delete Analysis;
    delete Settings;
    delete pagesWidget;

    removeToolBar(main_ToolBar);
    delete main_ToolBar;

    delete MainGroupBox;

    delete mode_label;
    delete rejime_gif;
    delete rejime_label;
    delete type_Connection;
    delete socket_State;
    //delete statusBar_widget;
}
//-----------------------------------------------------------------------------
//--- slot_ShutDown()
//-----------------------------------------------------------------------------
void Main_RT::slot_ShutDown()
{
    timer_ShutDown->stop();
    emit sShutDown(tr("ShutDown"));
}

//-----------------------------------------------------------------------------
//--- slot_StandBy()
//-----------------------------------------------------------------------------
void Main_RT::slot_StandBy()
{
    timer_StandBy->stop();

    if(splash_screen->isHidden()) splash_screen->show();
    emit sStandBy(tr("StandBy"));

}
//-----------------------------------------------------------------------------
//--- keyPressEvent
//-----------------------------------------------------------------------------
void Main_RT::keyReleaseEvent(QKeyEvent *e)
{
    qDebug() << "KeyRelease: " << e->key();

    if(e->key() == 0x1000034)
    {
        timer_StandBy->stop();
        timer_ShutDown->stop();
    }

    //slot_PressDevButtons(e->key());
    //e->ignore();
    //e->accept();

    QMainWindow::keyReleaseEvent(e);
}

//-----------------------------------------------------------------------------
//--- keyPressEvent
//-----------------------------------------------------------------------------
void Main_RT::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "KeyPress: " << e->key();

    int h = 0;
    int H = 40;
    int k = 3;
    int state;

    int key = e->key();


    if(key == 0x1000034)
    {
        if(Device->PWR_State == PWR_WAKEUP)   //
        {
            state = 1;
            splash_screen->show();
            //QTimer::singleShot(2000, this, SLOT(slot_StandBy()));
        }
        if(Device->PWR_State == PWR_STANDBY)
        {
            state = 2;
            splash_screen->hide();
        }
        Device->slot_RequestExit(state);

        //... StandBy & ShutDown ...
        timer_StandBy->start(1500);
        timer_ShutDown->start(6000);

    }

    slot_PressDevButtons(key);

    /*if(key >= 0x1000030 && key <= 0x1000033)
    {

        if(!splash_screen->isHidden())
        {
            qDebug() << "splash_screen->isHidden(): ";
            Device->slot_RequestExit(2);
            splash_screen->hide();
        }

        if(buttons_DeviceGroup->height() == 0)
        {
            while(k>0)
            {
                //Sleep(1);
                h += 17;
                buttons_DeviceGroup->setFixedHeight(h);
                group_PB->setFixedHeight(H+h);
                update();
                qApp->processEvents();
                k--;
            }

            timer_DevButtons->start(7000);
        }
        else
        {
            //qDebug() << " event for Button:" << key - 0x1000030;
            timer_DevButtons->stop();
            timer_DevButtons->start(7000);

            key = key - 0x1000030;
            QAbstractButton *b = Dev_Buttons->button(key);
            if(b)
            {
                if(b->isEnabled())
                {
                    b->setDown(true);
                    b->repaint();
                    qApp->processEvents();
                    b->click();
                    Sleep(200);
                    b->setDown(false);
                    b->repaint();
                    qApp->processEvents();
                }
            }
        }

    }*/

    //e->ignore();
    //e->accept();
    QMainWindow::keyPressEvent(e);
}
//-----------------------------------------------------------------------------
//--- showEvent
//-----------------------------------------------------------------------------
void Main_RT::slot_TimerDevButtons()
{
    timer_DevButtons->stop();

    buttons_DeviceGroup->setFixedHeight(0);
    group_PB->setFixedHeight(40);
}

//-----------------------------------------------------------------------------
//--- showEvent
//-----------------------------------------------------------------------------
void Main_RT::showEvent(QShowEvent *e)
{
    e->accept();

    QVariant url;
    QString text = "";
    if(Web_Parameters.size() >= 2) text = QString("ws://%1:%2").arg(Web_Parameters.at(0)).arg(Web_Parameters.at(1));
    url = text;
    Web->url_Server = text;
    bool state_connection = true;
    QVariant returned_Value = NULL;
    QVariant state = state_connection;
    QObject *obj = (QObject*)(pweb->rootObject());

    QMetaObject::invokeMethod(obj, "set_SocketUrl",
                              Q_RETURN_ARG(QVariant, returned_Value),
                              Q_ARG(QVariant, url));
}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Main_RT::readsettings()
{
    QString dir_SysTranslate;

    // Read web_settings
    read_WebSettings(qApp->applicationDirPath() + "/settings/settings.xml");

    // Language
    if(Language == "ru")
    {
        translator.load(":/translations/ru.qm");
        dir_SysTranslate = qApp->applicationDirPath() + "/translations/ru";
        qt_translator.load("qt_ru.qm", dir_SysTranslate);
        qApp->installTranslator(&qt_translator);
    }
    if(Language == "en" || Language.isEmpty())
    {
        translator.load(":/translations/en.qm");
    }
    qApp->installTranslator(&translator);

}
//-----------------------------------------------------------------------------
//--- read_WebSettings(QString fn)
//-----------------------------------------------------------------------------
bool Main_RT::read_WebSettings(QString fn)
{
    QString ip,port;

    QDomDocument    doc;
    QDomElement     root;
    QDomNode        child;

    QFile file(fn);

    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        if(!doc.setContent(&file))
        {
            file.close();
            return(false);
        }
        file.close();

        root = doc.documentElement();

        ip = root.firstChildElement("ip_server").text();
        port = root.firstChildElement("port_server").text();
        Language = root.firstChildElement("language").text();


        Web_Parameters << ip << port;
        qDebug() << "ip,port,Language: " << ip << port << Language;
        return(true);
    }
    else return(false);

}

//-----------------------------------------------------------------------------
//--- create_MainGroupBox()
//-----------------------------------------------------------------------------
void Main_RT::create_MainGroupBox()
{
    MainGroupBox = new QGroupBox(this);
    MainGroupBox->setObjectName("Transparent");
    setCentralWidget(MainGroupBox);
    main_layout = new QHBoxLayout;
    main_layout->setMargin(2);
    main_layout->setSpacing(4);
    MainGroupBox->setLayout(main_layout);


}
//-----------------------------------------------------------------------------
//--- create_ToolBar()
//-----------------------------------------------------------------------------
void Main_RT::create_ToolBar()
{
    main_ToolBar = new QToolBar(this);
    main_ToolBar->setMovable(false);
    box_ToolBar = new QGroupBox(this);
    box_ToolBar->setObjectName("Transparent");
    box_ToolBar->setFixedWidth(85);

    main_ToolBar->addWidget(box_ToolBar);

    QVBoxLayout *layout_tool = new QVBoxLayout;
    box_ToolBar->setLayout(layout_tool);

    protocol_Button = new QPushButton(this);
    protocol_Button->setFixedSize(64,64);
    //protocol_Button->setMinimumHeight(64);
    //protocol_Button->setFixedHeight(64);
    protocol_Button->setIcon(QIcon(":/images/protocol.png"));
    protocol_Button->setIconSize(QSize(32,32));
    protocol_Button->setCheckable(true);

    device_Button = new QPushButton(this);
    device_Button->setFixedSize(64,64);
    device_Button->setIcon(QIcon(":/images/start.png"));
    device_Button->setIconSize(QSize(32,32));
    device_Button->setCheckable(true);

    analysis_Button = new QPushButton(this);
    analysis_Button->setFixedSize(64,64);
    analysis_Button->setIcon(QIcon(":/images/analysis.png"));
    analysis_Button->setIconSize(QSize(32,32));
    analysis_Button->setCheckable(true);

    preference_Button = new QPushButton(this);
    preference_Button->setFixedSize(64,64);
    preference_Button->setIcon(QIcon(":/images/preference.png"));
    preference_Button->setIconSize(QSize(32,32));
    preference_Button->setCheckable(true);

    exit_Button = new QPushButton(this);
    exit_Button->setIcon(QIcon(":/images/run.png"));
    exit_Button->setIconSize(QSize(32,32));
    exit_Button->setFixedSize(64,64);    

    layout_tool->addWidget(protocol_Button);
    layout_tool->addWidget(device_Button);
    layout_tool->addWidget(analysis_Button);
    layout_tool->addWidget(preference_Button);    
    layout_tool->addWidget(exit_Button, 1, Qt::AlignBottom);

    addToolBar(Qt::LeftToolBarArea, main_ToolBar);

    connect(exit_Button, SIGNAL(released()), this, SLOT(slot_Exit()));
    connect(this, SIGNAL(sExit_next()), this, SLOT(slot_Exit_next()));

    group_Buttons = new QButtonGroup(this);
    group_Buttons->addButton(protocol_Button);
    group_Buttons->addButton(device_Button);
    group_Buttons->addButton(analysis_Button);
    group_Buttons->addButton(preference_Button);


    connect(group_Buttons, SIGNAL(buttonReleased(QAbstractButton*)), this, SLOT(clicked_Buttons(QAbstractButton*)));
    //connect(protocol_Button, SIGNAL(released()), this, SLOT(clicked_Protocol()));
    //connect(device_Button, SIGNAL(released()), this, SLOT(clicked_Device()));
    //connect(analysis_Button, SIGNAL(released()), this, SLOT(clicked_Analysis()));
    //connect(preference_Button, SIGNAL(released()), this, SLOT(clicked_Preference()));

}

//-----------------------------------------------------------------------------
//--- create_PagesWidget()
//-----------------------------------------------------------------------------
void Main_RT::create_PagesWidget()
{
    pagesWidget = new QStackedWidget(this);

    Device = new Device_page(this);
    Protocol = new Protocol_page(this);
    Analysis = new Analysis_page(this);
    Settings = new Settings_page(this);

    splash_screen = new SplashScreen(qApp, Language);
    splash_screen->show();
    splash_screen->hide();

    Device->Prot = Protocol->Prot;

    connect(Device, SIGNAL(sShutDown()), this, SLOT(close()));
    connect(Device, SIGNAL(sRun_rejime(bool)), this, SLOT(slot_EnableButtonExit(bool)));
    connect(Device, SIGNAL(sChangePage(int)), this, SLOT(slot_ChangePage(int)));
    connect(Device, SIGNAL(sChangeStateDevice(int)), Protocol, SLOT(slot_ChangeStateDevice(int)));
    connect(Device, SIGNAL(sChangeStateDevice(int)), this, SLOT(slot_ChangeStateDevice(int)));
    connect(Device, SIGNAL(sSendLogData(QString)), Settings, SLOT(GetLogData(QString)));
    connect(Device, SIGNAL(sLoad_USB_Protocol()), Protocol, SLOT(slot_LoadUSBProtocol()));
    connect(Device, SIGNAL(sRequestProtocol(QString)), Protocol, SLOT(find_Protocol(QString)));
    connect(Device, SIGNAL(sLoad_LastRunProtocol()), Protocol, SLOT(open_localLastRun()));
    connect(Protocol, SIGNAL(sStatusProtocol(QString)), Device, SLOT(slot_StatusProtocol(QString)));
    connect(this, SIGNAL(sExit(int)), Device, SLOT(slot_RequestExit(int)));
    connect(Settings, SIGNAL(changeLink(int)), Device, SLOT(slot_RequestExit(int)));
    connect(splash_screen, SIGNAL(s_PowerWakeup(int)), Device, SLOT(slot_RequestExit(int)));
    connect(this, SIGNAL(send_IP(QString)), splash_screen, SLOT(Get_IP(QString)));
    connect(Settings, SIGNAL(changeLink(int)), this, SLOT(slot_ChangeLink(int)));
    connect(Settings, SIGNAL(changeLink(int)), Device, SLOT(slot_ChangeLink(int)));
    connect(Settings, SIGNAL(changeLink(int)), Protocol, SLOT(slot_ChangeLink(int)));
    connect(Settings, SIGNAL(update_Software()), this, SLOT(slot_UpdateSoftware()));
    connect(Settings, SIGNAL(meas_HeightTubes()), Device, SLOT(slot_MeasureHeight()));
    connect(Settings, SIGNAL(MakeMeasure_Request(int,int,int)), Device, SLOT(slot_GetPicture(int,int,int)));
    connect(Settings, SIGNAL(RefreshInfoDevice()), Device, SLOT(slotGetInfoDevice()));
    connect(Settings, SIGNAL(SaveExpo(int,QString)), Device, SLOT(slot_SaveExpo(int,QString)));
    connect(Device, SIGNAL(sSendPicture(QMap<QString,QByteArray>*)), Settings, SLOT(Get_Picture(QMap<QString,QByteArray>*)));
    connect(Device, SIGNAL(sOpenProtocolAfterRun(QString)), Analysis, SLOT(open_Protocol(QString)));
    connect(Device, SIGNAL(sSaveProtocolToServer()), Analysis, SLOT(save_Protocol()));
    connect(Device, SIGNAL(sWait_Process(Wait_state,int,QString)), this, SLOT(wait_process(Wait_state,int,QString)));
    connect(Device, SIGNAL(sFinished_WaitProcess()), this, SLOT(slot_Finishing_WaitProcess()));
    connect(Device, SIGNAL(sRun_Process(int,QString)), this, SLOT(slot_DisplayProcess(int,QString)));
    connect(Device, SIGNAL(sRun_Start()), this, SLOT(slot_RunStart()));
    connect(Device, SIGNAL(sRun_Stop()), this, SLOT(slot_RunStop()));
    connect(Device, SIGNAL(sRun_Start()), Settings, SLOT(slot_RunStart()));
    connect(Device, SIGNAL(sRun_Stop()), Settings, SLOT(slot_RunStop()));
    connect(Device, SIGNAL(sRefreshInfoDevice()), Settings, SLOT(Get_RefreshInfoDevice()));
    connect(Protocol, SIGNAL(sWait_Process(Wait_state,int,QString)), this, SLOT(wait_process(Wait_state,int,QString)));
    connect(Protocol, SIGNAL(sFinished_WaitProcess()), this, SLOT(slot_Finishing_WaitProcess()));
    connect(Analysis, SIGNAL(sWait_Process(Wait_state,int,QString)), this, SLOT(wait_process(Wait_state,int,QString)));
    connect(Analysis, SIGNAL(sFinished_WaitProcess()), this, SLOT(slot_Finishing_WaitProcess()));

    // connect for Dev_Buttons
    connect(Protocol, SIGNAL(sRejimeDevButtons(int,int)), this, SLOT(slot_RejimeDevButtons(int,int)));
    connect(Protocol, SIGNAL(sKeyPress(int)), this, SLOT(slot_PressDevButtons(int)));
    connect(Device, SIGNAL(sRejimeDevButtons(int,int)), this, SLOT(slot_RejimeDevButtons(int,int)));
    connect(Analysis, SIGNAL(sRejimeDevButtons(int,int)), this, SLOT(slot_RejimeDevButtons(int,int)));
    connect(Analysis, SIGNAL(sKeyPress(int)), this, SLOT(slot_PressDevButtons(int)));
    //

    pagesWidget->addWidget(Protocol);
    pagesWidget->addWidget(Device);
    pagesWidget->addWidget(Analysis);
    pagesWidget->addWidget(Settings);

    //... for Protocol ...
    Protocol->map_InfoDevice = &Device->map_InfoDevice;
    Protocol->Expozition_dev = &Device->Expozition;
    Protocol->Expozition_Def = &Device->Expozition_Def;
    Protocol->expozition_Coeff = &Device->Expozition_Coeff;

    main_layout->addWidget(pagesWidget);

    //... Device Parameters ...
    Settings->XY = &Device->XY;
    Settings->Rx = &Device->Rx;
    Settings->Ry = &Device->Ry;
    Settings->offset_XY = &Device->offset_XY;
    Settings->map_InfoDevice = &Device->map_InfoDevice;
    Settings->Expozition = &Device->Expozition;

    //... IP ...
    emit send_IP(Settings->ip_address->text());

}
//-----------------------------------------------------------------------------
//--- create_StatusBar()
//-----------------------------------------------------------------------------
void Main_RT::create_StatusBar()
{
    QFont f = qApp->font();
    f.setPointSize(f.pointSize()-1);
    f.setBold(true);

    mode_label = new QLabel(this);
    main_Progress = new QProgressBar(this);
    main_Progress->setRange(0,100);
    //main_Progress->setValue(50);
    main_Progress->setFixedHeight(30);
    main_Progress->setTextVisible(false);
    PrBar_status = new QLabel(this);
    PrBar_status->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    PrBar_status->setFont(f);
    QHBoxLayout *probar_layout = new QHBoxLayout();
    main_Progress->setLayout(probar_layout);
    probar_layout->addWidget(PrBar_status);

    mode_label->setFixedWidth(220);
    mode_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    //QLabel *spacer = new QLabel(this);
    //spacer->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    //spacer->setFixedWidth(10);

    rejime_label = new QLabel(this);
    rejime_label->setFixedWidth(32);
    rejime_gif = new QMovie(":/images/active.gif");
    rejime_label->setMovie(rejime_gif);
    rejime_label->setVisible(false);

    type_Connection = new QLabel(this);
    type_Connection->setFixedWidth(32);
    type_Connection->setPixmap(QIcon(":/images/Ethernet_1.png").pixmap(32,32));

    socket_State = new QLabel(this);
    socket_State->setFixedWidth(32);
    socket_State->setPixmap(QIcon(":/images/server_32.png").pixmap(32,32));

    group_PB = new QGroupBox(this);
    group_PB->setObjectName("Transparent");
    QVBoxLayout *pb_layout = new QVBoxLayout();
    pb_layout->setMargin(0);
    pb_layout->setSpacing(0);
    group_PB->setLayout(pb_layout);
    group_PB->setFixedSize(795,40);

    QHBoxLayout *sb_H_layout = new QHBoxLayout();
    sb_H_layout->setMargin(0);
    sb_H_layout->setSpacing(4);
    sb_H_layout->addWidget(mode_label, 0); //, Qt::AlignLeft | Qt::AlignTop);
    sb_H_layout->addWidget(main_Progress, 1); //, Qt::AlignLeft | Qt::AlignTop);
    sb_H_layout->addWidget(socket_State, 0); //, Qt::AlignLeft | Qt::AlignTop);
    sb_H_layout->addWidget(type_Connection, 0); //, Qt::AlignLeft | Qt::AlignTop);
    sb_H_layout->addWidget(rejime_label, 0); //, Qt::AlignLeft | Qt::AlignTop);

    buttons_DeviceGroup = new QGroupBox(this);
    buttons_DeviceGroup->setFixedSize(795,0);
    Dev_0 = new QPushButton("", this);
    Dev_1 = new QPushButton("", this);
    Dev_2 = new QPushButton("", this);
    Dev_3 = new QPushButton("", this);
    Dev_4 = new QPushButton(QIcon(":/images/shutdown.png"), "", this);
    Dev_4->setIconSize(QSize(22,22));
    Dev_Buttons = new QButtonGroup(this);
    Dev_Buttons->addButton(Dev_0,0);
    Dev_Buttons->addButton(Dev_1,1);
    Dev_Buttons->addButton(Dev_2,2);
    Dev_Buttons->addButton(Dev_3,3);
    Dev_Buttons->addButton(Dev_4,4);
    foreach(QAbstractButton * button, Dev_Buttons->buttons())
    {
        button->setDisabled(true);
    }

    QHBoxLayout *buttons_layout = new QHBoxLayout();
    buttons_layout->setMargin(0);
    buttons_DeviceGroup->setLayout(buttons_layout);
    buttons_layout->addSpacing(30);
    buttons_layout->addWidget(Dev_0);
    buttons_layout->addWidget(Dev_1);
    buttons_layout->addWidget(Dev_2);
    buttons_layout->addWidget(Dev_3);
    buttons_layout->addWidget(Dev_4);
    buttons_layout->addSpacing(30);
    timer_DevButtons = new QTimer(this);
    connect(timer_DevButtons, SIGNAL(timeout()), this, SLOT(slot_TimerDevButtons()));

    pb_layout->addLayout(sb_H_layout);
    pb_layout->addWidget(buttons_DeviceGroup);
    //pb_layout->addSpacing(40);


    /*mode_label->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    main_Progress->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    socket_State->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    type_Connection->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    rejime_label->setAlignment(Qt::AlignTop | Qt::AlignHCenter);*/


    /*statusBar()->addPermanentWidget(mode_label);
    statusBar()->addPermanentWidget(main_Progress, 1);
    statusBar()->addPermanentWidget(socket_State);
    statusBar()->addPermanentWidget(type_Connection);
    statusBar()->addPermanentWidget(rejime_label);*/

    statusBar()->addPermanentWidget(group_PB);


    //statusBar()->setFixedHeight(100);
    //group_PB->setFixedHeight(100);


    /*QHBoxLayout *main_layout = new QHBoxLayout();
    setLayout(main_layout);
    //main_layout->addWidget(statusBar(),0,Qt::AlignBottom);

    buttons_Group = new QGroupBox(this);
    buttons_Group->setFixedHeight(50);
    buttons_Group->setFixedWidth(800);
    main_layout->addWidget(buttons_Group,1,Qt::AlignBottom);
    */
}
//-----------------------------------------------------------------------------
//--- create_Splash()
//-----------------------------------------------------------------------------
void Main_RT::create_Splash(void)
{
    QPixmap pixmap(":/images/splash.png");

    /*splash = new QSplashScreen(pixmap);
    //splash->resize(800,480);
    splash->hide();

    // Loading some items
    splash->showMessage("Touch for exit ...");
    */
}
//-----------------------------------------------------------------------------
//--- check_WebConnection()
//-----------------------------------------------------------------------------
void Main_RT::check_WebConnection()
{
    //qDebug() << "Web state: " << Web->url_Server << Web->connection_Server;
    if(!Web->connection_Server)
    {
        WebConnect();
    }
}
//-----------------------------------------------------------------------------
//--- WebConnect()
//-----------------------------------------------------------------------------
void Main_RT::WebConnect()
{
    QVariant url = Web->url_Server;
    bool state_connection = !Web->connection_Server;
    QVariant returned_Value = NULL;
    QVariant state = state_connection;
    QObject *obj = (QObject*)(pweb->rootObject());

    QMetaObject::invokeMethod(obj, "set_SocketUrl",
                              Q_RETURN_ARG(QVariant, returned_Value),
                              Q_ARG(QVariant, url));

    QMetaObject::invokeMethod(obj, "set_StateSocket",
                              Q_RETURN_ARG(QVariant, returned_Value),
                              Q_ARG(QVariant, state));
}

//-----------------------------------------------------------------------------
//--- Slot update_DateTime()
//-----------------------------------------------------------------------------
void Main_RT::update_DateTime()
{
    QString tim = QDateTime::currentDateTime().toString(" d-MM-yy, h:mm:ss ");
    mode_label->setText(tim);

    slot_PrintScreen();

    return;

// SSE
    /*
    if(Device->getDevState()==sNothing) {
      if(++sleepInterval==SLEEP_INTERVAL) {
        splash->show();
        emit sExit(1);
      }
      if(sleepInterval>SLEEP_INTERVAL+1) if(!splash->isVisible()) { sleepInterval=0; sExit(2);}
    }*/
}
//-----------------------------------------------------------------------------
//--- Slot clicked_Buttons(QAbstractButton *button)
//-----------------------------------------------------------------------------
void Main_RT::clicked_Buttons(QAbstractButton *button)
{

    foreach(QAbstractButton *b, group_Buttons->buttons())
    {
        b->blockSignals(true);
        b->setChecked(b == button);
        b->blockSignals(false);
    }

    /*foreach(QAbstractButton *b, Dev_Buttons->buttons())
    {
        b->setDisabled(true);
        b->setText("");
        b->disconnect();
        //b->setIcon(QIcon());
    }*/

    qApp->processEvents();

    if(button == device_Button) {pagesWidget->setCurrentWidget(Device); /*Device->repaint();*/}
    if(button == preference_Button) {pagesWidget->setCurrentWidget(Settings); /*Settings->repaint();*/}
    if(button == analysis_Button) {pagesWidget->setCurrentWidget(Analysis); /*Analysis->repaint();*/}
    if(button == protocol_Button) {pagesWidget->setCurrentWidget(Protocol); /*Protocol->repaint();*/}


    // Dev_Buttons ...
    /*Dev_Buttons->button(4)->setDisabled(false);


    if(button == device_Button)
    {
        Dev_Buttons->button(0)->setDisabled(false);
        Dev_Buttons->button(0)->setText(tr("Open"));
        connect(Dev_0, SIGNAL(clicked(bool)), Device, SLOT(slot_OpenBlock()));
        Dev_Buttons->button(1)->setDisabled(false);
        Dev_Buttons->button(1)->setText(tr("Close"));
        connect(Dev_1, SIGNAL(clicked(bool)), Device, SLOT(slot_CloseBlock()));
    }*/

    int sub_w = 0;

    if(pagesWidget->currentIndex() == 1)    // Device
    {
        if(Device->Dev_State >= sRun)   // Run
        {
            sub_w = 2;
        }
        else                            // Nothing
        {
            if(Device->flag_Compatibility) sub_w = 1;
            else sub_w = 0;
        }
    }

    slot_RejimeDevButtons(pagesWidget->currentIndex(), sub_w);

    pagesWidget->repaint();   

}
//-----------------------------------------------------------------------------
//--- slot_PressDevButtons(int key)
//-----------------------------------------------------------------------------
void Main_RT::slot_PressDevButtons(int key)
{
    int h = 0;
    int H = 40;
    int k = 3;
    int state;


    if(key >= 0x1000030 && key <= 0x1000033)
    {
        if(!splash_screen->isHidden())
        {
            qDebug() << "splash_screen->isHidden(): ";
            Device->slot_RequestExit(2);
            splash_screen->hide();
        }

        if(buttons_DeviceGroup->height() == 0)
        {
            while(k>0)
            {
                //Sleep(1);
                h += 17;
                buttons_DeviceGroup->setFixedHeight(h);
                group_PB->setFixedHeight(H+h);
                update();
                qApp->processEvents();
                k--;
            }

            timer_DevButtons->start(10000);
        }
        else
        {
            qDebug() << " event for Button:" << key - 0x1000030;
            timer_DevButtons->stop();
            timer_DevButtons->start(10000);

            key = key - 0x1000030;
            QAbstractButton *b = Dev_Buttons->button(key);
            if(b)
            {
                if(b->isEnabled())
                {
                    b->setDown(true);
                    b->repaint();
                    qApp->processEvents();
                    b->setFocus();
                    b->click();
                    Sleep(100);
                    b->setDown(false);
                    b->repaint();
                    qApp->processEvents();
                }
            }

            //if(key == 1)  Protocol->Open_Pro->animateClick(1000);
        }

    }
}
//-----------------------------------------------------------------------------
//--- slot_PressDevButtons(int key)
//-----------------------------------------------------------------------------
void Main_RT::slot_RejimeDevButtons(int page, int sub_w)
{
    int i;
    int count = Dev_Buttons->buttons().size();

    qDebug() << "slot_RejimeDevButtons: " << page << sub_w;

    // 1. Clear...
    foreach(QAbstractButton *b, Dev_Buttons->buttons())
    {
        b->setDisabled(true);
        b->setText("");
        b->disconnect();
        //disconnect(b,0,0,0);
        b->setIcon(QIcon());
    }
    Dev_Buttons->button(4)->setDisabled(false);
    Dev_Buttons->button(4)->setIcon(QIcon(":/images/shutdown.png"));
    Dev_Buttons->button(4)->setIconSize(QSize(22,22));

    switch(page)    
    {
    case 0:                     // Protocol

                switch(sub_w)
                {
                default:    break;

                case 0:
                            Dev_0->setDisabled(false);
                            Dev_0->setIcon(QIcon(":/images/clear_flat_16.png"));
                            connect(Dev_0, SIGNAL(clicked(bool)), Protocol, SLOT(clear_Protocol()));
                            Dev_1->setDisabled(false);
                            Dev_1->setIcon(QIcon(":/images/open_flat.png"));
                            connect(Dev_1, SIGNAL(clicked(bool)), Protocol, SLOT(open_Manually()));
                            break;

                case 1:                             // Choice_Type
                            for(i=0; i<4; i++) Dev_Buttons->button(i)->setDisabled(false);
                            Dev_0->setIcon(QIcon(":/images/www-48.png"));
                            Dev_1->setIcon(QIcon(":/images/usb_48.png"));
                            Dev_2->setIcon(QIcon(":/images/local_disk-48.png"));
                            Dev_3->setIcon(QIcon(":/images/back.png"));

                            connect(Dev_0, SIGNAL(clicked(bool)), Protocol->Choice_Type->Ethernet_Button, SLOT(click()));
                            connect(Dev_1, SIGNAL(clicked(bool)), Protocol->Choice_Type->USB_Button, SLOT(click()));
                            connect(Dev_2, SIGNAL(clicked(bool)), Protocol->Choice_Type->Local_Button, SLOT(click()));
                            connect(Dev_3, SIGNAL(clicked(bool)), Protocol->Choice_Type->cancel_Button, SLOT(click()));
                            break;

                case 2:                             // Protocol_List
                            for(i=0; i<4; i++) Dev_Buttons->button(i)->setDisabled(false);

                            Dev_0->setIcon(QIcon(":/images/UP.png"));
                            Dev_1->setIcon(QIcon(":/images/DOWN.png"));
                            Dev_2->setText(tr("Apply"));
                            Dev_3->setText(tr("Cancel"));
                            connect(Dev_0, SIGNAL(clicked(bool)), Protocol->List_Protocols, SLOT(Up_CurrentItem()));
                            connect(Dev_1, SIGNAL(clicked(bool)), Protocol->List_Protocols, SLOT(Down_CurrentItem()));
                            connect(Dev_2, SIGNAL(clicked(bool)), Protocol->List_Protocols->apply_Button, SLOT(click()));
                            connect(Dev_3, SIGNAL(clicked(bool)), Protocol->List_Protocols->cancel_Button, SLOT(click()));
                            break;
                }

                break;

    case 1:                     // Device

                switch(sub_w)
                {
                default:        break;

                case 1:         // Nothing, with Protocol
                            Dev_0->setDisabled(false);
                            Dev_0->setIcon(QIcon(":/images/start_1.png"));
                            connect(Dev_0, SIGNAL(clicked(bool)), Device, SLOT(slot_CheckExpozition_BeforeRun()));

                case 0:         // Nothing, No Protocol
                            Dev_2->setDisabled(false);
                            Dev_2->setIcon(QIcon(":/images/open_block.png"));
                            connect(Dev_2, SIGNAL(clicked(bool)), Device, SLOT(slot_OpenBlock()));
                            Dev_3->setDisabled(false);
                            Dev_3->setIcon(QIcon(":/images/close_block.png"));
                            connect(Dev_3, SIGNAL(clicked(bool)), Device, SLOT(slot_CloseBlock()));

                            break;

                case 2:         // Run

                            Dev_1->setDisabled(false);
                            Dev_1->setIcon(QIcon(":/images/stop_1.png"));
                            connect(Dev_1, SIGNAL(clicked(bool)), Device, SLOT(slot_Stop()));
                            break;
                }

                break;

    case 2:                     // Analysis
                switch(sub_w)
                {
                default:    break;

                case 0:
                            Dev_0->setDisabled(false);
                            Dev_0->setIcon(QIcon(":/images/clear_flat_16.png"));
                            connect(Dev_0, SIGNAL(clicked(bool)), Analysis, SLOT(clear_Protocol()));
                            Dev_1->setDisabled(false);
                            Dev_1->setIcon(QIcon(":/images/open_flat.png"));
                            connect(Dev_1, SIGNAL(clicked(bool)), Analysis, SLOT(open_Manually()));
                            Dev_2->setDisabled(false);
                            Dev_2->setIcon(QIcon(":/images/save_flat.png"));
                            connect(Dev_2, SIGNAL(clicked(bool)), Analysis, SLOT(save_Manually()));
                            break;

                case 1:             // Choice_Type: Open
                            for(i=1; i<4; i++) Dev_Buttons->button(i)->setDisabled(false);
                            //Dev_0->setIcon(QIcon(":/images/www-48.png"));
                            Dev_1->setIcon(QIcon(":/images/usb_48.png"));
                            Dev_2->setIcon(QIcon(":/images/local_disk-48.png"));
                            Dev_3->setIcon(QIcon(":/images/back.png"));

                            //connect(Dev_0, SIGNAL(clicked(bool)), Analysis->Choice_Type->Ethernet_Button, SLOT(click()));
                            connect(Dev_1, SIGNAL(clicked(bool)), Analysis->Choice_Type->USB_Button, SLOT(click()));
                            connect(Dev_2, SIGNAL(clicked(bool)), Analysis->Choice_Type->Local_Button, SLOT(click()));
                            connect(Dev_3, SIGNAL(clicked(bool)), Analysis->Choice_Type->cancel_Button, SLOT(click()));

                            break;

                case 3:             // Choice_Type: Save
                            for(i=0; i<4; i++) {if(i==2) continue;  Dev_Buttons->button(i)->setDisabled(false);}
                            Dev_0->setIcon(QIcon(":/images/www-48.png"));
                            Dev_1->setIcon(QIcon(":/images/usb_48.png"));
                            //Dev_2->setIcon(QIcon(":/images/local_disk-48.png"));
                            Dev_3->setIcon(QIcon(":/images/back.png"));

                            connect(Dev_0, SIGNAL(clicked(bool)), Analysis->Choice_Type->Ethernet_Button, SLOT(click()));
                            connect(Dev_1, SIGNAL(clicked(bool)), Analysis->Choice_Type->USB_Button, SLOT(click()));
                            //connect(Dev_2, SIGNAL(clicked(bool)), Analysis->Choice_Type->Local_Button, SLOT(click()));
                            connect(Dev_3, SIGNAL(clicked(bool)), Analysis->Choice_Type->cancel_Button, SLOT(click()));

                            break;

                case 2:                             // Protocol_List
                            for(i=0; i<4; i++) Dev_Buttons->button(i)->setDisabled(false);

                            Dev_0->setIcon(QIcon(":/images/UP.png"));
                            Dev_1->setIcon(QIcon(":/images/DOWN.png"));
                            Dev_2->setText(tr("Apply"));
                            Dev_3->setText(tr("Cancel"));
                            connect(Dev_0, SIGNAL(clicked(bool)), Analysis->List_Protocols, SLOT(Up_CurrentItem()));
                            connect(Dev_1, SIGNAL(clicked(bool)), Analysis->List_Protocols, SLOT(Down_CurrentItem()));
                            connect(Dev_2, SIGNAL(clicked(bool)), Analysis->List_Protocols->apply_Button, SLOT(click()));
                            connect(Dev_3, SIGNAL(clicked(bool)), Analysis->List_Protocols->cancel_Button, SLOT(click()));
                            break;
                }

                break;

    default:    break;
    }

    // icons size ...
    foreach(QAbstractButton *b, Dev_Buttons->buttons())
    {
        b->setIconSize(QSize(22,22));
        b->update();
        qApp->processEvents();
    }

    buttons_DeviceGroup->setFocus();

    // repaint...
    buttons_DeviceGroup->repaint();
    buttons_DeviceGroup->update();
    pagesWidget->repaint();
    qApp->processEvents();

}
//-----------------------------------------------------------------------------
//--- TempTimer()
//-----------------------------------------------------------------------------
void Main_RT::TempTimer()
{
    //QTimer::singleShot(1000, Protocol, SLOT(open_Manually()));
    //emit sProtocolOpen();
}

//-----------------------------------------------------------------------------
//--- slot_RequestProtocol(QString barcode)
//-----------------------------------------------------------------------------
void Main_RT::slot_RequestProtocol(QString barcode)
{
    protocol_Button->click();
    //Protocol->protocol_Label->setText(QString("BarCode: %1").arg(barcode));
}
//-----------------------------------------------------------------------------
//--- slot_ChangeStateDevice(int state)
//-----------------------------------------------------------------------------
void Main_RT::slot_ChangeStateDevice(int state)
{
    if(state > 0)
    {
        rejime_label->setVisible(true);
        rejime_gif->start();
    }
    else
    {
        rejime_label->setVisible(false);
        rejime_gif->stop();
    }
}
//-----------------------------------------------------------------------------
//--- slot_ChangeSocketState
//-----------------------------------------------------------------------------
void Main_RT::slot_ChangeSocketState(bool state)
{
    socket_State->setVisible(state);
}

//-----------------------------------------------------------------------------
//--- slot_ChangeLink
//-----------------------------------------------------------------------------
void Main_RT::slot_ChangeLink(int link)
{
    if(link == 3) type_Connection->setPixmap(QIcon(":/images/Ethernet_1.png").pixmap(32,32));
    if(link == 4) type_Connection->setPixmap(QIcon(":/images/USB-32.png").pixmap(32,32));

    type_Connection->repaint();


    //splash = new SplashScreen(qApp, this, 1);
    //splash->show();

}

//-----------------------------------------------------------------------------
//--- slot_ChangePage
//-----------------------------------------------------------------------------
void Main_RT::slot_ChangePage(int page)
{
    switch(page)
    {
    case 0:     protocol_Button->click();   break;
    case 1:     device_Button->click();     break;
    case 2:     analysis_Button->click();   break;
    case 3:     preference_Button->click(); break;
    default:    break;
    }
}
//-----------------------------------------------------------------------------
//--- slot_PrintScreen()
//-----------------------------------------------------------------------------
void Main_RT::slot_PrintScreen()
{
    QString fn_req = qApp->applicationDirPath() + "/ramdisk/ps.req";
    QString fn_prscr = qApp->applicationDirPath() + "/prscr/" + QDateTime::currentDateTime().toString("ddMMyy_hhmmss") + ".jpg";

    QFile file(fn_req);
    if(file.exists())
    {
        if(file.remove())
        {
            QScreen *screen = QGuiApplication::primaryScreen();
            if(screen)
            {
                QPixmap originalPixmap = screen->grabWindow(0);
                originalPixmap.save(fn_prscr, "JPG");
            }
        }
    }


    //QPixmap screen = QPixmap::grabWindow(QApplication::desktop()->winId());
    //

    /*QFile file(fn_prscr);
    if(file.open(QIODevice::WriteOnly))
    {
        //QTextStream(&file) << doc.toString();
        file.close();

    }*/
}

//-----------------------------------------------------------------------------
//--- slot_EnableButtonExit(bool state)
//-----------------------------------------------------------------------------
void Main_RT::slot_EnableButtonExit(bool state)
{
    exit_Button->setDisabled(state);
}

//-----------------------------------------------------------------------------
//--- slot_Exit()
//-----------------------------------------------------------------------------
void Main_RT::slot_Exit()
{
    //EXIT = new Exit_Dialog(this);
    EXIT->exec();

    //delete EXIT;

    emit sExit_next();

}
//-----------------------------------------------------------------------------
//--- slot_Exit_next()
//-----------------------------------------------------------------------------
void Main_RT::slot_Exit_next()
{
    QString sys_message = "";

    if(exit_status == 0) // ShutDown
    {
        message_main->setStandardButtons(QMessageBox::Yes| QMessageBox::Cancel);
        message_main->setIcon(QMessageBox::Question);
        message_main->setText(tr("Attention! Do you want to off the device?"));
        if(message_main->exec() == QMessageBox::Cancel)
        {
            exit_status = 2;
        }
    }
    if(exit_status == 5)    // Restart
    {
        label_Attention->setText(tr("Attention! Your device will restart..."));
    }

    if(exit_status == 0 || exit_status == 5)
    {

        MainGroupBox->setVisible(false);
        main_ToolBar->setVisible(false);
        statusBar()->setVisible(false);

        label_Attention->setVisible(true);
        slot_ChangePage(1);
        repaint();
        qApp->processEvents();
    }

    emit sExit(exit_status);

    if(exit_status == 0 || exit_status == 5) QThread::msleep(1000);
    qApp->processEvents();

    QFile file("/mnt/ramdisk/ctrl.req");

    switch(exit_status)
    {
    case 0:     sys_message = "SHTD";
    case 5:     if(sys_message.isEmpty()) sys_message = "RSTS";

                if(file.open(QIODevice::WriteOnly))
                {
                    file.write(sys_message.toLatin1().data());
                    file.close();
                }
                break;

    case 1:
                //SplashScreen *splash_screen = new SplashScreen(qApp);
                splash_screen->show();
                break;

    case 2:     break;

    default:    break;
    }
}
//-----------------------------------------------------------------------------
//--- slot_UpdateSoftware()
//-----------------------------------------------------------------------------
void Main_RT::slot_UpdateSoftware()
{
    label_Attention->setText(tr("Attention! Your software will be update..."));
    MainGroupBox->setVisible(false);
    main_ToolBar->setVisible(false);
    statusBar()->setVisible(false);

    label_Attention->setVisible(true);
    slot_ChangePage(1);
    repaint();
    qApp->processEvents();

}

//-----------------------------------------------------------------------------
//--- wait_process
//-----------------------------------------------------------------------------
void Main_RT::wait_process(Wait_state w_st, int msec, QString label)
{
    QThread* thread = new QThread;
    Worker_wait *woker = new Worker_wait(w_st, label);
    QTimer *timer_wait = new QTimer;
    timer_wait->setInterval(msec);
    QTimer *timer_critical = new QTimer;

    if(w_st == wClose || w_st == wOpen) timer_critical->setInterval(60000);
    else timer_critical->setInterval(15000);

    woker->moveToThread(thread);

    connect(timer_wait, SIGNAL(timeout()), woker, SLOT(slot_timeout()));
    connect(thread, SIGNAL(started()), timer_wait, SLOT(start()));
    connect(this, SIGNAL(finished_WaitProcess()), timer_wait, SLOT(stop()));

    connect(thread, SIGNAL(started()), timer_critical, SLOT(start()));
    connect(this, SIGNAL(finished_WaitProcess()), timer_critical, SLOT(stop()));
    connect(timer_critical, SIGNAL(timeout()), this, SLOT(slot_Finishing_WaitProcess()));

    //connect(woker, SIGNAL(cursor_wait(bool)), this, SLOT(slot_CursorWait(bool)));
    connect(thread, SIGNAL(started()), woker, SLOT(start_process()));
    connect(woker, SIGNAL(display_process(int,QString)),
            this, SLOT(slot_DisplayProcess(int,QString)));
    connect(this, SIGNAL(finished_WaitProcess()), woker, SLOT(stop_process()));
    connect(woker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(woker, SIGNAL(finished()), woker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), timer_wait, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), timer_critical, SLOT(deleteLater()));

    thread->start();
}
//-----------------------------------------------------------------------------
//--- slot_DisplayProcess
//-----------------------------------------------------------------------------
void Main_RT::slot_DisplayProcess(int percent, QString text)
{
    main_Progress->setValue(percent);
    PrBar_status->setText(text);
    PrBar_status->setMinimumSize(PrBar_status->sizeHint());
    main_Progress->repaint();
    qApp->processEvents();
}
//-----------------------------------------------------------------------------
//--- slot_RunStart()
//-----------------------------------------------------------------------------
void Main_RT::slot_RunStart()
{
    main_Progress->setStyleSheet("QProgressBar::chunk:horizontal "
                                 "{background: qlineargradient(x1: 0, y1: 0.1, x2: 1, y2: 0.1, stop: 0 #FFC4C4, stop: 1 red);}");
}
//-----------------------------------------------------------------------------
//--- slot_RunStop()
//-----------------------------------------------------------------------------
void Main_RT::slot_RunStop()
{        
    slot_DisplayProcess(0, "");
    main_Progress->setStyleSheet("QProgressBar::chunk:horizontal "
                                 "{background: qlineargradient(x1: 0, y1: 0.1, x2: 1, y2: 0.1, stop: 0 #B5D8E6, stop: 1 #409BBD);}");
}
//-----------------------------------------------------------------------------
//--- slot_Finishing_WaitProcess()
//-----------------------------------------------------------------------------
void Main_RT::slot_Finishing_WaitProcess()
{
    emit finished_WaitProcess();    
    qApp->processEvents();

    QTimer::singleShot(200, this, SLOT(repaint()));
}

//-----------------------------------------------------------------------------
//--- slot_AnswerRequest(QString message)
//-----------------------------------------------------------------------------
void Main_RT::slot_AnswerRequest(QString message)
{
    if(message.isEmpty()) return;

    qDebug() << "slot_AnswerRequest: " << message;

    QVariant returned_Value = NULL;
    QVariant answer = message;
    QVariant id = "...";

    QObject *obj = (QObject*)(pweb->rootObject());
    QMetaObject::invokeMethod(obj, "send_StateProtocolToWeb",
                                  Q_RETURN_ARG(QVariant, returned_Value),
                                  Q_ARG(QVariant, id),
                                  Q_ARG(QVariant, answer));
}

//-----------------------------------------------------------------------------
//--- slot_ChInt() SSE
//-----------------------------------------------------------------------------
/*void Main_RT::slot_ChInt(bool)
{
  qDebug()<<"mouse click bool";
}
void Main_RT::slot_ChInt(int)
{
  qDebug()<<"mouse click int";
}*/

/*bool Main_RT::event(QEvent *event)
{
  if(event->type()==QEvent::MouseButtonRelease ){
    sleepInterval=0;
  }
  return QWidget::event(event);
}*/

//-------------------------------------------------------------------------------
//--- Web_Interface()
//-------------------------------------------------------------------------------
Web_Interface::Web_Interface(QWidget *parent)
    :QObject(parent)
{
    connection_Server = false;

    connect(this, SIGNAL(connection_Changed(bool)), this, SLOT(change_connection(bool)));
}
//-------------------------------------------------------------------------------
//--- ~Web_Interface()
//-------------------------------------------------------------------------------
Web_Interface::~Web_Interface()
{

}
//-------------------------------------------------------------------------------
//--- get_connection()
//-------------------------------------------------------------------------------
bool Web_Interface::get_connection() const
{
    //qDebug() << "get_connection: " << connection_Server;
    return(connection_Server);
}
//-------------------------------------------------------------------------------
//--- set_connection(const bool&)
//-------------------------------------------------------------------------------
void Web_Interface::set_connection(const bool& state)
{
    //qDebug() << "set_connection: " << state;
    connection_Server = state;

    emit connection_Changed(state);
}
//-------------------------------------------------------------------------------
//--- set_url(const QString&)
//-------------------------------------------------------------------------------
void Web_Interface::set_url(const QString& url)
{
    //url_Server = url;
}
//-------------------------------------------------------------------------------
//--- set_connection(const bool&)
//-------------------------------------------------------------------------------
void Web_Interface::change_connection(bool state)
{
    //qDebug() << "change connection: " << state;
    emit change_SocketState(state);
    if(!state)
    {
        get_ListProtocols("","");
    }
}

//-------------------------------------------------------------------------------
//--- get_ListProtocols(QString,QString)
//-------------------------------------------------------------------------------
void Web_Interface::get_ListProtocols(QString str, QString separator)
{
    int i;
    QString text;
    QStringList list_param;
    QStringList list = str.split(separator);
    if(str.isEmpty()) list.clear();

    //qDebug() << "str, separator: " << str << separator;

    list_Protocols.clear();
    for(i=0; i<list.size(); i++)
    {
        text = list.at(i);
        list_param = text.split(";");
        if(list_param.size() >= 3)
        {
            text = QString("%1;%2").arg(list_param.at(2)).arg(list_param.at(1));
            list_Protocols.insert(list_param.at(0), text);
        }
    }
    emit listProtocols_Changed();

    qDebug() << "List: " << list_Protocols;
}
//-------------------------------------------------------------------------------
//--- get_ListCompleted(QString,QString)
//-------------------------------------------------------------------------------
void Web_Interface::get_ListCompleted(QString str, QString separator)
{
    int i;
    QString text;
    QStringList list_param;
    QStringList list = str.split(separator);
    if(str.isEmpty()) list.clear();

    list_ProtocolsCompleted.clear();
    for(i=0; i<list.size(); i++)
    {
        text = list.at(i);
        list_param = text.split(";");
        if(list_param.size() >= 3)
        {
            text = QString("%1;%2").arg(list_param.at(2)).arg(list_param.at(1));
            list_ProtocolsCompleted.insert(list_param.at(0), text);
        }
    }
    qDebug() << "List Completed: " << list_ProtocolsCompleted;
}

//-------------------------------------------------------------------------------
//--- get_Message(QString message)
//-------------------------------------------------------------------------------
void Web_Interface::get_Message(QString message)
{
    emit message_FromServer(message);
}
//-------------------------------------------------------------------------------
//--- send_Message(QString message)
//-------------------------------------------------------------------------------
void Web_Interface::send_Message(QString message)
{
    emit message_ToServer(message);
}
//-------------------------------------------------------------------------------
//--- get_Protocol(QString str)
//-------------------------------------------------------------------------------
void Web_Interface::get_Protocol(QString str)
{
    QString text = "";
    QFile file;

    if(str.length())
    {
        //text = str.mid(0,200);

        if(text.contains("<create_plate"))
        {
            file.setFileName(qApp->applicationDirPath() +  "/qml/web7.xml");
        }
        else
        {
            file.setFileName(qApp->applicationDirPath() +  "/qml/web.rt");
        }

        //qDebug() << "text: " << text.toUtf8();
        //qDebug() << "fn: " << file.fileName();

        qDebug() << "get_Protocol: (size): " << str.size();

        if(file.open(QIODevice::WriteOnly))
        {
            QTextStream out(&file);
            out.setCodec("UTF-8");

            out << str.toUtf8();
            file.close();

            emit send_ProtocolToSetup(file.fileName(), true);
            //emit send_ProtocolToScenario(file.fileName());
        }
       //else

    }
}
//-------------------------------------------------------------------------------
//--- exec_Command(QString message)
//-------------------------------------------------------------------------------
void Web_Interface::exec_Command(QString message)
{
    QDomDocument doc;
    QDomElement  request;
    QDomElement  element;
    QDomElement  item;
    QMap<QString,QString> map;

    QString fn, param;
    QString answer = "";

    param = "";


    if(doc.setContent(message))
        {
            request = doc.documentElement();
            element = request.firstChildElement("name_request");

            while(1)
            {
                // OPEN_BLOCK
                if(!element.isNull() && element.text() == OPENBLOCK_REQUEST)
                {                    
                    answer = element.text();
                    break;
                }

                //CLOSE_BLOCK
                if(!element.isNull() && element.text() == CLOSEBLOCK_REQUEST)
                {                    
                    answer = element.text();
                    break;
                }

                break;
            }



            // answer...
            if(!answer.isEmpty())
            {
                // 1. answer for request...
                doc.clear();
                QDomNode xmlNode = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"");
                doc.insertBefore(xmlNode, doc.firstChild());
                QDomElement  root = doc.createElement("answer_request");
                doc.appendChild(root);
                root.appendChild(MakeElement(doc,answer,"0"));

                emit AnswerRequest_ToServer(doc.toString());

                // 2.
                emit send_ExecCommand(answer);
            }

            doc.clear();



        }


    //qDebug() << "exec_Command: " << message;
}
