#include "device_page.h"
#include "device_param.h"
#include "coeff_struct.h"

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Device_page::Device_page(QWidget *parent):  QMainWindow(parent)
{
    int i;

    readsettings();

    DeviceGroupBox = new QGroupBox(this);
    DeviceGroupBox->setObjectName("Transparent");
    setCentralWidget(DeviceGroupBox);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(2);
    QHBoxLayout *dev_layout = new QHBoxLayout();
    DeviceGroupBox->setLayout(layout);

    open_Block = new QPushButton(QIcon(":/images/open_block.png"), "", this);
    close_Block = new QPushButton(QIcon(":/images/close_block.png"), "", this);
    RunDev = new QPushButton(QIcon(":/images/start_1.png"), "", this);
    PauseDev = new QPushButton(QIcon(":/images/pause_1.png"), "", this);
    StopDev = new QPushButton(QIcon(":/images/stop_1.png"), "", this);
    LastRun = new QPushButton(QIcon(":/images/LastRun_48.png"), "", this);
    RunDev->setFixedSize(48,48);
    RunDev->setIconSize(QSize(48,48));
    PauseDev->setFixedSize(48,48);
    PauseDev->setIconSize(QSize(48,48));
    PauseDev->setCheckable(true);
    StopDev->setFixedSize(48,48);
    StopDev->setIconSize(QSize(48,48));
    open_Block->setFixedSize(48,48);
    open_Block->setIconSize(QSize(48,48));
    close_Block->setFixedSize(48,48);
    close_Block->setIconSize(QSize(48,48));
    LastRun->setFixedSize(48,48);
    LastRun->setIconSize(QSize(48,48));

    RunDev->setDisabled(true);
    PauseDev->setDisabled(true);
    StopDev->setDisabled(true);
    open_Block->setDisabled(true);
    close_Block->setDisabled(true);


    QFont label_font("Times New Roman", 24, QFont::Bold);
    //label_font.setItalic(true);
    label_Time = new QLabel("00:00:00", this);
    //label_Time->setStyleSheet("color: darkblue");
    label_Time->setFont(label_font);
    label_Time->setVisible(false);

    dev_layout->addSpacing(50);
    dev_layout->addWidget(RunDev, 0, Qt::AlignLeft);
    dev_layout->addWidget(PauseDev, 0, Qt::AlignLeft);
    dev_layout->addWidget(StopDev, 1, Qt::AlignLeft);

    //dev_layout->addSpacing(35);
    dev_layout->addWidget(LastRun, 0, Qt::AlignLeft);
    dev_layout->addWidget(label_Time, 0, Qt::AlignLeft);

    dev_layout->addWidget(open_Block, 1, Qt::AlignRight);
    dev_layout->addWidget(close_Block, 0, Qt::AlignRight);

    // ... Control ...
    /*Control_Dev = new QGroupBox(this);
    Control_Dev->setObjectName("Transparent");
    QHBoxLayout *control_layout = new QHBoxLayout();
    control_layout->setMargin(0);
    Control_Dev->setLayout(control_layout);
    */

    Tab_Dev = new QTabWidget(this);
    Tab_Dev->setStyleSheet("QTabWidget::tab-bar{alignment: right;}");
    /*Information_Dev = new QGroupBox(this);
    Information_Dev->setFixedWidth(220);
    control_layout->addWidget(Tab_Dev);
    control_layout->addWidget(Information_Dev);
    */

    Temperature_Box = new QGroupBox(this);
    Fluor_Box = new QGroupBox(this);
    //RunTime_Box = new QGroupBox(this);
    Information_Box = new QGroupBox(this);

    // ... Temperature ...
    QHBoxLayout *temperature_layout = new QHBoxLayout();
    Temperature_Box->setLayout(temperature_layout);
    plot_temperature = new GraphTemperaturePlot(this);
    temperature_layout->addWidget(plot_temperature);

    // ... Fluor ...
    QHBoxLayout *fluor_layout = new QHBoxLayout();
    Fluor_Box->setLayout(fluor_layout);
    plot_fluor = new GraphFluorPlot(this);
    fluor_layout->addWidget(plot_fluor);

    // ... Info ...
    QHBoxLayout *devinfo_layout = new QHBoxLayout();
    Information_Box->setLayout(devinfo_layout);
    Info = new Device_Info(this);
    devinfo_layout->addWidget(Info);

    Tab_Dev->addTab(Temperature_Box, QIcon(":/images/Temp_new.png"), ""); //, tr("Temperature"));
    Tab_Dev->addTab(Fluor_Box, QIcon(":/images/Spectrum_new.png"), ""); //, tr("Fluorescence"));
    //Tab_Dev->addTab(RunTime_Box, QIcon(":/images/run_time.png"), ""); //, tr("RunTime"));
    Tab_Dev->addTab(Information_Box, QIcon(":/images/Info.png"), ""); //, tr("Info"));
    Tab_Dev->setIconSize(QSize(48,48)); Tab_Dev->setFont(QFont("Tahoma",11));

    // ... Information ...
    QHBoxLayout *info_layout = new QHBoxLayout();
    info_layout->setSpacing(0);
    //Information_Dev->setLayout(info_layout);
    Device_Name = new QLabel(this);
    Device_Name->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    Device_Name->setAlignment(Qt::AlignCenter);
    Device_Name->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC)};"); //white");
    QFont font_name("Times New Roman", 22, QFont::Bold);
    Device_Name->setFont(font_name);
    Device_Name->setTextFormat(Qt::RichText);
    Device_Name->setFixedWidth(200);
    Protocol_Name = new QLabel(this);
    Protocol_Name->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    Protocol_Name->setAlignment(Qt::AlignCenter);
    Protocol_Name->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC)}"); // rgb(220, 220, 220)}");
    font_name.setPointSize(16);
    Protocol_Name->setFont(font_name);
    Protocol_Name->setTextFormat(Qt::RichText);

    box_Dev = new QWidget(this);
    box_Dev->setFixedSize(1,48);
    info_layout->addWidget(Device_Name);
    info_layout->addWidget(Protocol_Name, 1);
    info_layout->addWidget(box_Dev);

    /*QHBoxLayout *protocol_layout = new QHBoxLayout();
    Status_LoadProtocol = new QLabel(this);
    Status_LoadProtocol->setFixedSize(24,24);
    Status_LoadProtocol->setPixmap(QPixmap(":/images/bad_pro.png"));
    Name_Protocol = new QLabel(tr(" protocol is absent "), this);
    //Name_Protocol->setFrameStyle(QFrame::Panel | QFrame::Plain);
    Name_Protocol->setAlignment(Qt::AlignCenter);
    protocol_layout->setMargin(0);
    protocol_layout->setSpacing(4);
    protocol_layout->addWidget(Status_LoadProtocol);
    protocol_layout->addWidget(Name_Protocol,1);
    */

    /*Temperature_Block = new QLabel(this);
    FN_label = new QLabel(this);
    Temperature_Block->setFont(font_name);
    FN_label->setFont(font_name);
    */

    TIM_state = "";
    prot_Start = QDateTime::currentDateTime();
    for(i=0; i<5; i++) list_Time.append("00:00:00");

    /*
    QFont label_font("Times New Roman", 14, QFont::Bold);
    QFont combo_font("Times New Roman", 12, QFont::Bold);
    QStringList list;
    list << tr("From start") << tr("Till end") << tr("Time of start") << tr("End time") << tr("Current time");
    time_first = new QComboBox(this);
    time_first->addItems(list);
    time_first->setCurrentIndex(0);
    time_first->setFont(combo_font);
    for(int i=0; i < time_first->count(); i++) time_first->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    time_first->setStyleSheet("background-color: white; selection-background-color: #d7d7ff; selection-color: black;");
    label_first = new QLabel("00:00:00", this);
    label_first->setStyleSheet("color: darkblue");
    label_first->setFont(label_font);

    box_first = new QGroupBox(this);
    box_first->setStyleSheet("QGroupBox {border: none;}");
    QHBoxLayout *layout_first = new QHBoxLayout;
    layout_first->setMargin(2);
    box_first->setLayout(layout_first);
    layout_first->addWidget(time_first,0,Qt::AlignLeft);
    layout_first->addWidget(label_first,0,Qt::AlignRight);

    time_second = new QComboBox(this);
    time_second->addItems(list);
    time_second->setCurrentIndex(1);
    time_second->setFont(combo_font);
    for(int i=0; i < time_second->count(); i++) time_second->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    time_second->setStyleSheet("background-color: white; selection-background-color: #d7d7ff; selection-color: black;");
    label_second = new QLabel("00:00:00", this);
    label_second->setStyleSheet("color: darkblue");
    label_second->setFont(label_font);

    box_second = new QGroupBox(this);
    box_second->setStyleSheet("QGroupBox {border: none;}");
    QHBoxLayout *layout_second = new QHBoxLayout;
    layout_second->setMargin(2);
    box_second->setLayout(layout_second);
    layout_second->addWidget(time_second,0,Qt::AlignLeft);
    layout_second->addWidget(label_second,0,Qt::AlignRight);
    */



    //info_layout->addWidget(Device_Name, 0, Qt::AlignTop | Qt::AlignHCenter);
    //info_layout->addLayout(protocol_layout);
    //info_layout->addSpacing(50);

    //info_layout->addWidget(box_first, 0, Qt::AlignTop | Qt::AlignHCenter);
    //info_layout->addWidget(box_second, 1, Qt::AlignTop | Qt::AlignHCenter);

    //info_layout->addWidget(FN_label, 1, Qt::AlignBottom);
    //info_layout->addWidget(Temperature_Block, 0, Qt::AlignBottom);



    //layout->addWidget(Control_Dev,1);

    layout->addLayout(info_layout);
    layout->addSpacing(2);
    layout->addWidget(Tab_Dev, 1);
    layout->addLayout(dev_layout);


    m_nNextBlockSize = 0;
    m_pTcpSocket = new QTcpSocket(this);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
                this,     SLOT(slotError(QAbstractSocket::SocketError)));

    connect(open_Block, SIGNAL(released()), this, SLOT(slot_OpenBlock()));
    connect(close_Block, SIGNAL(released()), this, SLOT(slot_CloseBlock()));
    //connect(RunDev, SIGNAL(released()), this, SLOT(slot_Run()));
    connect(RunDev, SIGNAL(released()), this, SLOT(slot_CheckExpozition_BeforeRun()));
    connect(StopDev, SIGNAL(released()), this, SLOT(slot_Stop()));
    connect(PauseDev, SIGNAL(released()), this, SLOT(slot_Pause()));
    connect(LastRun, SIGNAL(released()), this, SLOT(slot_LastRun()));

    connect(&dev_timer, SIGNAL(timeout()), this, SLOT(slotSendRequestInfo()));
    connect(this, SIGNAL(sDeviceRequest(QMap<QString,QString>*)), this, SLOT(slot_DeviceRequest(QMap<QString,QString>*)));
    connect(this, SIGNAL(sRequestCloseBlock(QMap<QString,QString>*)), this, SLOT(slot_RequestCloseBlock(QMap<QString,QString>*)));
    connect(this, SIGNAL(sRefresh(QMap<QString,QString>*)), plot_temperature, SLOT(slotRefreshData(QMap<QString,QString>*)));
    //connect(this, SIGNAL(sRefresh(QMap<QString,QString>*)), plot_fluor, SLOT(slotRefreshData(QMap<QString,QString>*)));
    connect(this, SIGNAL(sRefreshFluor()), plot_fluor, SLOT(slot_RefreshFluor()));
    connect(this, SIGNAL(sRefresh(QMap<QString,QString>*)), this, SLOT(slot_RefreshMeasure(QMap<QString,QString>*)));
    connect(this, SIGNAL(sChangeStateDevice(int)), plot_temperature, SLOT(slot_ChangeRejime(int)));
    connect(this, SIGNAL(sChangeStateDevice(int)), this, SLOT(slot_ChangeStateDevice(int)));
    connect(this, SIGNAL(sNewProtocol(rt_Protocol*)), plot_fluor, SLOT(slot_NewProtocol(rt_Protocol*)));
    connect(this, SIGNAL(sPause_rejime(int)), plot_temperature, SLOT(slot_ChangeRejime(int)));
    connect(this, SIGNAL(sMeasureTubeHeiht(int)), this, SLOT(slot_MeasuredTubeHeiht(int)));

    //connect(time_first, SIGNAL(currentIndexChanged(int)), this, SLOT(change_FirstTime(int)));
    //connect(time_second, SIGNAL(currentIndexChanged(int)), this, SLOT(change_SecondTime(int)));

    Catalogue_Requests << CATALOGUE;

    //DeviceGroupBox->setDisabled(true);

    //QFont font("Times New Roman", 16, QFont::Bold);
    QFont font("Times New Roman", 16, QFont::Normal); //SSE

    Message = new QMessageBox(this);
    //Message->setWindowIcon(QIcon(":/images/dna_2.ico"));
    //Message->setFont(font);


    //... flags ...
    flag_Compatibility = false;
    flag_SavingResult = false;
    flag_CloseRun = false;
    flag_USB_Rejime = false;
    flag_LastRun = false;
    flag_ChangeExpoBeforeRun = false;

    PWR_State = PWR_WAKEUP;

    Dev_State = sUnknown;
    FN = 0;
    Count_Tubes = 0;

    COEF_EXPO_v4 = 0.154;

    connect_Device();

}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Device_page::~Device_page()
{
    dev_timer.stop();
    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        m_pTcpSocket->disconnect();
        m_pTcpSocket->close();
    }

    delete Message;

    delete RunDev;
    delete StopDev;
    delete PauseDev;
    delete open_Block;
    delete close_Block;
    delete LastRun;

    delete plot_temperature;
    delete Temperature_Box;

    delete plot_fluor;
    delete Fluor_Box;
    delete Info;

    //delete RunTime_Box;
    //delete Information_Box;

    delete Tab_Dev;

    //delete Status_LoadProtocol;
    delete Device_Name;
    //delete Temperature_Block;
    //delete FN_label;
    //delete time_first;
    //delete label_first;
    //delete box_first;
    //delete time_second;
    //delete label_second;
    //delete box_second;
    //delete Information_Dev;

    //delete Control_Dev;


    delete DeviceGroupBox;

    List_Requests.clear();

}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Device_page::readsettings()
{
    /*translator.load(":/translations/device_page_ru.qm");
    qApp->installTranslator(&translator);*/

    QDomDocument    doc;
    QDomElement     root;
    QString lang = "en";

    QFile file(qApp->applicationDirPath() + "/settings/settings.xml");

    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        if(doc.setContent(&file))
        {
            file.close();

            root = doc.documentElement();
            lang = root.firstChildElement("language").text();
        }
        file.close();
    }

    if(lang == "ru")
    {
       translator.load(":/translations/device_page_ru.qm");
    }
    if(lang == "en")
    {
       translator.load(":/translations/device_page_en.qm");
    }

    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::connect_Device()
{
    QString ip;
    int port;

    port = 9002;
    ip = "127.0.0.1"; //172.18.0.10";


    if(m_pTcpSocket->state() == QAbstractSocket::UnconnectedState)
    {
        m_pTcpSocket->connectToHost(ip, port);
        if(!m_pTcpSocket->waitForConnected()) m_pTcpSocket->connectToHost(ip, port);
    }
    else
    {
        qDebug() << "Unable connect with " << ip << port;
        QTimer::singleShot(3000, this, SLOT(again_connect()));
    }

}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::again_connect()
{
    QString ip;
    int port;

    port = 9002;
    ip = "127.0.0.1"; //172.18.0.10";

    if(m_pTcpSocket->state() == QAbstractSocket::UnconnectedState)
    {
        m_pTcpSocket->connectToHost(ip, port);
        if(!m_pTcpSocket->waitForConnected(1000))
        {

        }
    }

}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slotConnected()
{
    qDebug() << "connect:";

    //DeviceGroupBox->setDisabled(false);
    slotGetInfoDevice();
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(m_pTcpSocket->errorString())
                    );
    qDebug() << strError;
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_Processing_ReadSector(QMap<QString, QString> &map)
{
    int i;

    union
    {
        Device_ParDefault Device_ParamDefault;
        unsigned char byte_buf[512];
    }DEVICE_PAR_DEFAULT;
    QByteArray buf_default;

    QString text;
    QString str_default;
    QString owner = map.value(ID_PARAM,"");

    if(owner == "default")
    {
        Expozition_Def.clear();
        for(i=0; i<COUNT_CH*2; i++) Expozition_Def.append(0);   // initial state

        text = map.value(SECTOR_DATA,"");

        if(!text.isEmpty())
        {
            buf_default = QByteArray::fromBase64(text.toStdString().c_str());

            if(buf_default.size() == 512)
            {
                for(i=0; i<512; i++) DEVICE_PAR_DEFAULT.byte_buf[i] = buf_default.at(i);
                str_default = QString(DEVICE_PAR_DEFAULT.Device_ParamDefault.id_default);

                qDebug() << "slot_Processing_ReadSector: " << str_default;


                if(str_default.contains("default"))
                {
                    Expozition_Def.clear();
                    for(i=0; i<COUNT_CH*2; i++) Expozition_Def.append(DEVICE_PAR_DEFAULT.Device_ParamDefault.Expo_def[i]);
                }
            }
        }
        //qDebug() << "Expozition_Def: " << Expozition_Def;

        //... Insert to Info Device ...
        text = "";
        for(i=0; i<Expozition_Def.size(); i++)
        {
            if(div(i,2).rem) continue;
            if(i) text += ", ";
            text += QString::number(Expozition_Def.at(i));
        }        
        map_InfoDevice.insert("Exposure_Def", text);
        Info->additioanl_info(&map_InfoDevice);

        //... slot_Run
        if(flag_ChangeExpoBeforeRun)
        {
            flag_ChangeExpoBeforeRun = false;
            slot_Run();
        }
    }

}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slotReadyRead()
{
    int index;
    QString text, str;
    QByteArray ba;
    int id;
    int fn;
    bool ok;
    short status;
    QBasicTimer *timer_req;
    QStringList list;
    int value;
    double dvalue;
    bool InfoDev = false;

    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_4_7);

    for(;;)
    {
        if(!m_nNextBlockSize)
        {
            if(m_pTcpSocket->bytesAvailable() < sizeof(quint32)) break;
            in >> m_nNextBlockSize;
        }
        if(m_pTcpSocket->bytesAvailable() < m_nNextBlockSize) break;
        m_nNextBlockSize = 0;


        QString answer;
        in >> answer >> status;

        if(answer != INFO_DATA) qDebug() << "Get Request: " << answer << status;

        if(answer == CONNECT_REQUEST)
        {
            in >> map_temp;
            map_temp.clear();
        }


        if(!List_Requests.contains(answer))     // Event from Device...
        {

            map_Device.clear();
            in >> map_Device;

            if(answer == DEVICE_REQUEST)
            {
                qDebug() << "DEVICE_REQUEST: " << map_Device;
                emit sDeviceRequest(&map_Device);
            }

            break;
        }
        /*
        if(Map_TimerRequest.contains(answer))
        {
            timer_req = Map_TimerRequest.value(answer);
            timer_req->stop();
        }

        //

        create_RequestStatusInfo(answer, status);   // Error Info ->
        */

        index = Catalogue_Requests.indexOf(answer);

        switch(index)
        {
        default:    qDebug() << "default: " << index << answer;
                    emit sFinished_WaitProcess();
                    if(status == 0 && answer == "CONTINUE")
                    {
                        if(!PauseDev->isChecked())
                        {
                            PauseDev->setIcon(QIcon(":/images/pause_1.png"));
                            emit sPause_rejime(1);
                        }
                    }
                    break;

        case 0:             //INFO_DATA

                    map_InfoData.clear();
                    in >> map_InfoData;
                    //qDebug() << "Info: " << status << map_InfoData.value(INFO_isMeasuring, "");
                    if(map_InfoData.isEmpty() || status == 5) break;
                    emit sRefresh(&map_InfoData);                    
                    break;

        case 1:             //INFO_DEVICE
                    map_InfoDevice.clear();
                    in >> map_InfoDevice;
                    qDebug() << "DEVICE: " << status << map_InfoDevice.value(INFODEV_serName, "...");
                    //qDebug() << "DEVICE: " << status << map_InfoDevice;

                    if(map_InfoDevice.isEmpty() || status == 5)
                    {
                        QTimer::singleShot(1000,this,SLOT(slotGetInfoDevice()));
                    }
                    else
                    {
                        slot_RefreshInfoDevice(&map_InfoDevice);
                        if(!dev_timer.isActive()) dev_timer.start(1000);    // reconnect

                        // ReadAllSectors:
                        map_Sector.clear();
                        map_Sector.insert(SECTOR_CMD, QString("PRDS %1").arg(0x418));
                        map_Sector.insert(ID_PARAM, "default");
                        slotSendToServer(SECTORREAD_REQUEST);
                    }
                    break;

        case 2:             //RUN
                    if(status) RunDev->setDisabled(false);
                    prot_Start = QDateTime::currentDateTime();
                    emit sFinished_WaitProcess();
                    break;

        case 3:             //STOP
                    qDebug() << "stop: ";
                    StopDev->setDisabled(false);
                    emit sFinished_WaitProcess();
                    break;

        case 4:             //PAUSE
                    qDebug() << "set Pause:";
                    emit sFinished_WaitProcess();
                    if(PauseDev->isChecked())
                    {
                        PauseDev->setIcon(QIcon(":/images/continue_32.png"));
                        emit sPause_rejime(2);
                    }
                    break;

        case 5:             // MEASURE
                    map_Measure.clear();
                    in >> fn >> map_Measure;
                    qDebug() << "GET MEASURE: " << fn << map_Measure.size();
                    slot_GetMeasure(fn);
                    emit sRefreshFluor();
                    break;

        case 6:             // OPEN
                    open_Block->setEnabled(true);
                    close_Block->setEnabled(true);
                    emit sFinished_WaitProcess();
                    break;
        case 7:             // CLOSE
                    close_Block->setEnabled(true);
                    open_Block->setEnabled(true);
                    emit sFinished_WaitProcess();
                    map_Closed.clear();
                    in >> map_Closed;
                    qDebug() << "CLOSEBLOCK_REQUEST: " << map_Closed;
                    if(!flag_CloseRun) emit sRequestCloseBlock(&map_Closed);

                    if(!status && flag_CloseRun)
                    {
                        slot_Run();
                        flag_CloseRun = false;
                    }

                    /*
                    prot->barcode = map_Closed.value(barcode_name).toStdString();
                    OpenClose_Box->setEnabled(true);

                    if(!status && flag_ClosePrerunRun) slot_PreRUN();
                    if(status && flag_ClosePrerunRun && flag_ActivePoint) PA_Error("Close block Error");

                    if(flag_ActivePoint &&
                       action_event &&
                       action_event->point_action->Unique_Name == GET_BARCODE) PA_BarCode();

                    flag_ClosePrerunRun = false;
                    */

                    break;

        case 10:            // GETPIC_REQUEST
                    emit sFinished_WaitProcess();
                    map_PictureData.clear();
                    in >> map_PictureData;
                    if(map_PictureData.contains(GETPIC_VIDEO)) emit sSendPicture(&map_PictureData);     // Video
                    //qDebug() << "GETPIC_REQUEST: " << map_PictureData;
                    break;
        case 11:            // SAVEPARAM
                    map_SavePar.clear();
                    in >> map_SavePar;
                    qDebug() << "map_SavelPar: " << map_SavePar;
                    emit sFinished_WaitProcess();
                    InfoDev = true;
                    break;

        case 12:            // SECTORREAD_REQUEST
                    map_Sector.clear();
                    in >> map_Sector;
                    //qDebug() << "map_Sector: " << map_Sector;
                    emit sFinished_WaitProcess();

                    slot_Processing_ReadSector(map_Sector);

                    break;

        case 14:            // GETAMPINSIMPLE_REQUEST - usb rejime, info about amp.programm
                    map_InfoUSB.clear();
                    in >> map_InfoUSB;
                    //qDebug() << "GET Info_USB: " << answer << status << map_InfoUSB;
                    slot_InfoUSB(&map_InfoUSB);
                    break;

        case 15:    // HTMEAS_REQUEST
                    if(status == 0) in >> value;
                    else value = -1;
                    emit sFinished_WaitProcess();
                    emit sMeasureTubeHeiht(value);
                    break;


        }

        index = List_Requests.indexOf(answer);
        if(index >= 0) List_Requests.removeAt(index);

        //... continuous data request ...
        if(answer == MEASURE_REQUEST)
        {
            if(fn_dev > FN)
            {
                active_ch = Prot->active_Channels;
                slotSendToServer(MEASURE_REQUEST);
            }
            else
            {
                emit sFinished_WaitProcess();
                //Display_ProgressBar(0,"");
                if(flag_LastRun) slot_ChangeStateDevice(Dev_State);
            }
        }
        //...

        if(InfoDev) slotSendToServer(INFO_DEVICE);
    }
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slotSendToServer(QString request)
{
    qint64 out_byte;
    QBasicTimer *timer_req;
    int interval;

    if(flag_USB_Rejime)
    {
        if(request == MEASURE_REQUEST) return;
    }

    if(List_Requests.contains(RUN_REQUEST)) return; // when RUN_REQUEST is active, ALL other are disabled
    if(List_Requests.contains(MEASURE_REQUEST)) return; // when MEASURE_REQUEST is active, ALL other are disabled
    if(List_Requests.contains(GETPIC_REQUEST)) return;  // when GETPIC_REQUEST is active, ALL other are disabled
    if(List_Requests.contains(SAVEPAR_REQUEST)) return;  // when SAVEPAR_REQUEST is active, ALL other are disabled
    //if(List_Requests.contains(SECTORREAD_REQUEST)) return;  // when SECTORREAD_REQUEST is active, ALL other are disabled
    //if(List_Requests.contains(SECTORWRITE_REQUEST)) return;  // when SECTORREAD_REQUEST is active, ALL other are disabled

    if(request != INFO_DATA) qDebug() << "Send To Server: " << request << List_Requests;

    if(List_Requests.contains(request)) return; //don't get answer on previous request
    else List_Requests.append(request);

    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    out << quint32(0) << request;


    if(request == RUN_REQUEST) out << map_Run;                          // Run

    if(request == MEASURE_REQUEST) out << (FN+1) << active_ch;          // Measure

    if(request == EXECCMD_REQUEST) out << map_CMD;                      // CMD

    if(request == GETPIC_REQUEST) out << map_Picture;                   // Get Picture

    if(request == SAVEPAR_REQUEST) out << map_SavePar;                  // Save Parameters to Device

    if(request == SECTORWRITE_REQUEST) out << map_Sector;               // Write Sector Data
    if(request == SECTORREAD_REQUEST) out << map_Sector;                // Read Sector Data

    if(request == CONTROL_REQUEST) out << map_Exit;                     // Exit request

    if(request == HIGHTUBE_SAVE) out << Tube_Height;                    // Save Tubes Height

    out.device()->seek(0);
    out << quint32(arrBlock.size() - sizeof(quint32));
    out_byte = m_pTcpSocket->write(arrBlock);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_OpenBlock()
{
    qDebug() << "state: " << m_pTcpSocket->state();
    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState &&
       !List_Requests.contains(OPENBLOCK_REQUEST) &&
       !List_Requests.contains(CLOSEBLOCK_REQUEST))
    {
        open_Block->setDisabled(true);
        close_Block->setDisabled(true);
        slotSendToServer(OPENBLOCK_REQUEST);
        emit sWait_Process(wOpen, 100, tr("Open block..."));
    }
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_CloseBlock()
{
    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState &&
       !List_Requests.contains(OPENBLOCK_REQUEST) &&
       !List_Requests.contains(CLOSEBLOCK_REQUEST))
    {
        close_Block->setDisabled(true);
        open_Block->setDisabled(true);
        slotSendToServer(CLOSEBLOCK_REQUEST);
        emit sWait_Process(wClose, 100, tr("Close block..."));
    }
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_GetPicture(int ch, int expo, int ctrl)
{
    map_Picture.clear();
    map_Picture.insert(GETPIC_CHANNEL, QString::number(ch));
    map_Picture.insert(GETPIC_EXP, QString::number(expo));
    map_Picture.insert(GETPIC_CTRL, QString::number(ctrl));

    slotSendToServer(GETPIC_REQUEST);
    emit sWait_Process(wPic, 100, tr("Get Picture..."));
}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_MeasureHeight()
{
    slotSendToServer(HTMEAS_REQUEST);
    emit sWait_Process(wOpen, 100, tr("Measuring the tubes height..."));
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_MeasuredTubeHeiht(int value)
{
    QString text;
    Tube_Height = 0;
    int res = 0;

    if(value < 0)
    {
        Message->setStandardButtons(QMessageBox::Ok);
        Message->setIcon(QMessageBox::Warning);
        text = tr("Attention! Error in measuring of the tube height!");
        Message->setText(text);
        Message->exec();

    }
    else
    {

        text = QString("%1: (h = %2)\r\n%3").arg(tr("Attention! Measurement of the tube height passed successfully"))
                                            .arg(value)
                                            .arg(tr("Do you want to save this value in subsequent runs?"));
        Message->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        Message->setIcon(QMessageBox::Question);
        Message->setText(text);
        res = Message->exec();

        if(res == QMessageBox::Yes)
        {
            Tube_Height = value;
            slotSendToServer(HIGHTUBE_SAVE);
        }
    }
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
bool Device_page::IsExpositionEqual(QVector<quint16> &expo_Protocol)
{
    int i;
    bool state = true;
    int act_ch = Prot->active_Channels;

    double dvalue;
    QVector<quint16> expo_Device;
    quint16 value;

    for(i=0; i<COUNT_CH; i++)
    {
        expo_Device.append(Expozition.at(i*2));
        dvalue = Expozition_Def.at(i*2) * Expozition_Coeff.at(i);
        value = (quint16)dvalue;
        expo_Protocol.append(value);
    }

    i = 0;
    foreach(value, expo_Device)
    {
        if(act_ch & 0xf<<(i*4))
        {
            if(qAbs(value - expo_Protocol.at(i)) > 1)
            {
                state = false;
                break;
            }
        }
        i++;
    }

    qDebug() << "expo_Def: " << state << expo_Device << expo_Protocol;

    expo_Device.clear();

    return(state);
}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_CheckExpozition_BeforeRun()
{
    QString str;
    quint16 value;
    QVector<quint16> expo;

    double coef_expo = (double)(COEF_EXPO);
    if(map_InfoDevice.value("device_hw","").contains("v4.0")) coef_expo = COEF_EXPO_v4;

    if(IsExpositionEqual(expo))
    {
        slot_Run();
    }
    else
    {
        str = "";
        foreach(value, expo)
        {
            value = qRound((double)(value)/coef_expo);
            str += QString(" %1").arg(value);
            value /= COEF_EXPO_1;
            str += QString(" %1").arg(value);
        }
        str = str.trimmed();

        qDebug() << "save_expo: " << str;

        flag_ChangeExpoBeforeRun = true;
        slot_SaveExpo(1, str);
    }

    expo.clear();
}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_Run()
{
    int i;
    QString text = "";
    QString fn_run = qApp->applicationDirPath() + "/device/run.rt";

    if(!flag_Compatibility) return;
    if(!flag_CloseRun && close_Block->isEnabled())  //  before run you need close block
    {
        flag_CloseRun = true;
        close_Block->click();
        return;
    }

    // Clear measure...
    for(i=0; i<Prot->meas.size(); i++) delete Prot->meas.at(i);
    Prot->meas.clear();

    map_Run.clear();

    //qDebug() << "Prot->SerialName: " << Prot->SerialName;
    //qDebug() << "map_InfoDevice: " << map_InfoDevice;

    // 0. Name
    text = Prot->name;
    map_Run.insert(run_name, text);

    // 1. Programm
    text = "";    
    for(i=0; i<Prot->program.size(); i++)
    {
        if(i) text += "\t";
        text += Prot->program.at(i);
    }
    map_Run.insert(run_programm, text);

    // 2. ActiveChannel
    text = QString::number(Prot->active_Channels,16);
    map_Run.insert(run_activechannel, text);

    // 3. ID_Protocol
    text = Prot->regNumber;
    map_Run.insert(run_IDprotocol, text);

    // 4. Operator
    text = Prot->owned_by;
    map_Run.insert(run_operator, text);

    qDebug() << "Map_Run: " << map_Run;

    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        emit sWait_Process(wRun, 100, tr("RUN Loading..."));

        FN = 0;
        plot_fluor->current_fn = 0;
        plot_fluor->Clear_Graph();
        //plot_fluor->current_Fn->setText(QString("Fn = %1").arg(plot_fluor->current_fn));
        plot_fluor->current_Fn->setText("");

        flag_SavingResult = false;

        RunDev->setDisabled(true);
        slotSendToServer(RUN_REQUEST);

        bool sts = SaveAsXML(Prot, fn_run, true);
        if(sts)
        {
            sts = Create_RunProtocol(fn_run);

            qDebug() << "CopyToInput:" << sts;
            CopyToInput(fn_run, Prot);
        }

    }

}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_Stop()
{
    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        emit sWait_Process(wStop, 100, tr("Stopping..."));

        Message->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        Message->setIcon(QMessageBox::Question);
        Message->setText(tr("Attention! Are you stopping a program?"));

        if(Message->exec() == QMessageBox::No)
        {
            emit sFinished_WaitProcess();
            return;
        }

        StopDev->setDisabled(true);
        slotSendToServer(STOP_REQUEST);        
    }
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_Pause()
{
    QString request;
    bool state = PauseDev->isChecked();

    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        emit sWait_Process(wStop, 100, tr("Pause..."));

        if(state)
        {
            request = PAUSE_REQUEST;
        }
        else
        {
            request = CONTINUE_REQUEST;
        }

        slotSendToServer(request);
    }
}
//-----------------------------------------------------------------------------
//--- slot_LastRun()
//-----------------------------------------------------------------------------
void Device_page::slot_LastRun()
{
    emit sLoad_LastRunProtocol();

    if(Prot->program.isEmpty()) return;

    Tab_Dev->setCurrentIndex(1); // Fluor Tab
    emit sWait_Process(wRun, 100, tr("Last RUN..."));

    active_ch = Prot->active_Channels;
    FN = 0;
    flag_LastRun = true;
    slotSendToServer(MEASURE_REQUEST);

    qDebug() << "slot_LastRun(): " << fn_dev << FN;
}

//-----------------------------------------------------------------------------
//--- slotSendRequestInfo (timeOut)
//-----------------------------------------------------------------------------
void Device_page::slotSendRequestInfo()
{
    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        slotSendToServer(INFO_DATA);
    }
}
//-----------------------------------------------------------------------------
//--- slotGetInfoDevice
//-----------------------------------------------------------------------------
void Device_page::slotGetInfoDevice()
{
    //qDebug() << "slotGetInfoDevice(): ";
    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        //qDebug() << "INFO_DEVICE: ";
        slotSendToServer(INFO_DEVICE);
    }
}
//-----------------------------------------------------------------------------
//--- slot_DeviceRequest
//-----------------------------------------------------------------------------
void Device_page::slot_DeviceRequest(QMap<QString, QString> *map)
{
    QString text;

    if(List_Requests.contains(OPENBLOCK_REQUEST) ||
       List_Requests.contains(CLOSEBLOCK_REQUEST)) return;

    // barcode_name
    if(map->keys().contains(barcode_name))
    {
       text = map->value(barcode_name,"").trimmed();
       if(!text.isEmpty())
       {
           emit sChangePage(0);
           emit sRequestProtocol(text);
           close_Block->setDisabled(true);
           slotSendToServer(CLOSEBLOCK_REQUEST);
       }
    }

    // shutdown
    if(map->keys().contains(DEVICES_MSG))
    {
        text = map->value(DEVICES_MSG,"").trimmed();

        if(text == "shutdown")
        {
            qDebug() << "shutdown: " << *map;
            emit sShutDown();
        }
    }
}
//-----------------------------------------------------------------------------
//--- slot_RequestCloseBlock
//-----------------------------------------------------------------------------
void Device_page::slot_RequestCloseBlock(QMap<QString, QString> *map)
{
    // Get BarCode
    int res;

    QString text;

    if(map->keys().contains(barcode_name) && flag_Compatibility && RunDev->isEnabled())
    {
       text = map->value(barcode_name,"").trimmed();
       if(!text.isEmpty())
       {
           barcode = text;
           emit sChangePage(1);

           Message->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
           Message->setDefaultButton(QMessageBox::Yes);
           Message->setIcon(QMessageBox::Question);
           text = tr("Do You want to run the found protocol?");
           Message->setText(text);
           res = Message->exec();
           if(res == QMessageBox::Yes)
           {
               RunDev->click();    // RUN
           }
       }
    }
}
//-----------------------------------------------------------------------------
//--- slot_StatusProtocol
//-----------------------------------------------------------------------------
void Device_page::slot_StatusProtocol(QString status)
{
    bool ok;
    int kod;
    QString text;
    QString icon;

    QStringList list = status.split(";");

    kod = QString(list.at(0)).toInt(&ok);
    if(!ok) kod = 0;
    text = list.at(1);
    //Name_Protocol->setText(text);

    switch(kod)
    {
    default:
    case 0:     //Status_LoadProtocol->setPixmap(QPixmap(":/images/bad_pro.png"));
                icon = ":/images/bad_pro.png";
                Protocol_Name->setText("<img src=" + icon + "> ... " + tr("(No Protocol)"));
                Protocol_Name->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC)}"); //rgb(220, 220, 220)
                Device_Name->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC)};"); //white
                flag_Compatibility = false;
                RunDev->setDisabled(true);
                break;

    case 1:     //Status_LoadProtocol->setPixmap(QPixmap(":/images/ok_pro.png"));
                Protocol_Name->setText(text);
                Protocol_Name->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #C8FFC8, stop: 1 #64FF64)}"); //rgb(128, 255, 128
                Device_Name->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #C8FFC8, stop: 1 #64FF64)}");  // rgb(128, 255, 128
                flag_Compatibility = true;
                RunDev->setDisabled(false);
                if(flag_USB_Rejime && Dev_State > 0)
                {
                    RunDev->setDisabled(true);
                }
                break;
    }


    if(!flag_USB_Rejime) emit sNewProtocol(Prot);

}

