#include "protocol_page.h"
#include "request_dev.h"

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Protocol_page::Protocol_page(QWidget *parent):  QMainWindow(parent)
{
    Prot = new rt_Protocol();

    readsettings();

    ProtocolGroupBox = new QGroupBox(this);
    ProtocolGroupBox->setObjectName("Transparent");
    setCentralWidget(ProtocolGroupBox);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(2);

    ProtocolGroupBox->setLayout(layout);

    QFont f = qApp->font();
    f.setBold(true);
    f.setPointSize(16);

    Name_Pro = new QLabel(tr("No Protocol..."));
    Name_Pro->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    Name_Pro->setAlignment(Qt::AlignCenter);
    Name_Pro->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC)}");
    Name_Pro->setFont(f);

    Clear_Pro = new QPushButton(QIcon(":/images/clear_flat_16.png"), NULL, this);
    //Clear_Pro->setObjectName("Transparent");
    Clear_Pro->setIconSize(QSize(48,48));
    Clear_Pro->setFixedSize(48,48);
    Clear_Pro->setFlat(true);
    Clear_Pro->setToolTip(tr("Clear Protocol"));
    connect(Clear_Pro, SIGNAL(released()),this, SLOT(clear_Protocol()));

    Open_Pro = new QPushButton(QIcon(":/images/open_flat.png"), NULL, this);
    //Open_Pro->setObjectName("Transparent");
    Open_Pro->setIconSize(QSize(48,48));
    Open_Pro->setFixedSize(48,48);
    //Open_Pro->setFlat(true);
    Open_Pro->setToolTip(tr("Open Protocol"));
    connect(Open_Pro, SIGNAL(released()), this, SLOT(open_Manually()));

    /*OpenUSB_Pro = new QPushButton(QIcon(":/images/open_usb.png"), NULL, this);
    OpenUSB_Pro->setIconSize(QSize(48,48));
    OpenUSB_Pro->setFixedSize(48,48);
    connect(OpenUSB_Pro, SIGNAL(released()), this, SLOT(open_USBProtocol()));
    */


    QHBoxLayout *layout_protocol = new QHBoxLayout;
    layout_protocol->setSpacing(0);
    layout_protocol->addWidget(Name_Pro,1);
    layout_protocol->addWidget(Clear_Pro);
    layout_protocol->addWidget(Open_Pro);
    //layout_protocol->addWidget(OpenUSB_Pro);

    Tab_Pro = new QTabWidget(this);
    Tab_Pro->setStyleSheet("QTabWidget::tab-bar{alignment: right;}");
    Tab_Pro->setIconSize(QSize(48,48));

    Program_group = new QGroupBox(this);
    Plate_group = new QGroupBox(this);
    Sample_group = new QGroupBox(this);
    //TestSample_group = new QGroupBox(this);
    Info_group = new QGroupBox(this);

    //... Info
    Info = new Protocol_Info(this);
    QHBoxLayout *layout_info = new QHBoxLayout;
    layout_info->setMargin(2);
    Info_group->setLayout(layout_info);
    Info_group->setObjectName("Transparent");
    layout_info->addWidget(Info);

    //... Program
    QHBoxLayout *layout_program = new QHBoxLayout;
    Program_group->setLayout(layout_program);
    Program_group->setObjectName("Transparent");
    Plot_Program = new Plot_ProgramAmpl(this);
    Program_scheme = new Protocol_Program(QColor(1,1,1,1), this);
    layout_program->setSpacing(2);
    layout_program->setMargin(2);
    layout_program->addWidget(Plot_Program);
    layout_program->addWidget(Program_scheme);

    //... Plate ...
    Plate = new PlateTableWidget(0,0, this);
    Plate->setFocusPolicy(Qt::NoFocus);
    QHBoxLayout *layout_plate = new QHBoxLayout;
    layout_plate->setMargin(2);
    Plate_group->setLayout(layout_plate);
    Plate_group->setObjectName("Transparent");
    layout_plate->addWidget(Plate);
    //QFont f_plate("Times New Roman", 6);
    //Plate->setFont(f_plate);

    //... Samples ...
    Samples = new Protocol_Samples(false, this);
    Samples->setFocusPolicy(Qt::NoFocus);
    QHBoxLayout *layout_samples = new QHBoxLayout;
    layout_samples->setMargin(2);
    Sample_group->setLayout(layout_samples);
    Sample_group->setObjectName("Transparent");
    layout_samples->addWidget(Samples);

    Tab_Pro->addTab(Program_group, QIcon(":/images/program.png"), "");
    Tab_Pro->addTab(Sample_group, QIcon(":/images/sample.png"), "");
    Tab_Pro->addTab(Plate_group, QIcon(":/images/plate.png"), "");
    //Tab_Pro->addTab(TestSample_group, QIcon(":/images/Info.png"), "");
    Tab_Pro->addTab(Info_group, QIcon(":/images/Info.png"), "");

    layout->addLayout(layout_protocol);
    layout->addSpacing(2);
    layout->addWidget(Tab_Pro, 1);


    //... GIF ...
    label_gif = new QLabel(Tab_Pro);
    label_gif->setFixedSize(48,48);
    label_gif->raise();
    obj_gif = new QMovie(":/images/wait_1.gif");
    label_gif->setMovie(obj_gif);
    label_gif->setVisible(false);

    //... List Protocols ...
    //List_Protocols = new Protocol_List(this);
    //List_Protocols->setModal(true);
    //List_Protocols->hide();
    //List_Protocols = NULL;

    //... Choice Type ...
    //Choice_Type = new ChoiceType_Dialog(this);
    //Choice_Type->hide();
    //Choice_Type = NULL;

    //... Message ...
    //setStyleSheet("QMessageBox QPushButton{background-color: #FAFAFA;}");
    message_pro = new QMessageBox(this);

    //... Error Label ...
    ERROR_Label = new QLabel("", Tab_Pro);
    ERROR_Label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ERROR_Label->setAlignment(Qt::AlignCenter);
    ERROR_Label->setWordWrap(true);
    QFont Font("Times New Roman", 14);
    ERROR_Label->setFont(Font);
    ERROR_Label->setStyleSheet("QLabel {color : red; border: 1px solid red; background-color: white;}");
    ERROR_Label->setVisible(false);


    //protocol_Label = new QLabel("", this);
    //QFont Font("Times New Roman", 18, QFont::Bold);
    //protocol_Label->setFont(Font);


}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Protocol_page::~Protocol_page()
{
    delete obj_gif;
    delete label_gif;
    delete message_pro;

    delete Samples;
    delete Program_scheme;
    delete Plot_Program;
    delete Program_group;
    //delete Choice_Type;
    delete Plate;
    delete Info;

    //if(List_Protocols) delete List_Protocols;

    delete Plate_group;
    delete Sample_group;
    //delete TestSample_group;
    delete Info_group;
    delete Tab_Pro;

    //delete protocol_Label;
    delete ProtocolGroupBox;

    //List_Protocols = NULL;


    delete Prot;
}
//-----------------------------------------------------------------------------
//--- keyPressEvent(QKeyEvent *e)
//-----------------------------------------------------------------------------
/*void Protocol_page::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "Protocol_page KeyPress: " << e->key();

    e->accept();
}*/

