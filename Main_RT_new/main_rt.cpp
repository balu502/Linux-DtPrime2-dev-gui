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
                "QPushButton::enabled {background-color: #FAFAFA;}"
                "QPushButton::focused {background-color: #FAFAFA;}"
                "QPushButton::pressed {background-color: #ccc;}"
                "QPushButton::checked {background-color: #999;}"
                "QPushButton {text-align: center;}"
                "QPushButton {min-width: 2.5em; margin:1; padding:5;}"
                "QPushButton {border: 1px solid #777; border-radius: 0px;}"
                "QPushButton#Transparent {border: 0px solid #aaa; min-width: 1em; margin:0; padding: 2;}"
                "QListWidget {background-color: #ffffff; selection-background-color: #d7d7ff; selection-color: black;}"
                "QComboBox {background-color: #ffffff; selection-background-color: #d7d7ff; selection-color: black;}"
                "QComboBox::down-arrow {image: url(:/images/down_arrow_width.png);}"
                "QComboBox::down-arrow:on {top: 1px; left: 1px;}"
                "QComboBox::drop-down {subcontrol-origin: padding; subcontrol-position: top right; width: 30px; background-color: #ffffff; border: 1px solid #777; min-width: 30px;}"
                "QStatusBar {background: #FAFAFA; border: 1px solid #ddd;}"
                "QTabBar::tab:!selected {background: #FAFAFA; border: 1px solid #777; border-radius: 2px;}"
                "QTabBar::tab:selected {background: #999; border: 1px solid #777; border-radius: 2px;}"
                "QMessageBox QPushButton {border: 1px solid #111; color: black; background-color: #FAFAFA;}"
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

    //...WEB...
    Web = new Web_Interface(this);
    pweb = new QQuickWidget(this);
    pweb->rootContext()->setContextProperty("Web", Web);
    pweb->setSource(QUrl::fromLocalFile(qApp->applicationDirPath() + "/qml/web_5jul.qml"));

    connect(Web, SIGNAL(send_ProtocolToSetup(QString)), Protocol, SLOT(load_fromXML(QString)));


    Protocol->list_protocols = &Web->list_Protocols;
    Analysis->list_protocolsCompleted = &Web->list_ProtocolsCompleted;
    Protocol->pweb = pweb;
    Analysis->pweb = pweb;
    //pweb->show();

    message_main = new QMessageBox(this);
    label_Attention = new QLabel("Do not turn off the power of the device before the end of the program...", this);
    label_Attention->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label_Attention->setAlignment(Qt::AlignCenter);
    label_Attention->setStyleSheet("QLabel{border: 1px solid #111; background-color: white; color: red};");
    label_Attention->setFixedWidth(700);
    label_Attention->move(50,220);
    label_Attention->setVisible(false);

    EXIT = new Exit_Dialog(this);
    EXIT->setVisible(false);



}
//-----------------------------------------------------------------------------
//--- ~Main_RT()
//-----------------------------------------------------------------------------
Main_RT::~Main_RT()
{
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
    //delete statusBar_widget;
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
    QString dir_SysTranslate = qApp->applicationDirPath() + "/translations/ru";

    if(qt_translator.load("qt_ru.qm", dir_SysTranslate)) qDebug() << "qt_translator - ok!";
    qApp->installTranslator(&qt_translator);

    translator.load(":/translations/ru.qm");    
    qApp->installTranslator(&translator);

    // Read web_settings
    read_WebSettings(qApp->applicationDirPath() + "/settings/settings.xml");

}
//-----------------------------------------------------------------------------
//--- readsettings()
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

        Web_Parameters << ip << port;
        qDebug() << "ip,port: " << ip << port;
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

    splash_screen = new SplashScreen(qApp);
    splash_screen->hide();

    Device->Prot = Protocol->Prot;

    connect(Device, SIGNAL(sChangePage(int)), this, SLOT(slot_ChangePage(int)));
    connect(Device, SIGNAL(sChangeStateDevice(int)), Protocol, SLOT(slot_ChangeStateDevice(int)));
    connect(Device, SIGNAL(sChangeStateDevice(int)), this, SLOT(slot_ChangeStateDevice(int)));
    connect(Device, SIGNAL(sSendLogData(QString)), Settings, SLOT(GetLogData(QString)));
    //connect(Device, SIGNAL(sRequestProtocol(QString)), this, SLOT(slot_RequestProtocol(QString)));
    connect(Device, SIGNAL(sRequestProtocol(QString)), Protocol, SLOT(find_Protocol(QString)));
    connect(Protocol, SIGNAL(sStatusProtocol(QString)), Device, SLOT(slot_StatusProtocol(QString)));
    connect(this, SIGNAL(sExit(int)), Device, SLOT(slot_RequestExit(int)));
    connect(Settings, SIGNAL(changeLink(int)), Device, SLOT(slot_RequestExit(int)));
    connect(splash_screen, SIGNAL(s_PowerWakeup(int)), Device, SLOT(slot_RequestExit(int)));
    connect(this, SIGNAL(send_IP(QString)), splash_screen, SLOT(Get_IP(QString)));
    connect(Settings, SIGNAL(changeLink(int)), this, SLOT(slot_ChangeLink(int)));
    connect(Device, SIGNAL(sOpenProtocolAfterRun(QString)), Analysis, SLOT(open_Protocol(QString)));
    connect(Device, SIGNAL(sWait_Process(Wait_state,int,QString)), this, SLOT(wait_process(Wait_state,int,QString)));
    connect(Device, SIGNAL(sFinished_WaitProcess()), this, SLOT(slot_Finishing_WaitProcess()));
    connect(Protocol, SIGNAL(sWait_Process(Wait_state,int,QString)), this, SLOT(wait_process(Wait_state,int,QString)));
    connect(Protocol, SIGNAL(sFinished_WaitProcess()), this, SLOT(slot_Finishing_WaitProcess()));
    connect(Analysis, SIGNAL(sWait_Process(Wait_state,int,QString)), this, SLOT(wait_process(Wait_state,int,QString)));
    connect(Analysis, SIGNAL(sFinished_WaitProcess()), this, SLOT(slot_Finishing_WaitProcess()));

    pagesWidget->addWidget(Protocol);
    pagesWidget->addWidget(Device);
    pagesWidget->addWidget(Analysis);
    pagesWidget->addWidget(Settings);

    //... for Protocol ...
    Protocol->map_InfoDevice = &Device->map_InfoDevice;
    Protocol->Expozition_dev = &Device->Expozition;

    main_layout->addWidget(pagesWidget);

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


    statusBar()->addPermanentWidget(mode_label);    
    statusBar()->addPermanentWidget(main_Progress, 1);
    statusBar()->addPermanentWidget(type_Connection);
    statusBar()->addPermanentWidget(rejime_label);
    //statusBar()->addPermanentWidget(spacer);

    statusBar()->setFixedHeight(40);
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
//--- Slot update_DateTime()
//-----------------------------------------------------------------------------
void Main_RT::update_DateTime()
{
    QString tim = QDateTime::currentDateTime().toString(" d MMMM yyyy, h:mm:ss ");
    mode_label->setText(tim);

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

    qApp->processEvents();

    if(button == device_Button) {pagesWidget->setCurrentWidget(Device); /*Device->repaint();*/}
    if(button == preference_Button) {pagesWidget->setCurrentWidget(Settings); /*Settings->repaint();*/}
    if(button == analysis_Button) {pagesWidget->setCurrentWidget(Analysis); /*Analysis->repaint();*/}
    if(button == protocol_Button) {pagesWidget->setCurrentWidget(Protocol); /*Protocol->repaint();*/}

    pagesWidget->repaint();

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
//--- slot_ChangePage
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
    case 5:     if(sys_message.isEmpty()) sys_message = "RSTP";

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
//--- wait_process
//-----------------------------------------------------------------------------
void Main_RT::wait_process(Wait_state w_st, int msec, QString label)
{
    QThread* thread = new QThread;
    Worker_wait *woker = new Worker_wait(w_st, label);
    QTimer *timer_wait = new QTimer;
    timer_wait->setInterval(msec);

    woker->moveToThread(thread);

    connect(timer_wait, SIGNAL(timeout()), woker, SLOT(slot_timeout()));
    connect(thread, SIGNAL(started()), timer_wait, SLOT(start()));
    connect(this, SIGNAL(finished_WaitProcess()), timer_wait, SLOT(stop()));

    //connect(woker, SIGNAL(cursor_wait(bool)), this, SLOT(slot_CursorWait(bool)));
    connect(thread, SIGNAL(started()), woker, SLOT(start_process()));
    connect(woker, SIGNAL(display_process(int,QString)),
            this, SLOT(slot_DisplayProcess(int,QString)));
    connect(this, SIGNAL(finished_WaitProcess()), woker, SLOT(stop_process()));
    connect(woker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(woker, SIGNAL(finished()), woker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), timer_wait, SLOT(deleteLater()));

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
//--- slot_Finishing_WaitProcess()
//-----------------------------------------------------------------------------
void Main_RT::slot_Finishing_WaitProcess()
{
    emit finished_WaitProcess();    
    qApp->processEvents();

    QTimer::singleShot(200, this, SLOT(repaint()));
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
    qDebug() << "get_connection: " << connection_Server;
    return(connection_Server);
}
//-------------------------------------------------------------------------------
//--- set_connection(const bool&)
//-------------------------------------------------------------------------------
void Web_Interface::set_connection(const bool& state)
{
    qDebug() << "set_connection: " << state;
    connection_Server = state;

    emit connection_Changed(state);
}
//-------------------------------------------------------------------------------
//--- set_url(const QString&)
//-------------------------------------------------------------------------------
void Web_Interface::set_url(const QString& url)
{
    url_Server = url;
}
//-------------------------------------------------------------------------------
//--- set_connection(const bool&)
//-------------------------------------------------------------------------------
void Web_Interface::change_connection(bool state)
{
    qDebug() << "change connection: " << state;
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
    QString text;
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


        if(file.open(QIODevice::WriteOnly))
        {
            QTextStream out(&file);
            out.setCodec("UTF-8");

            out << str.toUtf8();
            file.close();

            emit send_ProtocolToSetup(file.fileName());
            emit send_ProtocolToScenario(file.fileName());
        }
       //else

    }
}