//-----------------------------------------------------------------------------
//--- slot_RequestExit(int status)
//-----------------------------------------------------------------------------
void Device_page::slot_RequestExit(int status)
{
    QString value = "";

    switch(status)
    {
    case 0: /*value = PWR_SHUTDOWN;*/   break;
    case 1: value = PWR_STANDBY;    break;
    case 2: value = PWR_WAKEUP;     break;
    case 3: value = INTERFACE_ETH;  break;  //SSE
    case 4: value = INTERFACE_USB;  break;  //SSE
    case 5: break;                           // reset
    default: break;
    }

    if(!value.isEmpty())
    {
        PWR_State = value;
        map_Exit.clear();
        map_Exit.insert(CTRL_STRING, value);
        qDebug() << "map_Exit: " << map_Exit << List_Requests;
        slotSendToServer(CONTROL_REQUEST);

    }
}
//-----------------------------------------------------------------------------
//--- slot_RefreshInfoDevice(QMap<QString, QString> *map)
//-----------------------------------------------------------------------------
void Device_page::slot_RefreshInfoDevice(QMap<QString, QString> *map)
{
    int i;
    quint16 value;
    QString text;
    //QTreeWidgetItem *item;
    QStringList header;
    bool ok;
    header << tr("Parameter") << tr("Value");
    QString B96b = "A5X112,A5X206,A5Y201,A5Y809,A5Z202,A5Z806,A5Z910,A5AN14,A5AN15,A5BN09,A5BD06,A5C113,A5C302,A5CD11,A5CD26";
    QString B96c = "A5X111,A5X207,A5X409,A5Z008,A5A603,A5AN09,A5B730,A5BN01,A5C510,A5CD15,A5CD16";
    QStringList list_B96b = B96b.split(",");
    QStringList list_B96c = B96c.split(",");

    QString name_dev = map->value(INFODEV_serName,"");
    QString mask = map->value(INFODEV_devMask,"");


    //... Load Exposition ...
    Load_Expozition();

    // Load Coefficients
    Load_SpectralCoeff();
    Load_OpticCoeff();
    Load_UnequalCoeff();

    // Load Optical Mask
    Load_Mask();

    //... Information ...
    //Device_Name->setText(name_dev);
    text = ":/images/bad_pro.png";
    Device_Name->setText(name_dev);
    Protocol_Name->setText("<img src=" + text + "> ... " + tr("(No Protocol)"));

    //... Info Device ...
    text = "";
    for(i=0; i<Expozition.size(); i++)
    {
        if(div(i,2).rem) continue;
        if(!text.isEmpty()) text += ", ";
        text += QString::number(Expozition.at(i));
    }
    map->insert("Exposure", text);
    Info->fill_Info(map);

    emit sRefreshInfoDevice();  // for Settings
}
//-----------------------------------------------------------------------------
//--- Load_Expozition()
//-----------------------------------------------------------------------------
bool Device_page::Load_Expozition()
{
    int i;
    QString text;
    QByteArray buf;
    QVector<short> std_vec;

    union
    {
        Device_Par Device_Param;
        unsigned char byte_buf[512];
    }DEVICE_PAR;

    Expozition.clear();

    text = map_InfoDevice.value(INFODEV_parameters,"");
    if(text.isEmpty()) return(false);

    buf = QByteArray::fromBase64(text.toLocal8Bit());
    if(buf.size() < 512) return(false);

    double coef_expo = (double)(COEF_EXPO);
    if(map_InfoDevice.value("device_hw","").contains("v4.0")) coef_expo = COEF_EXPO_v4;

    qDebug() << "LoadExpo: " << coef_expo;

    //... read data ...
    for(i=0; i<512; i++) DEVICE_PAR.byte_buf[i] = buf.at(i);
    std_vec.clear();
    for(i=0; i<COUNT_CH; i++)
    {
        std_vec.append((short int)DEVICE_PAR.Device_Param.optics_ch[i].exp[0]);
        std_vec.append((short int)DEVICE_PAR.Device_Param.optics_ch[i].exp[1]);
    }

    for(i=0; i<COUNT_CH; i++)
    {
        Expozition.append(qRound((double)(std_vec.at(i*2))*coef_expo));   // first expo for i-channel
        Expozition.append(qRound((double)(std_vec.at(i*2+1))*coef_expo));   // seecond expo for i-channel
    }

    return(true);
}
//-----------------------------------------------------------------------------
//--- slot_RefreshMeasure(QMap<QString, QString> *map)
//-----------------------------------------------------------------------------
void Device_page::slot_RefreshMeasure(QMap<QString, QString> *map)
{
    bool ok;
    QByteArray ba("\xB0\x43");
    QString str = QString::fromLatin1(ba);

    double T_current = map->value(INFO_Temperature,"-1").split(" ").at(0).toDouble()/100.;   // current temperature
    int fn = map->value(INFO_fn,"0").toInt();                   // fn
    fn_dev = fn;

    int state = map->value(INFO_status,"0").mid(0,1).toInt();   // state - status(nothing,run,hold,pause,warm,...)

    QString logData = map->value(INFO_logData,"");              // logData
    if(!logData.isEmpty()) emit sSendLogData(logData);          // to Settings...

    //qDebug() << "slot_RefreshMeasure: " << T_current << fn << FN << state << Dev_State << flag_Compatibility;


    //... Information ...
    //Temperature_Block->setText(QString("   T = %1%2").arg(T_current,0,'f',1).arg(str));
    //FN_label->setText(QString("   Fn = %1").arg(fn));

    //... TIM - info about time
    if(map->contains(INFO_time)) TIM_info(map->value(INFO_time, ""));


    if(state > sUnknown && state <= sWarming_up)
    {
        Queue_State.enqueue(state);
        if(Queue_State.size() > 10) Queue_State.dequeue();

        if(Check_ChangeDevice(state))  emit sChangeStateDevice(state);
    }


    //...
    if(List_Requests.contains(MEASURE_REQUEST)) return;
    if(!flag_Compatibility) return;

    if(fn > FN && (Dev_State == sRun || Dev_State == sHold) && !flag_USB_Rejime)    // In rejime RUN,HOLD
    {
        active_ch = Prot->active_Channels;
        slotSendToServer(MEASURE_REQUEST);
        //emit sWait_Process(wMeasure, 1000, "");
    }


}
//-----------------------------------------------------------------------------
//--- slot_GetMeasure(int fn_meas)
//-----------------------------------------------------------------------------
bool Device_page::slot_GetMeasure(int fn_meas)
{
    int i,j,k,m;
    int id;
    double value;
    int count = map_Measure.size();
    QByteArray b;
    QString text;
    int count_ch = 0;
    rt_Measurement* measure;

    //... offset exposition ...
    int offset_expo = 40;
    /*if(ver_OPTICS >= 3.03)*/ offset_expo = 118;
    //...

    int num_tubes = 96;
    if(Prot->count_Tubes == 48) num_tubes = 48;

    int all_measure = Prot->count_MC + Prot->count_PCR;
    int count_tubes = Prot->count_Tubes;

    int*    p_int;
    short*  p_short;

    int sec_type;
    int sec_sequence_number;
    short fn;                // number of measuring
    short type_meas;         // type of measuring
    short block_number;      // number of block in temperature program
    short cycle_rep;		 // current cycle in block
    short optical_channel;   // 0 - Fam, 1 - Hex, 2 - Rox, 3 - Cy, ...
    short exp_number;        // count of exposition
    short blk_exp;		     // black level
    short ovf_exp;			 // flag overflow
    unsigned short value_exp;         // value of exp

    Message->setStandardButtons(QMessageBox::Ok);
    Message->setIcon(QMessageBox::Warning);

    double coef_expo = (double)(COEF_EXPO);
    if(map_InfoDevice.value("device_hw","").contains("v4.0")) coef_expo = COEF_EXPO_v4;

    int num_sector = div(Prot->count_Tubes,96).quot;
    if(num_sector < 1) num_sector = 1;
    for(i=0; i<COUNT_CH; i++)
    {
        if(Prot->active_Channels & (0xf<<i*4)) count_ch++;
    }

    qDebug() << "count,count_ch,num_sector" << count << count_ch << num_sector << Prot->count_Tubes << Prot->active_Channels << fn_meas;

    if(count_ch*num_sector != count)
    {
        Message->button(QMessageBox::Ok)->animateClick(5000);
        Message->setText(tr("Invalid data format...(num_sector)"));
        Message->exec();
        return(false);
    }


    QByteArray single_block;
    single_block.reserve(512*num_sector);

    for(i=0; i<count_ch; i++)
    {
        single_block.clear();
        for(j=0; j<num_sector; j++)
        {
            text = QString("_%1").arg(i*num_sector+j);
            text = MEASURE_Data + text;
            b = map_Measure.value(text,"");
            single_block.append(b);
        }
        for(j=0; j<COUNT_EXP; j++)
        {
            measure = new rt_Measurement();
            Prot->meas.push_back(measure);
            measure->measurements.reserve(Prot->count_Tubes);

            sec_type = *(int*)(single_block.mid(0,4).data());                   // 4
            sec_sequence_number = *(int*)(single_block.mid(4,4).data());        // 8
            fn = *(short*)(single_block.mid(8,2).data());                       // 10
            type_meas = *(short*)(single_block.mid(10,2).data());               // 12
            block_number = *(short*)(single_block.mid(12,2).data());            // 14
            cycle_rep = *(short*)(single_block.mid(14,2).data());               // 16
            optical_channel = *(short*)(single_block.mid(16,2).data());         // 18
            exp_number = *(short*)(single_block.mid(18,2).data());              // 20

            blk_exp = *(short*)(single_block.mid(20+j*4,2).data());             // 22
            ovf_exp = *(short*)(single_block.mid(22+j*4,2).data());             // 24
                //...                                                               // 26-28
            value_exp = *(unsigned short*)(single_block.mid(offset_expo+j*2,2).data());           // 30-32
            value_exp = qRound((double)value_exp * coef_expo);
            if(value_exp <= 0.)
            {
                value_exp = Expozition.at(i*COUNT_EXP+j);
            }
            //value_exp = QString::number((double)value_exp*0.308,'f',0).toInt();
            //...
            //reserve char[96]                                                  // 128
            //...

            measure->fn = fn;
            measure->type_meas = type_meas;
            measure->block_number = block_number;
            measure->cycle_rep = cycle_rep;
            measure->optical_channel = optical_channel;
            measure->num_exp = j;
            measure->exp_value = value_exp;
            measure->blk_exp = blk_exp;

            for(m=0; m<num_sector; m++)
            {
                for(k=0; k<num_tubes; k++)
                {
                    p_short = (short*)(single_block.mid(128+j*96*2+m*512+k*2,2).data());
                    measure->measurements.push_back(*p_short);
                }
            }


            /*qDebug() << "meas_" << i*2+j;
            qDebug() << sec_type << sec_sequence_number << fn << type_meas << block_number
                         << cycle_rep << optical_channel
                         << exp_number << blk_exp << ovf_exp << value_exp;*/

            //qDebug() << temp;


            if(!j)  // only first expo
            {
                for(m=0; m<Prot->count_Tubes; m++)
                {
                    value = 0x0fff & measure->measurements.at(m);
                    id = i*count_tubes*all_measure + m*all_measure + (fn_meas-1);
                    plot_fluor->Y.replace(id,value);
                }
            }
        }
    }

    //qDebug() << "fn =" << fn_meas << plot_fluor->Y;

    plot_fluor->current_fn = fn_meas;
    //plot_fluor->current_Fn->setText(QString("Fn=%1 (%2)").arg(fn_meas).arg(all_measure));
    FN = fn_meas;

    if(fn_meas > 0 && all_measure > 0)
    {
        k = (100.*fn_meas)/all_measure;
        text = QString(tr("Measurements %1(%2)")).arg(fn_meas).arg(all_measure);
        //Display_ProgressBar(k, text);
    }
    //... for Holding ...
    /*if(Dev_State == sHold &&
        FN == all_measure &&
           FN > 0)
        {
            emit sChangeStateDevice(sHold);
        }*/
}