//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Protocol_page::readsettings()
{
    /*translator.load(":/translations/protocol_page_ru.qm");
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
       translator.load(":/translations/protocol_page_ru.qm");
    }
    if(lang == "en")
    {
       translator.load(":/translations/protocol_page_en.qm");
    }

    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//--- find_Protocol(QString barcode)
//-----------------------------------------------------------------------------
void Protocol_page::find_Protocol(QString barcode)
{
    QString text;
    QStringList list_item;
    bool find = false;

    foreach(QString key, list_protocols->keys())
    {
        text = list_protocols->value(key);
        list_item = text.split(";");
        if(barcode == list_item.at(1))
        {
            open_Protocol(key);
            find = true;
            break;
        }
    }

    if(!find)
    {
        clear_Protocol();

        message_pro->setStandardButtons(QMessageBox::Ok);
        message_pro->setIcon(QMessageBox::Warning);
        message_pro->button(QMessageBox::Ok)->animateClick(10000);
        text = QString("%1").arg(tr("Protocol is not found!"));
        message_pro->setText(text);
        message_pro->exec();
    }

}
//-----------------------------------------------------------------------------
//--- open_USBProtocol()
//-----------------------------------------------------------------------------
void Protocol_page::open_USBProtocol()
{
    QDomDocument    doc;
    QDomElement     root;
    QDomNode        child;
    QDomNode        node;
    QDomNode        item;

    QMap<QString,QString> map_USB;
    QMap<QString,QString> map_USBfile;
    QString text;
    QString name, barcode, reg_number;
    QFileInfo fn;
    QFile file;
    QDir usb_Dir("/home/user/prog/dev_gui/usb-flash");
    QString fileName = "/home/user/prog/dev_gui/usb-flash/bacscreen.rt";
    int num = 0;

    int usb_find = system("mount | grep usb-flash");
    if(usb_find != 0)
    {
        emit sRejimeDevButtons(0,-1);
        message_pro->setStandardButtons(QMessageBox::Ok);
        message_pro->setIcon(QMessageBox::Warning);
        message_pro->button(QMessageBox::Ok)->animateClick(7000);
        text = tr("USB-Flash is absent!");
        message_pro->setText(text);
        message_pro->exec();
        repaint();
        qApp->processEvents();

        emit sRejimeDevButtons(0,0);

        return;
    }


    clear_Protocol();
    //emit sWait_Process(wOpen, 100, tr("Open USB Protocol..."));

    foreach(QString fileName, usb_Dir.entryList(QDir::Files))
    {
        fn.setFile(usb_Dir, fileName);
        if(fn.exists() && fn.suffix() == "rt")
        {
            num++;
            text = QString::number(num);
            map_USB.insert(text, fn.fileName() + "; ");
            map_USBfile.insert(text, fn.absoluteFilePath());

            //qDebug() << "name: " << fn.baseName();

            /*file.setFileName(fn.absoluteFilePath());
            if(file.exists() && file.open(QIODevice::ReadOnly))
            {
                if(!doc.setContent(&file))
                {
                    file.close();
                    continue;
                }
                file.close();

                root = doc.documentElement();
                name = barcode = reg_number = "";
                name = root.firstChildElement("name").text();
                barcode = root.firstChildElement("barcode").text();
                reg_number = root.firstChildElement("regNumber").text();
                doc.clear();

                qDebug() << "name: " << name << barcode << reg_number << file.fileName();

                if(reg_number.trimmed().isEmpty() || name.isEmpty()) continue;

                text = QString("%1;%2").arg(name).arg(barcode);
                map_USB.insert(reg_number, text);
            }*/

        }
    }

    List_Protocols = new Protocol_List(this);
    List_Protocols->Load_Protocols(&map_USB, true);

    emit sRejimeDevButtons(0,2);
    connect(List_Protocols, SIGNAL(sKeyPress(int)), this, SLOT(slot_KeyPress(int)));

    //List_Protocols->open();
    List_Protocols->exec();
    //List_Protocols->hide();
    qApp->processEvents();

    List_Protocols->disconnect();

    if(List_Protocols->Key_result.isEmpty()) {;}
    else
    {
        fileName = map_USBfile.value(List_Protocols->Key_result);
        qDebug() << "Key_results: " << List_Protocols->Key_result;

        emit sWait_Process(wOpenFile, 100, tr("Open USB Protocol..."));
        load_fromXML(fileName);
        emit sFinished_WaitProcess();
        qApp->processEvents();
    }
    delete List_Protocols;

    map_USB.clear();
    map_USBfile.clear();

    emit sRejimeDevButtons(0,0);

}
//-----------------------------------------------------------------------------
//--- slot_KeyPress(int key)
//-----------------------------------------------------------------------------
void Protocol_page::slot_KeyPress(int key)
{
    qDebug() << "Protocol: Get KeyPress: " << key;
    emit sKeyPress(key);
}

