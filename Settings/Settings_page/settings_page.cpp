#include "settings_page.h"


//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Settings_page::Settings_page(QWidget *parent):  QMainWindow(parent)
{    
    QFont f = qApp->font();
    f.setBold(true);
    f.setPointSize(f.pointSize()+2);

    readsettings();

    SettingsGroupBox = new QGroupBox(this);
    SettingsGroupBox->setObjectName("Transparent");
    setCentralWidget(SettingsGroupBox);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setMargin(2);

    SettingsGroupBox->setLayout(layout);    

    Tab_Settings = new QTabWidget(this);
    Tab_Settings->setStyleSheet("QTabWidget::tab-bar{alignment: right;}");
    Tab_Settings->setIconSize(QSize(48,48));
    layout->addWidget(Tab_Settings,1);


    //... Link ...
    group_setLinks = new QButtonGroup(this);
    Ethernet_Button = new QPushButton(this);
    Ethernet_Button->setFixedSize(64,64);
    Ethernet_Button->setIcon(QIcon(":/images/Ethernet_1.png"));
    Ethernet_Button->setIconSize(QSize(32,32));
    Ethernet_Button->setCheckable(true);
    Ethernet_Button->setChecked(true);
    USB_Button = new QPushButton(this);
    USB_Button->setFixedSize(64,64);
    USB_Button->setIcon(QIcon(":/images/USB.png"));
    USB_Button->setIconSize(QSize(48,48));
    USB_Button->setCheckable(true);

    group_setLinks->addButton(Ethernet_Button);
    group_setLinks->addButton(USB_Button);

    Link_Type = new QGroupBox(this);
    QHBoxLayout *layout_link = new QHBoxLayout;
    layout_link->setMargin(2);
    Link_Type->setLayout(layout_link);
    Link_Type->setObjectName("Transparent");
    layout_link->addStretch(1);
    layout_link->addWidget(Ethernet_Button);
    layout_link->addWidget(USB_Button);
    layout_link->addStretch(1);

    //... IP ...
    IP_Address = new QGroupBox(this);
    QVBoxLayout *layout_ip = new QVBoxLayout;
    layout_ip->setMargin(2);
    IP_Address->setLayout(layout_ip);
    IP_Address->setObjectName("Transparent");
    layout_ip->addStretch(1);

    ip_address = new QPushButton(this);
    ip_address->setFont(f);
    //ip_address->setFixedWidth(200);
    netmask = new QPushButton(this);
    netmask->setFont(f);
    //netmask->setFixedWidth(200);
    gateway = new QPushButton(this);
    gateway->setFont(f);
    //gateway->setFixedWidth(200);
    ip_label = new QLabel("IP address", this);
    netmask_label = new QLabel("Netmask", this);
    gateway_label = new QLabel("Gateway", this);

    QHBoxLayout *layout_address = new QHBoxLayout();
    QHBoxLayout *layout_netmask = new QHBoxLayout();
    QHBoxLayout *layout_gateway = new QHBoxLayout();

    layout_address->setSpacing(10);
    layout_netmask->setSpacing(10);
    layout_gateway->setSpacing(10);

    //layout_address->addStretch(1);
    layout_address->addWidget(ip_address, 0, Qt::AlignLeft);
    layout_address->addWidget(ip_label, 0, Qt::AlignLeft);
    layout_address->addStretch(1);
    //layout_netmask->addStretch(1);
    layout_netmask->addWidget(netmask, 0, Qt::AlignLeft);
    layout_netmask->addWidget(netmask_label, 0, Qt::AlignLeft);
    layout_netmask->addStretch(1);
    //layout_gateway->addStretch(1);
    layout_gateway->addWidget(gateway, 0, Qt::AlignLeft);
    layout_gateway->addWidget(gateway_label, 0, Qt::AlignLeft);
    layout_gateway->addStretch(1);

    //ip_address->setInputMask("000.000.000.000;_");
    //layout_ip->addStretch(1);
    layout_ip->addLayout(layout_address);
    layout_ip->addLayout(layout_netmask);
    layout_ip->addLayout(layout_gateway);
    layout_ip->addStretch(1);

    group_ip = new QButtonGroup(this);
    group_ip->addButton(ip_address);
    group_ip->addButton(netmask);
    group_ip->addButton(gateway);

    //connect(ip_address, SIGNAL())

    //... Diagnostic ...
    Diagnostic = new QGroupBox(this);
    QVBoxLayout *layout_diag = new QVBoxLayout;
    Diagnostic->setLayout(layout_diag);
    View_cmd = new QListWidget(this);
    layout_diag->addWidget(View_cmd);

    //... Editing IP ...
    edit_ip = new Edit_IP(this);
    edit_ip->hide();

    //... List Protocols ...
    List_Protocols = new Protocol_List(this);
    List_Protocols->hide();

    //... Choice Type ...
    Choice_Type = new ChoiceType_Dialog(this);
    Choice_Type->hide();

    //... Message ...
    setStyleSheet("QMessageBox QPushButton{background-color: #FAFAFA;}");
    message_settings = new QMessageBox(this);

    //... Upgrade ...
    Upgrate = new QGroupBox(this);
    QHBoxLayout *layout_upgrate = new QHBoxLayout();
    Upgrate->setLayout(layout_upgrate);
    upgrate_soft = new QPushButton(tr("Upgrade soft..."), this);
    upgrate_soft->setFixedWidth(500);
    upgrate_soft->setFont(f);
    //layout_upgrate->addWidget(upgrate_soft, 0, Qt::AlignLeft | Qt::AlignTop);
    layout_upgrate->addWidget(upgrate_soft);

    //... Device_Settings ...
    Device_Settings = new QGroupBox(this);
    Device_Settings->setObjectName("Transparent");
    Settings = new QTabWidget(this);
    Settings->setTabPosition(QTabWidget::East);
    Settings->setStyleSheet("QTabWidget::tab-bar{alignment: left;}");
    Settings->setIconSize(QSize(48,48));
    QHBoxLayout *settings_layout = new QHBoxLayout();
    settings_layout->setMargin(2);
    Device_Settings->setLayout(settings_layout);
    settings_layout->addWidget(Settings,1);
    Measure_HeightTubes = new QGroupBox(this);
    Measure_HeightTubes->setObjectName("Transparent");
    measure_height = new QPushButton(tr("Measure the tubes heigh..."), this);
    measure_height->setFont(f);
    measure_height->setFixedWidth(500);
    QHBoxLayout *measure_layout = new QHBoxLayout();
    Measure_HeightTubes->setLayout(measure_layout);
    measure_layout->addWidget(measure_height);
    //---
    Exposure_Change = new QGroupBox(this);
    Exposure_Change->setObjectName("Transparent");
    QHBoxLayout *expo_layout = new QHBoxLayout;
    expo_layout->setMargin(0);
    expo_layout->setSpacing(4);
    Exposure_Change->setLayout(expo_layout);
    Video_Box = new QGroupBox(this);
    Control_Box = new QGroupBox(this);
    expo_layout->addWidget(Video_Box);
    expo_layout->addWidget(Control_Box);

    Image = new QImage(W_IMAGE_COEF, H_IMAGE, QImage::Format_RGB32);
    Image->fill(Qt::white);
    image_Widget = new Image_Widget(Image, this);
    image_Widget->setFixedSize(W_IMAGE_COEF, H_IMAGE);
    QHBoxLayout *layout_image = new QHBoxLayout;
    Video_Box->setLayout(layout_image);
    layout_image->addWidget(image_Widget);

    measure_Button = new QPushButton(QIcon(":/images/video_flat.png"), tr("measure"), this);
    save_Expo_Button = new QPushButton(QIcon(":/images/load_32.png"), tr("save Expo"), this);
    save_Expo_Button->setDisabled(true);
    Paint_Mask = new QToolButton(this);
    Paint_Mask->setCheckable(true);
    Paint_Mask->setFixedSize(48,44);
    Paint_Mask->setStyleSheet("QToolButton::pressed {background-color: #F1F1F1;}"
                              "QToolButton::enabled {background-color: #FAFAFA;}"
                              "QToolButton::checked {background-image: url(:/images/ok_32_48.png); border: 1px solid black;}"
                              );
    mask_label = new QLabel(tr("mask"), this);
    QHBoxLayout *layout_mask = new QHBoxLayout;
    layout_mask->setMargin(0);
    layout_mask->setSpacing(6);
    layout_mask->addWidget(Paint_Mask, 0, Qt::AlignLeft);
    layout_mask->addWidget(mask_label, 0, Qt::AlignLeft);
    layout_mask->addStretch(1);
    //Paint_Mask->setIconSize(QSize(48,48));
    //button1->setStyleSheet("QPushButton{ background-image: url(config.png); }");
    //Paint_Mask->setStyleSheet("QCheckBox::indicator {width:30px; height: 25px;}");
    Fluor_Box = new QComboBox(this);
    f = qApp->font();
    f.setPointSize(f.pointSize()+4);
    Fluor_Box->setFont(f);
    Fluor_Box->setStyleSheet(
                "QComboBox::down-arrow {image: url(:/images/down_arrow_wide.png);}");
    Exposure = new QPushButton(this);
    Exposure->setFont(f);    
    Exposure->setFocusPolicy(Qt::NoFocus);
    //Exposure->setObjectName("Transparent");
    Exposure->setStyleSheet("QPushButton::enabled {background-color: #FAFAFA;}"
                            "QPushButton::pressed {background-color: #F1F1F1;}");
    QVBoxLayout *layout_control = new QVBoxLayout;
    Control_Box->setLayout(layout_control);
    layout_control->addWidget(Fluor_Box,0, Qt::AlignTop);
    layout_control->addWidget(Exposure,0, Qt::AlignTop);
    layout_control->addLayout(layout_mask);

    //layout_control->addWidget(Paint_Mask,1, Qt::AlignTop);
    layout_control->addWidget(save_Expo_Button,1, Qt::AlignBottom);
    layout_control->addWidget(measure_Button,0, Qt::AlignBottom);

    BUF_Video.resize(H_IMAGE*W_IMAGE);
    BUF_Video.fill(0);


    Settings->addTab(Measure_HeightTubes, QIcon(":/images/measure_tube_32.png"), "");
    Settings->addTab(Exposure_Change, QIcon(":/images/timer_flat.png"), "");

    //... ScreenShot ...
    /*ScreenShot = new QGroupBox(this);
    QVBoxLayout *layout_screenshot = new QVBoxLayout;
    ScreenShot->setLayout(layout_screenshot);
    make_screenshot = new QCheckBox(tr("make screenshot..."), this);
    layout_screenshot->addWidget(make_screenshot, 0, Qt::AlignLeft | Qt::AlignTop);
    Dialog_Screenshot = new QDialog();
    Dialog_Screenshot->setModal(false);
    Dialog_Screenshot->setWindowFlags(Qt::WindowStaysOnTopHint);
    Dialog_Screenshot->setFixedSize(200,100);
    Make_ScreenShot = new QPushButton("Make Screenshot", Dialog_Screenshot);
    Make_ScreenShot->setFixedSize(180,90);
    Dialog_Screenshot->move(600,380);
    //Make_ScreenShot->setVisible(false);*/



    connect(group_setLinks, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(clicked_LinkButtons(QAbstractButton*)));
    connect(group_ip, SIGNAL(buttonReleased(QAbstractButton*)), this, SLOT(Editing_IP(QAbstractButton*)));
    connect(edit_ip, SIGNAL(apply_net()), this,SLOT(Write_IP()));
    connect(upgrate_soft, SIGNAL(released()), this, SLOT(Upgrade_Soft()));
    connect(measure_height, SIGNAL(released()), this, SLOT(measure_Height()));
    connect(measure_Button, SIGNAL(released()), this, SLOT(Get_Image()));
    //connect(Paint_Mask, SIGNAL(toggled(bool)), image_Widget, SLOT(Optic_Mask(bool)));
    connect(Paint_Mask, SIGNAL(toggled(bool)), image_Widget, SLOT(Optic_Mask(bool)));
    connect(Fluor_Box, SIGNAL(currentIndexChanged(int)), this, SLOT(Change_Fluor(int)));
    connect(Exposure, SIGNAL(released()), this, SLOT(Editing_Expo()));
    connect(save_Expo_Button, SIGNAL(released()), this, SLOT(Save_Exposure()));
    //connect(Exposure, SIGNAL())

    //connect(make_screenshot, SIGNAL(clicked(bool)), this, SLOT(Create_ScreenShot()));

    //...
    Tab_Settings->addTab(Link_Type, QIcon(":/images/connection-32.png"), "");
    Tab_Settings->addTab(IP_Address, QIcon(":/images/ip-32.png"), "");
    Tab_Settings->addTab(Device_Settings, QIcon(":/images/tools_32.png"), "");
    Tab_Settings->addTab(Diagnostic, QIcon(":/images/eye_32.png"), "");
    Tab_Settings->addTab(Upgrate, QIcon(":/images/upgrade-32.png"), "");
    //Tab_Settings->addTab(ScreenShot, QIcon(":/images/upgrade-32.png"), "");    

    //...
    Read_IP();

    //...
    COEF_EXPO_v4 = 0.154;


}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Settings_page::~Settings_page()
{
    delete Image;

    delete List_Protocols;
    delete message_settings;
    delete edit_ip;
    delete Choice_Type;
    delete SettingsGroupBox;
}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Settings_page::readsettings()
{
    /*translator.load(":/translations/settings_page_ru.qm");
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
       translator.load(":/translations/settings_page_ru.qm");
    }
    if(lang == "en")
    {
       translator.load(":/translations/settings_page_en.qm");
    }

    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//--- Slot clicked_Buttons(QAbstractButton *button)
//-----------------------------------------------------------------------------
void Settings_page::clicked_LinkButtons(QAbstractButton *button)
{
    foreach(QAbstractButton *b, group_setLinks->buttons())
    {
        b->blockSignals(true);
        b->setChecked(b == button);
        b->blockSignals(false);
    }

    qApp->processEvents();
    repaint();

    if(button == Ethernet_Button) {emit changeLink(3);} //  Sleep(1000);  emit RefreshInfoDevice();}
    if(button == USB_Button) emit changeLink(4);
    qApp->processEvents();
}
//-----------------------------------------------------------------------------
//--- Read_IP()
//-----------------------------------------------------------------------------
void Settings_page::Read_IP()
{
    QString text;
    QStringList list;
    QFile file("/etc/network/interfaces");
    QByteArray data;

    int id = 0;

    if(file.open(QIODevice::ReadOnly))
    {
       data = file.readAll();
       list = QString(data).split("\n");
    }

    //qDebug() << "interfaces: IP "  << QString(data);
    if(list.size())
    {
        foreach(text, list)
        {
            //qDebug() << text;
            text = text.trimmed();
            if(text.startsWith("iface eth0 inet static"))
            {
                id = 1; // next address
                continue;
            }
            switch(id)
            {
            default:
            case 0:
                        break;
            case 1:                 // address
                        if(text.startsWith("address"))
                        {
                            text.remove("address");
                            id = 2; // next netmask
                            ip_address->setText(text.trimmed());
                            //emit send_IP(text.trimmed());
                        }
                        break;

            case 2:                 // netmask

                        if(text.startsWith("netmask"))
                        {
                            text.remove("netmask");
                            id = 3;
                            netmask->setText(text.trimmed());
                        }
                        break;

            case 3:                 // getaway

                        if(text.startsWith("gateway"))
                        {
                            text.remove("gateway");
                            id = -1;
                            gateway->setText(text.trimmed());
                        }
                        break;
            }

            if(id < 0) break;
        }
    }
}
//-----------------------------------------------------------------------------
//--- Write_IP()
//-----------------------------------------------------------------------------
void Settings_page::Write_IP()
{
    QString text = "address " + ip_address->text() + "\nnetmask " + netmask->text() + "\ngateway " + gateway->text();
    QFile file("/mnt/ramdisk/interfaces");

    if(file.open(QIODevice::WriteOnly))
    {
        file.write(text.toLatin1().data());
        file.close();

        QFile file_req("/mnt/ramdisk/ctrl.req");
        text = "NETW";
        if(file_req.open(QIODevice::WriteOnly))
        {
            file_req.write(text.toLatin1().data());
            file_req.close();
        }
    }
}

//-----------------------------------------------------------------------------
//--- GetLogData(QString data)
//-----------------------------------------------------------------------------
void Settings_page::GetLogData(QString data)
{
    if(data.isEmpty()) return;

    QString str;
    QStringList list = data.split("\n");

    if(View_cmd->count() > 300) View_cmd->clear();


    foreach(str, list)
    {
        if(str.trimmed().length()) View_cmd->addItem(str);
    }
    View_cmd->scrollToBottom();
}
//-----------------------------------------------------------------------------
//--- slot_RunStart()
//-----------------------------------------------------------------------------
void Settings_page::slot_RunStart()
{
    int i;

    for(i=Tab_Settings->count()-1; i>=0; i--)
    {
        if(Tab_Settings->widget(i) == Link_Type)  Tab_Settings->removeTab(i);
    }
}
//-----------------------------------------------------------------------------
//--- slot_RunStop()
//-----------------------------------------------------------------------------
void Settings_page::slot_RunStop()
{
    int i;
    QVector<QWidget*> list;

    for(i=0; i<Tab_Settings->count(); i++) list.append(Tab_Settings->widget(i));
    if(!list.contains(Link_Type)) Tab_Settings->insertTab(0, Link_Type, QIcon(":/images/connection-32.png"), "");
}
//-----------------------------------------------------------------------------
//--- Get_RefreshInfoDevice()
//-----------------------------------------------------------------------------
void Settings_page::Get_RefreshInfoDevice()
{
    bool ok;
    int i;
    QString text;
    QString fluor_name[COUNT_CH] = FLUOR_NAME;
    QString mask =  map_InfoDevice->value(INFODEV_devMask,"");
    int active_Channels = mask.toInt(&ok, 16);

    qDebug() << "mask: " << mask << *Expozition;
    //qDebug() << "map_InfoDevice" << *map_InfoDevice;

    // device_hw
    version_HW = map_InfoDevice->value("device_hw", "v3.0");
    if(version_HW.contains("v4.0"))
    {
        BUF_Video.clear();
        BUF_Video.resize(640*480);
        BUF_Video.fill(0);
    }

    // Count_Tubes
    int count;
    text = map_InfoDevice->value(INFODEV_serName,"");
    int k = text.trimmed().mid(1,1).toInt();
    switch(k)
    {
    default:
    case 5:     count = 96;    break;
    case 6:     count = 384;   break;
    case 7:     count = 48;    break;
    case 8:     count = 192;    break;
    }
    Count_Tubes = count;


    // Fluor_Box
    int id = Fluor_Box->currentIndex();
    Initial_Expo.clear();

    Fluor_Box->blockSignals(true);
    QIcon icon;
    Fluor_Box->clear();
    for(i=0; i<COUNT_CH; i++)
    {
       Fluor_Box->addItem(fluor_name[i]);
       switch(i)
       {
       case 0:  icon.addFile(":/images/channels/fam_flat.png");   break;
       case 1:  icon.addFile(":/images/channels/hex_flat.png");   break;
       case 2:  icon.addFile(":/images/channels/rox_flat.png");   break;
       case 3:  icon.addFile(":/images/channels/cy5_flat.png");   break;
       case 4:  icon.addFile(":/images/channels/cy55_flat.png");   break;
       default: icon.addFile(NULL);   break;
       }
       Fluor_Box->setItemIcon(i,icon);

       if(!(active_Channels & (0x01<<i)))
       {
          Fluor_Box->setItemData(i,0,Qt::UserRole - 1);
       }
       Initial_Expo.append(Expozition->at(i*2));
     }
    //qDebug() << "Expo: " << Initial_Expo;

    if(id < 0) id = 0;
    Fluor_Box->setCurrentIndex(id);

    text = QString("%1 %2").arg(Expozition->at(id*2)).arg(tr("ms"));
    Exposure->setText(text);

    Fluor_Box->blockSignals(false);

    Check_ExpoForSave();
}
//-----------------------------------------------------------------------------
//--- Change_Fluor(int ch)
//-----------------------------------------------------------------------------
void Settings_page::Change_Fluor(int ch)
{
    Clear_Image();

    if(ch < 0) ch = 0;

    QString text = QString("%1 %2").arg(Initial_Expo.at(ch)).arg(tr("ms")); //   arg(Expozition->at(ch*2));
    Exposure->setText(text);
}
//-----------------------------------------------------------------------------
//--- Check_ExpoForSave()
//-----------------------------------------------------------------------------
bool Settings_page::Check_ExpoForSave()
{
    int i;
    bool res = false;

    for(i=0; i<COUNT_CH; i++)
    {
        if(Expozition->at(i*2) != Initial_Expo.at(i))
        {
            res = true;
            break;
        }
    }

    save_Expo_Button->setDisabled(!res);
    save_Expo_Button->update();
    update();
    qApp->processEvents();

    return(res);
}

//-----------------------------------------------------------------------------
//--- Save_Exposure()
//-----------------------------------------------------------------------------
void Settings_page::Save_Exposure()
{
    int id;
    quint16 value;
    QString text = tr("Do you want to SAVE the current exposures?");
    QString str = "";

    double coef_expo = (double)(COEF_EXPO);
    if(version_HW.contains("v4.0")) coef_expo = COEF_EXPO_v4;

    foreach(value, Initial_Expo)
    {
        if(str.size()) str += ",";
        str += QString::number(value);
    }
    text += "\r\n(" + str + ")";


    message_settings->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    message_settings->setIcon(QMessageBox::Question);

    message_settings->setText(text);
    id = message_settings->exec();

    if(id == QMessageBox::Yes)
    {
        str = "";
        foreach(value, Initial_Expo)
        {
            value = qRound((double)(value)/coef_expo);
            str += QString(" %1").arg(value);
            value /= COEF_EXPO_1;
            str += QString(" %1").arg(value);
        }
        str = str.trimmed();

        emit SaveExpo(1,str);
    }


}

//-----------------------------------------------------------------------------
//--- Clear_Image()
//-----------------------------------------------------------------------------
void Settings_page::Clear_Image()
{
    BUF_Video.fill(0);

    Image->fill(Qt::white);
    image_Widget->update();
}
//-----------------------------------------------------------------------------
//--- Get_Image()
//-----------------------------------------------------------------------------
void Settings_page::Get_Image()
{
    bool ok;
    QStringList list;
    int ch = Fluor_Box->currentIndex();

    QString text = Exposure->text();
    list = text.split(" ");

    text = list.at(0);
    int expo = text.toInt(&ok);
    qDebug() << "expo: " << text.toInt(&ok);

    Clear_Image();
    emit MakeMeasure_Request(ch, expo, 2);
}
//-----------------------------------------------------------------------------
//--- Get_Image()
//-----------------------------------------------------------------------------
void Settings_page::Get_Picture(QMap<QString, QByteArray> *map)
{    
    if(map->size() == 0) return;

    int num_sec = div(Count_Tubes,96).quot;
    if(num_sec < 1) num_sec = 1;

    QByteArray buf = map->value(GETPIC_VIDEO, NULL);
    int count = buf.size();

    int videoBuf_size = 256*1023*2;
    if(version_HW.contains("v4.0")) videoBuf_size = 640*480*2;

    if(count != videoBuf_size)
    {
        message_settings->setStandardButtons(QMessageBox::Ok);
        message_settings->setIcon(QMessageBox::Warning);
        message_settings->setText(QString("Attention! Invalid Buf_Video size: %1 (%2)").arg(count).arg(videoBuf_size));
        message_settings->exec();

        buf.clear();
        map->clear();
        return;
    }

    QByteArray buf_digit = map->value(GETPIC_DATA, NULL);
    int count_digit = buf_digit.size();

    if(count_digit != 512*num_sec)
    {
        message_settings->setStandardButtons(QMessageBox::Ok);
        message_settings->setIcon(QMessageBox::Warning);
        message_settings->setText(QString("Attention! Invalid Buf_Digit size: %1 (%2)").arg(count_digit).arg(512*num_sec));
        message_settings->exec();

        buf_digit.clear();
        map->clear();
        return;
    }

    //...
    BUF_Video.fill(0);
    QVector<ushort> vec(count/2);
    memcpy(vec.data(), buf.data(), count);

    Treat_VideoImage(vec, BUF_Video);
    Draw_VideoImage(BUF_Video);

    image_Widget->update();

}
//-----------------------------------------------------------------------------
//--- Treat_VideoImage a->b
//-----------------------------------------------------------------------------
void Settings_page::Treat_VideoImage(QVector<ushort> &a, QVector<int> &b)
{
    int left_offset = LEFT_OFFSET;
    int w_image = W_IMAGE;
    int h_realimage = H_REALIMAGE;
    int w_realimage = W_REALIMAGE;

    if(version_HW.contains("v4.0"))
    {
        left_offset = 0;
        w_image = 640;
        h_realimage = 480;
        w_realimage = 640;
    }

    //-------
    int i,j;
    int k,m;
    int left = left_offset;
    int width_left;

    width_left = left + w_image;

    k=0;
    for(i=0; i<h_realimage; i++)
    {
        if(!version_HW.contains("v4.0") && (i<5 || i>296)) continue;

        m=0;
        for(j=0; j<w_realimage; j++)
        {
            if(j<left || j>width_left-1) continue;
            b.replace(k*w_image + m, a.at(i*w_realimage + j));
            m++;
        }
        k++;
    }
}
//-----------------------------------------------------------------------------
//--- Draw_VideoImage
//-----------------------------------------------------------------------------
void Settings_page::Draw_VideoImage(QVector<int> &a)
{    
    int w_image = W_IMAGE;
    int h_image = H_IMAGE;
    int h_realimage = H_REALIMAGE;
    int w_realimage = W_REALIMAGE;

    if(version_HW.contains("v4.0"))
    {
        w_image = 640;
        h_image = 480;
        h_realimage = 480;
        w_realimage = 640;
    }

    //----
    int i,j;
    int num = 0;
    int size = w_image * h_image;
    QRgb pb = QColor(255,0,0).rgba();
    int pixel;

    QImage image(w_image, h_image, QImage::Format_RGB32);

    for(i=0; i<h_image; i++)
    {
        QRgb *line = reinterpret_cast<QRgb*>(image.scanLine(i));
        for(j=0; j<w_image; j++)
        {
            pixel = a.at(num);
            pixel = pixel >> 4;
            pb = qRgb(pixel,pixel,pixel);
            line[j] = pb;
            num++;
        }
    }

    // Scaled image: ...
    *Image = image.scaled(W_IMAGE_COEF, H_IMAGE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

}
//-----------------------------------------------------------------------------
//--- Draw_Mask(int rep)
//-----------------------------------------------------------------------------
void Settings_page::Draw_Mask(QPainter *p)
{
    int i;
    QPen pen;
    QPoint center;
    QString text;
    int x,y;
    int select = -1;
    int type_dev = Count_Tubes;

    if(!Paint_Mask->isChecked()) return;

    double coef_zoom = 1.;
    double coef_image = COEF_IMAGE;
    if(version_HW.contains("v4.0"))
    {
        coef_image = 1.;
        coef_zoom = 1.64;       // 1.64 = 640/390 or 480/292
    }

    //if(Rep >= 0) select = rep_Point.at(Rep);

    pen.setColor(Qt::red);
    pen.setWidth(1);
    p->setPen(pen);

    int id = 0; //Set_Fluor->currentIndex();
    short offset_x = offset_XY->at(id*2);
    short offset_y = offset_XY->at(id*2+1);

    //qDebug() << "offset: " << offset_x << offset_y;

    //... draw mask ...
    for(i=0; i<type_dev; i++)
    {
        if(select == i)
        {
            pen.setWidth(2);
            p->setPen(pen);
        }
        center.setX(Round((double)(XY->at(2*i) + offset_x)/(coef_image*coef_zoom)));
        center.setY((XY->at(2*i+1) - offset_y)/coef_zoom);
        p->drawEllipse(center,Round((double)(*Rx)/(coef_image*coef_zoom)),*Ry/coef_zoom);
        if(pen.width() > 1)
        {
            pen.setWidth(1);
            p->setPen(pen);
        }
    }

    //... draw Label ...
    /*p->setFont(QFont("Times New Roman", 8, QFont::Bold));
    for(i=0; i<4; i++)
    {
        text = list_Label.at(i);

        x = XY.at(2*rep_Point.at(i));
        y = XY.at(2*rep_Point.at(i)+1);
        if(div(i,2).rem == 0) x -= Rx*3.5;
        else x += Rx*1.8;
        x /= COEF_IMAGE;
        center.setX(x);
        center.setY(y);
        p->drawText(center, text);
    }*/

}
//-----------------------------------------------------------------------------
//--- Round(double) -> int
//-----------------------------------------------------------------------------
int Settings_page::Round(double val)
{
    int res;

    res = qFloor(val+0.5);

    return(res);
}
//-----------------------------------------------------------------------------
//--- measure_Height()
//-----------------------------------------------------------------------------
void Settings_page::measure_Height()
{
    emit meas_HeightTubes();
}