//-----------------------------------------------------------------------------
//--- slot_SaveExpo
//-----------------------------------------------------------------------------
void Device_page::slot_Exec_Commaand(QString request)
{
    int id = Catalogue_Requests.indexOf(request);

    switch(id)
    {
    default:        break;

    case 6:         // Open Block
                    slot_OpenBlock();
                    break;

    case 7:         // Close Block
                    slot_CloseBlock();
                    break;
    }



}

//-----------------------------------------------------------------------------
//--- slot_SaveExpo
//-----------------------------------------------------------------------------
void Device_page::slot_SaveExpo(int ctrl, QString data)
{
    map_SavePar.clear();
    map_SavePar.insert(SAVEPAR_CTRL, QString::number(ctrl));
    map_SavePar.insert(SAVEPAR_DATA, data);
    map_SavePar.insert(ID_PARAM, QString::number(ctrl));

    //qDebug() << map_SavePar;

    slotSendToServer(SAVEPAR_REQUEST);
    emit sWait_Process(wPic, 100, tr("Save Expo..."));
}

//-----------------------------------------------------------------------------
//--- slot_ChangeStateDevice
//-----------------------------------------------------------------------------
void Device_page::slot_ChangeStateDevice(int state)
{
    DevState current_state = Dev_State;
    Dev_State = (DevState)state;
    int res;
    QString fn;
    QString text;
    bool sts = false;

    emit sFinished_WaitProcess();

    qDebug() << "CHANGE Dev_State: " << Dev_State << current_state;
/*
    // 1. Run
    if(Dev_State == sNothing && flag_Compatibility && flag_StatusRun) RunDev->setDisabled(false);
    else RunDev->setDisabled(true);

    // 2. Pause
    if(Dev_State == sRun) PauseDev->setDisabled(false);
    else PauseDev->setDisabled(true);

    // 3. Stop
    if(Dev_State > sNothing && Dev_State != sPause) StopDev->setDisabled(false);
    else StopDev->setDisabled(true);

    // 4. Tab_Control
    if(Dev_State > sUnknown) {Tab_Control->setDisabled(false); OpenClose_Box->setDisabled(false);}
    else {Tab_Control->setDisabled(true); OpenClose_Box->setDisabled(true);}

    // 5. OpenProtocol
    if(Dev_State < sRun) {OpenProtocol->setDisabled(false); LastProtocol->setDisabled(false); ClearProtocol->setDisabled(false);}
    else {OpenProtocol->setDisabled(true); LastProtocol->setDisabled(true); ClearProtocol->setDisabled(true);}
    if(Dev_State == sRun)
    {
        Tab_Protocol->setCurrentIndex(0);
    }

    // 6. LastRun
    if(Dev_State == sNothing) LastRun->setDisabled(false);
    else  LastRun->setDisabled(true);

    // 7. Error Info
    if(Dev_State < sNothing) Error_Info->clear();
*/

    // 6. LastRun
    if(Dev_State == sNothing) LastRun->setVisible(true);
    else  LastRun->setVisible(false);

    // ... Enable/Disable Button Exit
    if(Dev_State > sNothing) emit sRun_rejime(true);
    else emit sRun_rejime(false);


    switch(current_state)
    {
    default:
    case sUnknown:      if(state > sNothing && state <= sWarming_up)
                        {
                            Message->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                            Message->setDefaultButton(QMessageBox::Yes);
                            Message->setIcon(QMessageBox::Question);
                            Message->button(QMessageBox::Yes)->animateClick(7000);
                            text = tr("Attention! Program is running in the device!") + "\r\n" +
                                   tr("Would you like to continue the program execution?");
                            Message->setText(text);
                            //Message->setInformativeText(tr("Would you like to continue the program execution?"));
                            res = Message->exec();

                            if(res == QMessageBox::No)
                            {
                                slotSendToServer(STOP_REQUEST);
                            }
                            if(res == QMessageBox::Yes)
                            {
                                //... open last running protocol ...                                
                                emit sLoad_LastRunProtocol();
                            }
                        }
                        break;

    case sNothing:      /*if(state == sNothing && flag_LastRun)
                        {
                            if(Create_MeasureProtocol("last_run.rt"))
                            {
                                flag_LastRun = false;
                                if(Analyze_immediately->isChecked())
                                {
                                    QEvent *e = new QEvent((QEvent::Type)3003);
                                    QApplication::sendEvent(this->parentWidget(), e);
                                }
                            }
                         }*/
                        if(state == sRun) prot_Start = QDateTime::currentDateTime();

                        break;

    case sHold:
    case sRun:
                        if((state == sNothing || state == sHold) && !flag_SavingResult && FN > 0)
                        {
                            if(Create_MeasureProtocol())
                            {
                                flag_SavingResult = true;
                                CopyToOutput(QString("%1/device/measurements.rt").arg(qApp->applicationDirPath()), Prot);
                            }
                        }
                        break;

    case sPause:        break;

    case sWarming_up:
                        if(state == sRun) prot_Start = QDateTime::currentDateTime();
                        break;
    }

    switch(Dev_State)
    {
    default:
                    if(current_state == sRun || current_state == sPause) emit sRun_Stop();
                    break;

    case sRun:
    case sPause:
                    emit sRun_Start();
                    break;
    }

    //
    if(Dev_State >= sRun) emit sRejimeDevButtons(1,2);
    else
    {
        if(flag_Compatibility) emit sRejimeDevButtons(1,1);
        else emit sRejimeDevButtons(1,0);
    }

    // label_Time:
    if(Dev_State == sRun || Dev_State == sPause) label_Time->setVisible(true);
    else label_Time->setVisible(false);

    // RunDev:
    if(Dev_State < 1 && flag_Compatibility) RunDev->setDisabled(false);
    else RunDev->setDisabled(true);

    // StopDev:
    if(Dev_State > 0) StopDev->setDisabled(false);
    else StopDev->setDisabled(true);

    // PauseDev:
    if(Dev_State > 0) PauseDev->setDisabled(false);
    else PauseDev->setDisabled(true);

    // Open%Close
    if(Dev_State > 0 && Dev_State != sPause) {open_Block->setDisabled(true); close_Block->setDisabled(true);}
    else {open_Block->setDisabled(false); close_Block->setDisabled(false);}

    // Rejime USB and Run...
    if(flag_USB_Rejime && current_state <= 0 && Dev_State > 0) slotSendToServer(GETAMPINSIMPLE_REQUEST);

    // Last Run
    if(flag_LastRun && Dev_State == sNothing)
    {
        flag_LastRun = false;
        sts = Create_MeasureProtocol("", true);
        if(sts)
        {
            emit sChangePage(2);    // to Analysis
            emit sOpenProtocolAfterRun(qApp->applicationDirPath() + "/device/last_run.rt");
        }
        //qDebug() << "Create Last Run: " << sts;
    }

    /*if(Dev_State > sNothing) plot_temperature->set_Enable(true);
    else plot_temperature->set_Enable(false);

    if(Dev_State == sRun) StandBy->setEnabled(true);
    else StandBy->setEnabled(false);
    */

}
//-----------------------------------------------------------------------------
//--- Create_LastRunProtocol()
//-----------------------------------------------------------------------------
bool Device_page::Create_LastRunProtocol()
{

}