//-----------------------------------------------------------------------------
//--- open_Manually()
//-----------------------------------------------------------------------------
void Protocol_page::open_Manually()
{
    int type;

    if(Choice_Type)
    {
        qDebug() << "Delete Choice_Type...";
        //delete Choice_Type;
    }
    //if(Choice_Type != NULL)  {delete Choice_Type; Choice_Type = NULL;}
    Choice_Type = new ChoiceType_Dialog(this);
    Choice_Type->mask = 0x0fff;

    emit sRejimeDevButtons(0,1);
    connect(Choice_Type, SIGNAL(sKeyPress(int)), this, SLOT(slot_KeyPress(int)));

    //Choice_Type->setFocusPolicy(Qt::StrongFocus);


    //Choice_Type->setFocus();
    Choice_Type->exec();
    //Choice_Type->open();

    //Choice_Type->hide();

    type = Choice_Type->type;
    Choice_Type->disconnect();
    //delete Choice_Type;



    switch(type)
    {
    case 0:     open_Protocol();   break;
    case 1:     open_USBProtocol(); break;
    case 2:     open_localProtocol(); break;

    default:    emit sRejimeDevButtons(0,0);
                break;
    }



}
//-----------------------------------------------------------------------------
//--- open_localLastRun()
//-----------------------------------------------------------------------------
bool Protocol_page::open_localLastRun()
{
    bool state = false;
    QDir dir_input(qApp->applicationDirPath() + "/device");
    QString fileName = "run.rt";
    QFileInfo fi;
    QString text;

    fi.setFile(dir_input, fileName);
    if(fi.exists())
    {
        state = true;
        //emit sWait_Process(wOpenFile, 100, tr("Open Local Protocol..."));
        load_fromXML(fi.absoluteFilePath());
        //emit sFinished_WaitProcess();
        qApp->processEvents();
    }
    else
    {
        clear_Protocol();

        message_pro->setStandardButtons(QMessageBox::Ok);
        message_pro->setIcon(QMessageBox::Critical);
        message_pro->button(QMessageBox::Ok)->animateClick(7000);
        text = QString("%1: run.rt").arg(tr("Error opening Last Run"));
        message_pro->setText(text);
        message_pro->exec();
        repaint();
    }

    return(state);
}