//-----------------------------------------------------------------------------
//--- Editing_IP()
//-----------------------------------------------------------------------------
void Settings_page::Editing_IP(QAbstractButton *button)
{
    edit_ip->state_Edit = sIP;
    edit_ip->edit_text->setText(button->text());
    edit_ip->button = button;
    edit_ip->exec();
}
//-----------------------------------------------------------------------------
//--- Editing_Expo()
//-----------------------------------------------------------------------------
void Settings_page::Editing_Expo()
{
    bool ok;
    QString text;
    QStringList list;
    int id = Fluor_Box->currentIndex();

    list = Exposure->text().split(" ");
    text = list.at(0);
    edit_ip->state_Edit = sExpo;
    edit_ip->edit_text->setText(text);
    edit_ip->button = (QAbstractButton*)Exposure;
    edit_ip->exec();

    // validate expo value:  100 <= value <= 10000
    unsigned int value = Exposure->text().toInt(&ok);
    if(!ok) value = Initial_Expo.at(id);

    if(value < 100) value = 100;
    if(value > 10000) value = 10000;
    Initial_Expo.replace(id, value);
    Exposure->setText(QString("%1 %2").arg(value).arg(tr("ms")));
    Exposure->repaint();
    Exposure->update();
    update();
    qApp->processEvents();

    qDebug() << "valid expo: " << Initial_Expo;

    Check_ExpoForSave();

}