//-----------------------------------------------------------------------------
//--- Create_MeasureProtocol()
//-----------------------------------------------------------------------------
bool Device_page::Create_MeasureProtocol(QString text, bool last_run)
{
    int i;
    bool res = false;
    bool ok;
    QString fn = "/measurements.rt";
    if(last_run) fn = "/last_run.rt";

    QDomDocument    doc;
    QDomElement     root;
    QDomElement     status_elemment;
    QDomElement     status_new;

    QString dir_device = qApp->applicationDirPath() + "/device";
    QFile file(dir_device + "/run.rt");
    QFile file_out;
    QFileInfo file_info;

    bool sts = QFile::remove(dir_device + fn);                          //"/measurements.rt");

    if(text.isEmpty())  file_out.setFileName(dir_device + fn);          //"/measurements.rt");
    else                file_out.setFileName(dir_device + "/" + text);


    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        if(doc.setContent(&file))
        {
            file.close();

            root = doc.documentElement();
            //... change status -> measurements
            status_elemment = root.firstChildElement("status");
            status_new = MakeElement(doc,"status","measurements");
            if(status_elemment.isNull()) root.insertAfter(status_new, root.firstChildElement("regNumber"));
            else root.replaceChild(status_new, status_elemment);

            //... Device ...
            //qDebug() << "Device:" << Prot->SerialName;
            //QDomElement device = SaveXML_Device(doc, Prot);
            //root.appendChild(device);

            //... Measurements ...
            QDomElement measurements = SaveXML_Measurements(doc, Prot);
            root.appendChild(measurements);


            if(file_out.open(QIODevice::WriteOnly))
            {
                QTextStream(&file_out) << doc.toString();
                file_out.close();
                file_info.setFile(file_out);
                if(file_out.exists()) res = true;
            }
        }
        else file.close();
    }

    return(res);
}
//-----------------------------------------------------------------------------
//--- Check_ChangeDevice()
//-----------------------------------------------------------------------------
bool Device_page::Check_ChangeDevice(int state)
{
    int i;
    int current_state = Dev_State;
    int new_state = state;
    int count = Queue_State.size();

    if(current_state == new_state) return(false);
    if(Queue_State.size() < 3) return(false);

    for(i=0; i<2; i++)
    {
        if(new_state != Queue_State.at(count-1-i)) return(false);
    }

    //Dev_State = (DevState)state;

    return(true);
}
//-----------------------------------------------------------------------------
//--- CopyToInput(QString fn, rt_Protocol *p)
//-----------------------------------------------------------------------------
bool Device_page::CopyToInput(QString fn, rt_Protocol *p)
{
    bool res = false;
    QString dir_input = qApp->applicationDirPath() + "/input";
    QString fn_in = QString("%1/%2_%3.rt").arg(dir_input).arg(p->regNumber).arg(QDateTime::currentDateTime().toString("ddMMyy_hhmmss"));

    Limit_Dir(dir_input, 10);

    QFile f(fn);
    if(f.exists())
    {
        res = f.copy(fn_in);
        qDebug() << "copy in:" << res << fn_in;
    }

    return(res);
}
//-----------------------------------------------------------------------------
//--- CopyToOutput(QString fn, rt_Protocol *p)
//-----------------------------------------------------------------------------
bool Device_page::CopyToOutput(QString fn, rt_Protocol *p)
{
    bool res = false;
    QString dir_output = qApp->applicationDirPath() + "/output";
    QString fn_out = QString("%1/%2_%3.rt").arg(dir_output).arg(p->regNumber).arg(QDateTime::currentDateTime().toString("ddMMyy_hhmmss"));

    Limit_Dir(dir_output, 20);

    QFile f(fn);
    if(f.exists())
    {
        res = f.copy(fn_out);
        qDebug() << "copy out:" << res << fn_out;
        if(res)
        {
            emit sChangePage(1);
            Message->setStandardButtons(QMessageBox::Ok);
            Message->setIcon(QMessageBox::Information);
            Message->button(QMessageBox::Ok)->animateClick(5000);
            Message->setText(tr("File with optical data is saved! Proceed to the analysis of the results..."));
            Message->exec();
            emit sChangePage(2);
            emit sOpenProtocolAfterRun(fn_out);
            if(Property_WebProtocol(p) == p->regNumber) emit sSaveProtocolToServer();   // save to Web if protocol came from Web
            qDebug() << "Protocol Properties: " << Property_WebProtocol(p) << p->regNumber;
            foreach(rt_Preference *property, p->preference_Pro)
            {
                qDebug() << "Name,Value: " << property->name << property->value;
            }
        }
    }

    return(res);
}
//-----------------------------------------------------------------------------
//--- Limit_Dir
//-----------------------------------------------------------------------------
void Device_page::Limit_Dir(QString dir_name, int lim)
{
    QDir dir(dir_name);

    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Time);
    QFileInfoList list = dir.entryInfoList();

    for (int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        //qDebug() << "QFileInfoList: " << fileInfo.fileName() << fileInfo.created();

        if(i >= (lim-1))
        {
            QFile::remove(fileInfo.absoluteFilePath());
        }
    }

}