//-----------------------------------------------------------------------------
//--- open_localProtocol()
//-----------------------------------------------------------------------------
void Protocol_page::open_localProtocol()
{
    QMap<QString,QString> map_USB;
    QMap<QString,QString> map_USBfile;
    QString text;
    QString fileName;
    QDir dir_input(qApp->applicationDirPath() + "/input");
    QFileInfo fi;
    int num = 0;

    foreach(QString fileName, dir_input.entryList(QDir::Files))
    {
         fi.setFile(dir_input, fileName);
         if(fi.exists() && fi.suffix() == "rt")
         {
             num++;
             text = QString::number(num);
             map_USB.insert(text, fi.fileName() + "; ");
             map_USBfile.insert(text, fi.absoluteFilePath());
         }
    }

    //if(List_Protocols) delete List_Protocols;
    List_Protocols = new Protocol_List(this);       //
    //List_Protocols->setAttribute(Qt::WA_DeleteOnClose, false);
    //List_Protocols->setModal(true);

    emit sRejimeDevButtons(0,2);
    connect(List_Protocols, SIGNAL(sKeyPress(int)), this, SLOT(slot_KeyPress(int)));

    List_Protocols->Load_Protocols(&map_USB, true);    
    List_Protocols->exec();

    List_Protocols->disconnect();


    qDebug() << "List_Protocols: " << List_Protocols;

    if(List_Protocols->Key_result.isEmpty()) {;}
    else
    {        
        fileName = map_USBfile.value(List_Protocols->Key_result);
        //qDebug() << "Key_results: " << List_Protocols->Key_result << fileName;

        emit sWait_Process(wOpenFile, 100, tr("Open Local Protocol..."));
        load_fromXML(fileName);
        emit sFinished_WaitProcess();
        qApp->processEvents();
    }


    delete List_Protocols;
    //List_Protocols->deleteLater();

    map_USB.clear();
    map_USBfile.clear();

    emit sRejimeDevButtons(0,0);
}