//-----------------------------------------------------------------------------
//--- Upgrade_Soft()
//-----------------------------------------------------------------------------
void Settings_page::Upgrade_Soft()
{
    //QString fn = QFileDialog::getOpenFileName(this, "Open file");
    int type;

    Choice_Type->mask = 0x00f0;
    Choice_Type->open();
    Choice_Type->exec();
    Choice_Type->hide();

    type = Choice_Type->type;

    switch(type)
    {
    default:    break;
    case 1:     open_USBProtocol(); break;
    }
}
//-----------------------------------------------------------------------------
//--- open_USBProtocol()
//-----------------------------------------------------------------------------
void Settings_page::open_USBProtocol()
{
    int i;
    QMap<QString,QString> map_USB;
    QMap<QString,QString> map_USBfile;
    QFileInfo fn;    
    QString text;
    QDir usb_Dir("/home/user/prog/dev_gui/usb-flash");
    QString fileName = "";
    int num = 0;
    QStringList header_name;

    int usb_find = system("mount | grep usb-flash");
    if(usb_find != 0)
    {
        message_settings->setStandardButtons(QMessageBox::Ok);
        message_settings->setIcon(QMessageBox::Warning);
        message_settings->button(QMessageBox::Ok)->animateClick(7000);
        text = tr("USB-Flash is absent!");
        message_settings->setText(text);
        message_settings->exec();
        repaint();
        qApp->processEvents();

        return;
    }

    foreach(QString fileName, usb_Dir.entryList(QDir::Files))
    {
        fn.setFile(usb_Dir, fileName);
        if(fn.exists() && fn.suffix() == "tar")
        {
            num++;
            text = QString::number(num);
            map_USB.insert(text, fn.fileName() + "; ");
            map_USBfile.insert(text, fn.absoluteFilePath());
        }
    }

    List_Protocols->Load_Protocols(&map_USB, true);
    header_name << tr("Name (update files *.tar)") << "" << "";
    List_Protocols->tree_Protocols->setHeaderLabels(header_name);
    List_Protocols->tree_Protocols->setColumnWidth(1,0);
    List_Protocols->tree_Protocols->setColumnWidth(2,0);
    List_Protocols->tree_Protocols->setColumnWidth(0,599);

    List_Protocols->open();
    List_Protocols->exec();
    List_Protocols->hide();
    qApp->processEvents();

    if(List_Protocols->Key_result.isEmpty()) {;}
    else
    {
        fileName = map_USBfile.value(List_Protocols->Key_result);
        if(!fileName.isEmpty())
        {
            QFile file("/mnt/ramdisk/update");
            if(file.open(QIODevice::WriteOnly))
            {
                file.write(fileName.toLatin1().data());
                file.close();

                QFile file_req("/mnt/ramdisk/ctrl.req");
                text = "SWUP";
                if(file_req.open(QIODevice::WriteOnly))
                {
                    file_req.write(text.toLatin1().data());
                    file_req.close();

                    emit update_Software();
                }
            }
        }
    }

    map_USB.clear();
    map_USBfile.clear();
}

//-----------------------------------------------------------------------------
//--- Create_ScreenShot()
//-----------------------------------------------------------------------------
void Settings_page::Create_ScreenShot()
{
    /*bool state = make_screenshot->isChecked();
    if(state) Dialog_Screenshot->show();
    else Dialog_Screenshot->hide();*/
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Image_Widget::Image_Widget(QImage *picture, QWidget *parent): QWidget(parent)
{
    p_video = (Settings_page*)parent;
    image = picture;
    state = false;
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Image_Widget::paintEvent(QPaintEvent *e)
{
    QPoint center;

    QPainter painter(this);
    QRect rect = image->rect();
    rect.setWidth(image->width() - 2);
    rect.setHeight(image->height() - 2);

    //... image ...
    painter.drawImage(0,0,*image);

    //... mask ...
    if(state)
    {
       p_video->Draw_Mask(&painter);
    }

    //
    painter.drawRect(rect);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Image_Widget::Optic_Mask(bool s)
{
    state = s;
    update();
}