//-----------------------------------------------------------------------------
//--- Create_RunProtocol()
//-----------------------------------------------------------------------------
bool Device_page::Create_RunProtocol(QString fn)
{
    int i;
    bool ok;
    bool res = false;

    QDomDocument    doc;
    QDomElement     root;
    QDomElement     status_element;
    QDomElement     status_new;
    QDomElement     created_element;
    QDomElement     created_new;
    QDateTime       run_Start = QDateTime::currentDateTime();

    if(!Prot)   return(false);

    // device info ...
    Prot->SerialName = map_InfoDevice.value(INFODEV_serName,"");
    Prot->uC_Versions = map_InfoDevice.value(INFODEV_version, "");
    Prot->Type_ThermoBlock = map_InfoDevice.value(INFODEV_thermoBlock,"");
    Prot->FluorDevice_MASK = map_InfoDevice.value(INFODEV_devMask,"").toInt(&ok,16);

    // device coeff ...
    Prot->COEFF_Spectral.clear();
    for(i=0; i<SpectralCoeff.size(); i++) Prot->COEFF_Spectral.push_back(SpectralCoeff.at(i));
    Prot->COEFF_Optic.clear();
    for(i=0; i<OpticCoeff.size(); i++) Prot->COEFF_Optic.push_back(OpticCoeff.at(i));
    Prot->COEFF_UnequalCh.clear();
    for(i=0; i<UnequalCoeff.size(); i++) Prot->COEFF_UnequalCh.push_back(UnequalCoeff.at(i));

    // device mask ...
    Prot->DeviceParameters = Load_OpticMask();

    QFile file(fn);
    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        if(doc.setContent(&file))
        {
            file.close();

            root = doc.documentElement();

            //... change status -> run
            status_element = root.firstChildElement("status");
            status_new = MakeElement(doc, "status", "run");
            if(status_element.isNull()) root.insertAfter(status_new, root.firstChildElement("regNumber"));
            else root.replaceChild(status_new, status_element);
            //...

            //... change created: QDateTime::currentDateTime()
            created_element = root.firstChildElement("created");
            created_new = MakeElement(doc, "created", run_Start.toString("d dddd yyyy, HH:mm:ss"));
            if(created_element.isNull()) root.insertAfter(created_new, root.firstChildElement("status"));
            else root.replaceChild(created_new, created_element);

            //runtime_Program->prot_Start = run_Start;
            //...

            QDomElement device = SaveXML_Device(doc, Prot);
            root.appendChild(device);

            if(file.open(QIODevice::WriteOnly))
            {
                QTextStream(&file) << doc.toString();
                file.close();
                if(file.exists())
                {
                    res = true;
                    //addProtocol_toList(file_out.fileName());
                }
            }
        }
        else file.close();
    }

    return(res);
}