//-----------------------------------------------------------------------------
//--- open_Protocol()
//-----------------------------------------------------------------------------
void Protocol_page::open_Protocol(QString id)
{
    QVariant returned_Value;
    QVariant id_prot;

    //qDebug() << "system: " << system("mount | grep usb-flash");

    clear_Protocol();
    qApp->processEvents();

    if(id.isEmpty())
    {
        List_Protocols = new Protocol_List(this);
        List_Protocols->Load_Protocols(list_protocols);

        emit sRejimeDevButtons(0,2);
        connect(List_Protocols, SIGNAL(sKeyPress(int)), this, SLOT(slot_KeyPress(int)));
        //List_Protocols->open();
        List_Protocols->exec();
        //List_Protocols->hide();
        qApp->processEvents();
        List_Protocols->disconnect();
        if(!List_Protocols->Key_result.trimmed().isEmpty()) id_prot = List_Protocols->Key_result;

        delete List_Protocols;
    }
    else id_prot = id;


    if(id_prot.toString().size())
    {        
        emit sWait_Process(wOpenFile, 100, tr("Open Protocol..."));
        QObject *obj = (QObject*)(pweb->rootObject());
        QMetaObject::invokeMethod(obj, "getWebProtocol",
                                  Q_RETURN_ARG(QVariant, returned_Value),
                                  Q_ARG(QVariant, id_prot));        
    }


    emit sRejimeDevButtons(0,0);
}
//-----------------------------------------------------------------------------
//--- slot_ChangeLink(int type)
//-----------------------------------------------------------------------------
void Protocol_page::slot_ChangeLink(int type)
{
    int i;
    QVector<QWidget*> list;

    clear_Protocol();

    bool state = true;

    if(type == 3) state = true;
    if(type == 4) state = false;

    Tab_Pro->setCurrentIndex(0);

    if(!state)
    {
        for(i=Tab_Pro->count()-1; i>=0; i--)
        {
            if(Tab_Pro->widget(i) == Sample_group || Tab_Pro->widget(i) == Plate_group)  Tab_Pro->removeTab(i);
        }
    }
    else
    {
        for(i=0; i<Tab_Pro->count(); i++) list.append(Tab_Pro->widget(i));
        if(!list.contains(Sample_group)) Tab_Pro->insertTab(1, Sample_group, QIcon(":/images/sample.png"), "");
        if(!list.contains(Plate_group)) Tab_Pro->insertTab(2, Plate_group, QIcon(":/images/plate.png"), "");
    }
    Open_Pro->setEnabled(state);
    Clear_Pro->setEnabled(state);
}

//-----------------------------------------------------------------------------
//--- clear_Protocol()
//-----------------------------------------------------------------------------
void Protocol_page::clear_Protocol()
{
    ERROR_Label->setText("");
    ERROR_Label->setVisible(false);

    //... Name ...
    Name_Pro->setText(tr("No Protocol..."));
    Name_Pro->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC)}");

    //... Info ...
    Info->clear_Info();

    //... Program ...
    Plot_Program->clear_Program();
    Program_scheme->clear_scheme();

    //... Plate ...
    Plate->clear_Plate();

    //... Samples ...
    Samples->clear_Samples();

    Prot->Clear_Protocol();

    QString text = QString("%1;%2").arg("0").arg(tr(" protocol is absent "));
    emit sStatusProtocol(text);    

    qApp->processEvents();
    QTimer::singleShot(200, this, SLOT(repaint()));
}
//-----------------------------------------------------------------------------
//--- slot_LoadUSBProtocol()
//-----------------------------------------------------------------------------
void Protocol_page::slot_LoadUSBProtocol()
{
    //... Name ...
    Name_Pro->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #C8FFC8, stop: 1 #64FF64)}");
    Name_Pro->setText(Prot->name);

    //... Program ...
    Plot_Program->draw_Program(Prot);
    Program_scheme->draw_Program(Prot);
    qApp->processEvents();

    //... Info ...
    Info->fill_Info(Prot);
    qApp->processEvents();

    QString text = QString("%1;%2").arg("1").arg(Prot->name);
    emit sStatusProtocol(text);

}
//-----------------------------------------------------------------------------
//--- SetPpoperty_WebProtocol(bool web_pro)
//-----------------------------------------------------------------------------
void Protocol_page::SetPpoperty_WebProtocol(rt_Protocol *p, bool web_pro)
{
    rt_Preference *property;
    bool find = false;
    QString text;

    if(!p)  return;

    foreach(property, p->preference_Pro)
    {
        if(property->name == "Web_Protocol")
        {
            text = "";
            if(web_pro) text = p->regNumber;
            property->value = text;
            find = true;
            break;
        }
    }

    if(web_pro && !find)
    {
        property = new rt_Preference;
        property->name = "Web_Protocol";
        property->value = p->regNumber;
        p->preference_Pro.append(property);
    }
}

//-----------------------------------------------------------------------------
//--- load_fromXML(QString fn)
//-----------------------------------------------------------------------------
bool Protocol_page::load_fromXML(QString fn, bool web_pro)
{

    QString kod = "", text;
    bool only_cohfig = true;

    clear_Protocol();

    bool sts = Read_XML(Prot, fn, only_cohfig);
    qApp->processEvents();
    qDebug() << "Read_XML-  status: " << sts << only_cohfig << fn;

    //... Property: Web_Protocol ...
    SetPpoperty_WebProtocol(Prot, web_pro);

    //... Name ...
    Name_Pro->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #C8FFC8, stop: 1 #64FF64)}");
    Name_Pro->setText(Prot->name);

    //... Info ...    
    Info->fill_Info(Prot);
    qApp->processEvents();

    //... Program ...
    Plot_Program->draw_Program(Prot);
    Program_scheme->draw_Program(Prot);
    qApp->processEvents();

    //... Plate ...
    Plate->fill_Plate(Prot);
    qApp->processEvents();

    //... Samples ...    
    Samples->fill_Samples(Prot);
    qApp->processEvents();

    Tab_Pro->setCurrentWidget(Program_group);

    repaint();
    qApp->processEvents();


    //... Check Tests on Equal expozitions, programs, volume ...
    Check_ValidityProtocol(kod);


    //... Check Compatibility ...
    if(!kod.isEmpty() || !Check_Compatibility(kod))
    {
        Name_Pro->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFC8C8, stop: 1 #FF6464)}");
        qApp->processEvents();

        text = QString("%1;%2").arg("0").arg(tr(" protocol is absent "));
        //emit sStatusProtocol(text);

        message_pro->setStandardButtons(QMessageBox::Ok);
        message_pro->setIcon(QMessageBox::Critical);
        message_pro->button(QMessageBox::Ok)->animateClick(7000);
        text = QString("%1: (%2)").arg(tr("Error opening protocol")).arg(kod);
        message_pro->setText(text);
        message_pro->exec();
        repaint();

        ERROR_Label->setText(QString("  %1  ").arg(text));
        //QFontMetrics fm(ERROR_Label->font());
        QRect rect = Tab_Pro->geometry();
        ERROR_Label->setFixedWidth(rect.width()-20);
        ERROR_Label->setFixedHeight(60);
        int y = rect.height()/2;
        int x = 10; //(rect.width() - fm.width(ERROR_Label->text()))/2;
        ERROR_Label->move(x,y);
        ERROR_Label->setVisible(true);
    }
    else
    {
        text = QString("%1;%2").arg("1").arg(Prot->name);        
        emit sStatusProtocol(text);
    }

    emit sFinished_WaitProcess();    
    qApp->processEvents();

}
//-----------------------------------------------------------------------------
//--- Check_ValidityProtocol(QString &kod)
//-----------------------------------------------------------------------------
bool Protocol_page::Check_ValidityProtocol(QString &kod)
{
    int i;
    bool res = true;
    QString text;
    double dvalue, dval;
    bool ok;
    QStringList list;
    QVector<double>             *vec_ExpoTest;
    QVector<QVector<double>*>   Vec_Expo;
    QVector<QString>            *vec_ProgramTest;
    QVector<QVector<QString>*>  Vec_Program;

    //if(Prot->tests.size() == 1) return(true);

    foreach(rt_Test *ptest, Prot->tests)
    {
        // 1. Expo...
        vec_ExpoTest = new QVector<double>;
        vec_ExpoTest->fill(1., COUNT_CH);
        foreach(rt_Preference *property, ptest->preference_Test)
        {
            if(property->name == "exposure_Measurements")
            {
                //qDebug() << "test: " << ptest->header.Name_Test << property->value;
                list = property->value.split(QRegExp("\\s+"), QString::SkipEmptyParts);
                i = 0;
                foreach(text, list)
                {
                    dvalue = text.toDouble(&ok);
                    if(!ok) dvalue = 1.0;
                    vec_ExpoTest->replace(i, dvalue);
                    i++;
                }
                break;
            }
        }
        Vec_Expo.append(vec_ExpoTest);

        // 2. Program...
        vec_ProgramTest = new QVector<QString>;
        *vec_ProgramTest = ptest->header.program;
        vec_ProgramTest->removeFirst();
        Vec_Program.append(vec_ProgramTest);


        // 3. Volume...

    }

    // 1. Expo:
    if(vec_ExpoTest->size() > 1)
    {
        for(i=0; i<COUNT_CH; i++)
        {
            if(Prot->active_Channels & (0xf<<i*4))
            {
                dvalue = Vec_Expo.at(0)->at(i);
                foreach(QVector<double> *vec, Vec_Expo)
                {
                    if(dvalue != vec->at(i))
                    {
                        kod = tr("Exposure");
                        res = false;
                        break;
                    }
                }
            }
            if(!kod.isEmpty()) break;
        }
    }
    expozition_Coeff->clear();
    expozition_Coeff->fill(1, COUNT_CH);
    if(kod.isEmpty())
    {
        for(i=0; i<COUNT_CH; i++) expozition_Coeff->replace(i, Vec_Expo.at(0)->at(i));
    }
    qDeleteAll(Vec_Expo.begin(),Vec_Expo.end());
    Vec_Expo.clear();


    // 2. Program:
    if(kod.isEmpty() && Vec_Program.size() > 1)
    {
        //qDebug() << "Pro: " << Prot->program;
        QVector<QString> *vec_ProgramProtocol = new QVector<QString>;
        *vec_ProgramProtocol = Prot->program;
        vec_ProgramProtocol->removeFirst();
        foreach(QVector<QString> *vec, Vec_Program)
        {
            //qDebug() << "pro: " << *vec;
            if(*vec_ProgramProtocol != *vec)
            {
                kod = tr("Program");
                res = false;
                break;
            }
        }
        vec_ProgramProtocol->clear();
        delete vec_ProgramProtocol;
    }
    qDeleteAll(Vec_Program.begin(), Vec_Program.end());
    Vec_Program.clear();

    return(res);
}