//-----------------------------------------------------------------------------
//--- Load_SpectralCoeff()
//-----------------------------------------------------------------------------
bool Device_page::Load_SpectralCoeff()
{
    int i,j;
    int count;
    double value;
    bool sts;

    union
    {
        SpectralCoeff_Compensation SpectralCOEFF;
        unsigned char byte_buf[512];
    }SPECTRAL_COEFF;

    SpectralCoeff.clear();

    QString text = map_InfoDevice.value(INFODEV_SpectralCoeff,"");
    if(text.isEmpty()) return(false);

    QByteArray buf = QByteArray::fromBase64(text.toStdString().c_str());
    for(i=0; i<512; i++) SPECTRAL_COEFF.byte_buf[i] = buf.at(i);
    count = SPECTRAL_COEFF.SpectralCOEFF.count;

    for(i=0; i<count; i++)
    {
        text = (QString)SPECTRAL_COEFF.SpectralCOEFF.Info_Spectral[i].fluor_name;
        text += "\t" + QString::number(SPECTRAL_COEFF.SpectralCOEFF.Info_Spectral[i].id_group);
        text += "\t";
        for(j=0; j<COUNT_CH; j++)
        {
            value = SPECTRAL_COEFF.SpectralCOEFF.Info_Spectral[i].coeff[j];
            value /= 1000.;
            text += " " + QString::number(value,'f',3);
        }

        SpectralCoeff.append(text);
            //qDebug() << text;
    }

    return(sts);
}
//-----------------------------------------------------------------------------
//--- Load_OpticCoeff
//-----------------------------------------------------------------------------
bool Device_page::Load_OpticCoeff()
{
    int i,j,k;
    int count;
    int count_block = 1;
    int count_tube;
    double value;
    bool sts;

    union
        {
            OpticalCoeff_Compensation OpticalCOEFF;
            unsigned char byte_buf[512];
        }OPTICAL_COEFF;

    OpticCoeff.clear();

    QString text = map_InfoDevice.value(INFODEV_OpticalCoeff,"");
    if(text.isEmpty()) return(false);

    QByteArray buf = QByteArray::fromBase64(text.toStdString().c_str());

    text = map_InfoDevice.value(INFODEV_serName,"");
    k = text.trimmed().mid(1,1).toInt();
    if(k == 6) count_block = 2;
    switch(k)
    {
    default:
    case 5:     count_tube = 96;    break;
    case 6:     count_tube = 384;   break;
    case 7:     count_tube = 48;    break;
    case 8:     count_tube = 192;    break;
    }

    for(i=0; i<COUNT_CH; i++)
    {
        text = "";
        for(j=0; j<count_block; j++)
        {
            for(k=0; k<512; k++) OPTICAL_COEFF.byte_buf[k] = buf.mid(512*count_block*i + 512*j, 512).at(k);

            //if(!j) text = (QString)OPTICAL_COEFF.OpticalCOEFF.fluor_name + "\t";

            for(k=0; k<192; k++)
            {
                if(k >= count_tube) break;
                value = OPTICAL_COEFF.OpticalCOEFF.coeff[k];
                value /= 1000.;
                //text += QString::number(value,'f',3) + " ";
                text += QString("%1 ").arg(value,0,'f',3);
            }
        }
        OpticCoeff.append(text);
        //qDebug() << text;
    }


    return(sts);
}
//-----------------------------------------------------------------------------
//--- Load_UnequalCoeff()
//-----------------------------------------------------------------------------
bool Device_page::Load_UnequalCoeff()
{
    int i,j;
    int count;
    double value;
    bool sts;

    union
        {
            UnequalCoeff_Compensation UnequalCOEFF;
            unsigned char byte_buf[512];
        }UNEQUAL_COEFF;

    UnequalCoeff.clear();

    QString text = map_InfoDevice.value(INFODEV_UnequalCoeff,"");
    if(text.isEmpty()) return(false);

    QByteArray buf = QByteArray::fromBase64(text.toStdString().c_str());
    for(i=0; i<512; i++) UNEQUAL_COEFF.byte_buf[i] = buf.at(i);
    count = UNEQUAL_COEFF.UnequalCOEFF.count;

    for(i=0; i<count; i++)
    {
        text = (QString)UNEQUAL_COEFF.UnequalCOEFF.Info_Unequal[i].fluor_name;
        text += "\t" + QString::number(UNEQUAL_COEFF.UnequalCOEFF.Info_Unequal[i].id_group);
        text += "\t";
        for(j=0; j<2; j++)  // 2 coefficients
        {
            value = UNEQUAL_COEFF.UnequalCOEFF.Info_Unequal[i].coeff[j];
            if(!j) {value /= 1000.; text += " " + QString::number(value,'f',3);}
            else text += " " + QString::number(value,'f',0);
        }

        UnequalCoeff.append(text);
        //qDebug() << text;
    }

    return(sts);
}
//-----------------------------------------------------------------------------
//--- Load_OpticMask()
//-----------------------------------------------------------------------------
QString Device_page::Load_OpticMask()
{

    int i;
    int count;
    QString mask;
    QString text;

    // 1. auto status
    mask += "0 ";

    // 2. radius
    mask += QString("%1 %2 ").arg(Rx).arg(Rx);

    // 3. offset
    text = "";
    count = offset_XY.size();
    for(i=0; i<count; i++)
    {
        text += QString("%1 ").arg(offset_XY.at(i));
    }
    mask += text;

    // 4. data
    mask += "centers: ";
    count = XY.size();
    for(i=0; i<count; i++)
    {
       mask += QString("%1 ").arg(XY.at(i));
    }

    return(mask);
}
//-----------------------------------------------------------------------------
//--- Load_Mask()
//-----------------------------------------------------------------------------
bool Device_page::Load_Mask()
{
    int i,j;
    int num_sec;
    int left;
    int count_sec = 96;
    QString text;
    QByteArray buf;
    QVector<short> std_vec;

    union
    {
        Device_Par Device_Param;
        unsigned char byte_buf[512];
    }DEVICE_PAR;

    text = map_InfoDevice.value(INFODEV_parameters,"");
    if(text.isEmpty()) return(false);

    buf = QByteArray::fromBase64(text.toStdString().c_str());
    num_sec = div(buf.size(),512).quot;

    text = map_InfoDevice.value(INFODEV_serName,"000");
    int count_tubes = text.trimmed().mid(1,1).toInt();
    switch(count_tubes)
    {
    default:    count_tubes = 0;   break;
    case 5:     count_tubes = 96;  break;
    case 6:     count_tubes = 384; break;
    case 7:     count_tubes = 48;  break;
    case 8:     count_tubes = 192; break;
    }

    Count_Tubes = count_tubes;
    if(count_tubes == 0) return(false);

    QString version_HW = map_InfoDevice.value("device_hw","v3.0");

    int left_offset = LEFT_OFFSET;
    int top_offset = TOP_OFFSET;
    if(version_HW.contains("v4.0"))
    {
        left_offset = 0;
        top_offset = 0;
    }

    left = left_offset;
    if(count_tubes == 48 || count_tubes == 192) left = LEFT_OFFSET_DT48;
    if(count_tubes == 48) count_sec = 48;


    XY.clear();
    offset_XY.clear();

    //... Geometry ...
    for(i=0; i<num_sec; i++)
    {
        for(j=0; j<512; j++) DEVICE_PAR.byte_buf[j] = buf.at(j+i*512);

        std_vec.clear();
        for(j=0; j<count_sec*2; j++) std_vec.append(DEVICE_PAR.Device_Param.X_Y[j]);

        for(j=0; j<count_sec; j++)
        {
            XY.append(std_vec.at(2*j) - left);
            XY.append(std_vec.at(2*j+1) - top_offset);
        }
        if(i == 0)  // only for first sector
        {
            Rx = DEVICE_PAR.Device_Param.Rx;
            Ry = DEVICE_PAR.Device_Param.Ry;
            for(j=0; j<COUNT_CH; j++)
            {
                offset_XY.append(DEVICE_PAR.Device_Param.d_xy[j*2] * (-1));
                offset_XY.append(DEVICE_PAR.Device_Param.d_xy[j*2+1]);
            }
        }
    }
    //qDebug() << "XY: " << Rx << Ry << offset_XY << XY;
    std_vec.clear();
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
QString Device_page::Property_WebProtocol(rt_Protocol *p)
{
    QString value = "";
    rt_Preference *property;

    foreach(property, p->preference_Pro)
    {
        if(property->name == "Web_Protocol")
        {
            value = property->value;
            break;
        }
    }

    return(value);
}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::TIM_info(QString text)
{
    QDateTime tim;
    QTime     tau;
    int tim_0 = 0;
    int tim_1 = 0;
    int tim_2 = 0;
    int value;
    int all_meas = Prot->count_PCR + Prot->count_MC;

    qint64 msec;

    sscanf(text.toStdString().c_str(),"%d %d %d", &tim_0, &tim_1, &tim_2);
    if(text != TIM_state)
    {
        TIM_state = text;
        tim = QDateTime::currentDateTime();

        // From start:
        msec = prot_Start.msecsTo(tim);
        tau = QTime::fromMSecsSinceStartOfDay(msec);
        list_Time.replace(0, tau.toString("HH:mm:ss"));

        // Till end
        tau = QTime::fromMSecsSinceStartOfDay(tim_0*1000);
        list_Time.replace(1, tau.toString("HH:mm:ss"));

        // Time of start
        list_Time.replace(2, prot_Start.toString("HH:mm:ss"));

        // End time
        list_Time.replace(3, prot_Start.addSecs(tim_0).toString("HH:mm:ss"));

        // Current time
        list_Time.replace(4, tim.toString("HH:mm:ss"));


        change_FirstTime(1);
        //change_SecondTime(time_second->currentIndex());

        if(Dev_State == sRun || Dev_State == sPause)
        {
            value = (msec/1000. * 100.)/(msec/1000. + tim_0);
            if(flag_USB_Rejime)     emit sRun_Process(value, QString("%1%  (%2)").arg(value).arg(fn_dev));
            else                    emit sRun_Process(value, QString("%1%  %2(%3)").arg(value).arg(FN).arg(all_meas));
        }
    }

}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_InfoUSB(QMap<QString, QString> *map)
{
    QString text;
    QVector<QString> pr;
    QStringList list_pr;
    bool ok;


    qDebug() << "GETAMPINSIMPLE_DATA: " << *map;

    // Programm of Amplification
    text = map->value(GETAMPINSIMPLE_AMPPROG, "");
    if(!text.isEmpty())
    {
        list_pr = text.split("\t");
        foreach(text, list_pr)
        {
            pr.append(text);
        }
        Prot->program = pr;
        Parsing_ProgramAmplification(Prot);
    }

    // Protocols Name
    text = map->value(GETAMPINSIMPLE_PNUM, "");
    Prot->name = text;

    // Operator Name
    text = map->value(GETAMPINSIMPLE_PONM, "");
    Prot->owned_by = text;

    // Active Channels
    text = map->value(GETAMPINSIMPLE_PLEDS, "0x0000");
    Prot->active_Channels = text.toInt(&ok,16);
    if(!ok) Prot->active_Channels = 0;

    // Count Tubes
    Prot->count_Tubes = Count_Tubes;


    emit sChangePage(1);
    emit sLoad_USB_Protocol();
}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::slot_ChangeLink(int rejime)
{
    int i;
    QVector<QWidget*> list;

    if(rejime == 3) flag_USB_Rejime = false;
    if(rejime == 4) flag_USB_Rejime = true;

    Tab_Dev->setCurrentIndex(0);

    if(flag_USB_Rejime)
    {
        for(i=Tab_Dev->count()-1; i>=0; i--)
        {
            if(Tab_Dev->widget(i) == Fluor_Box)  Tab_Dev->removeTab(i);
        }
    }
    else
    {
        for(i=0; i<Tab_Dev->count(); i++) list.append(Tab_Dev->widget(i));
        if(!list.contains(Fluor_Box)) Tab_Dev->insertTab(1, Fluor_Box, QIcon(":/images/Spectrum_new.png"), "");
    }
}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::change_FirstTime(int id)
{
    label_Time->setText(list_Time.at(id));
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_page::change_SecondTime(int id)
{
    //label_second->setText(list_Time.at(id));
}