//-----------------------------------------------------------------------------
//--- Check_Compatibility(QString &kod)
//-----------------------------------------------------------------------------
bool Protocol_page::Check_Compatibility(QString &kod)
{
    int i,j;
    bool res = true;
    kod = "";
    int count_tubes;
    int active_ch, mask;
    bool ok;
    QString text;
    int measured_Time = 0;
    int count_expo = 2;

    while(1)
    {
        //... Empty Protocol ...
        if(!Prot || Prot->program.length() < 1 || Prot->count_Tubes < 1 || Prot->active_Channels == 0x0000)
        {
            kod = tr("Empty Protocol");
            break;
        }

        //... Count of Tubes ...
        text = map_InfoDevice->value(INFODEV_serName,"000");
        count_tubes = text.trimmed().mid(1,1).toInt(&ok);
        if(!ok) count_tubes = 0;
        switch(count_tubes)
        {
        default:    count_tubes = 0;   break;
        case 5:     count_tubes = 96;  break;
        case 6:     count_tubes = 384; break;
        case 7:     count_tubes = 48;  break;
        case 8:     count_tubes = 192; break;
        }
        if(Prot->count_Tubes != count_tubes)
        {
            kod = tr("Count_Tubes");
            break;
        }

        //... Active channels ...
        active_ch = Prot->active_Channels;
        mask = map_InfoDevice->value(INFODEV_devMask,"0").toInt(&ok,16);
        for(i=0; i<COUNT_CH; i++)
        {
            if(active_ch & (0x0f << i*4))
            {
                if(!(mask & (1 << i)))
                {
                    kod = tr("FluorMask");
                    break;
                }
            }
        }
        if(!kod.isEmpty()) break;

        //... Minimum temperature level ...

        //qDebug() << "Expo_Def: " << *Expozition_Def << *expozition_Coeff;

        for(i=0; i<COUNT_CH; i++)
        {
            if(active_ch & (0x0f << i*4))
            {
                measured_Time += 1000;  // On/Off LEDs, turn filters
                for(j=0; j<count_expo; j++)
                {
                    measured_Time += Expozition_Def->at(i*2+j) * expozition_Coeff->at(i);         // value of expo
                    measured_Time += 500;                                                         // read and calculate data
                }
            }
        }
        measured_Time += 1000;  // reserve

        measured_Time = (double)(measured_Time)/1000. + 1 - ToleranceMinLevel;
        if(measured_Time > Prot->PrAmpl_minimumLevel)
        {
            text = tr("sec: Minimum temperature level...");
            kod = QString("%1 %2").arg(measured_Time).arg(text);
            break;
        }


        break;
    }

    if(kod.length()) res = false;
    return(res);
}

//-----------------------------------------------------------------------------
//--- slot_ChangeStateDevice(int state)
//-----------------------------------------------------------------------------
void Protocol_page::slot_ChangeStateDevice(int state)
{
    bool sts = true;
    if(state > 0) sts = false;

    Open_Pro->setEnabled(sts);
    //OpenUSB_Pro->setEnabled(sts);
    Clear_Pro->setEnabled(sts);
}
