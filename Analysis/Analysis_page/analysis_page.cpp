#include "analysis_page.h"

#include <gsl/gsl_fit.h>
#include <gsl/gsl_statistics.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Analysis_page::Analysis_page(QWidget *parent):  QMainWindow(parent)
{
    Prot = new rt_Protocol();

    readsettings();

    AnalysisGroupBox = new QGroupBox(this);
    AnalysisGroupBox->setObjectName("Transparent");
    setCentralWidget(AnalysisGroupBox);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(2);

    AnalysisGroupBox->setLayout(layout);

    QFont f = qApp->font();
    f.setBold(true);
    f.setPointSize(16);

    Name_Analysis = new QLabel(tr("No Protocol..."));
    Name_Analysis->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    Name_Analysis->setAlignment(Qt::AlignCenter);
    Name_Analysis->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC)}");
    Name_Analysis->setFont(f);

    Clear_Analysis = new QPushButton(QIcon(":/images/clear_flat_16.png"), NULL, this);
    Clear_Analysis->setIconSize(QSize(48,48));
    Clear_Analysis->setFixedSize(48,48);
    Clear_Analysis->setFlat(true);
    Clear_Analysis->setToolTip(tr("Clear Protocol"));
    connect(Clear_Analysis, SIGNAL(released()),this, SLOT(clear_Protocol()));

    Open_Analysis = new QPushButton(QIcon(":/images/open_flat.png"), NULL, this);
    Open_Analysis->setIconSize(QSize(48,48));
    Open_Analysis->setFixedSize(48,48);
    Open_Analysis->setFlat(true);
    connect(Open_Analysis, SIGNAL(released()),this, SLOT(open_Manually()));

    Save_Analysis = new QPushButton(QIcon(":/images/save_flat.png"), NULL, this);
    Save_Analysis->setIconSize(QSize(48,48));
    Save_Analysis->setFixedSize(48,48);
    Save_Analysis->setFlat(true);
    connect(Save_Analysis, SIGNAL(released()),this, SLOT(save_Manually()));


    QHBoxLayout *layout_protocol = new QHBoxLayout;
    layout_protocol->setSpacing(0);
    layout_protocol->addWidget(Name_Analysis,1);
    layout_protocol->addWidget(Clear_Analysis);
    layout_protocol->addWidget(Open_Analysis);
    layout_protocol->addWidget(Save_Analysis);

    Tab_Analysis = new QTabWidget(this);
    Tab_Analysis->setStyleSheet("QTabWidget::tab-bar{alignment: right;}");
    Tab_Analysis->setIconSize(QSize(48,48));


    //... Info
    Info_group = new QGroupBox(this);
    Info = new Protocol_Info(this);
    QHBoxLayout *layout_info = new QHBoxLayout;
    layout_info->setMargin(2);
    Info_group->setLayout(layout_info);
    Info_group->setObjectName("Transparent");
    layout_info->addWidget(Info);

    //... Program
    Program_group = new QGroupBox(this);
    QHBoxLayout *layout_program = new QHBoxLayout;
    Program_group->setLayout(layout_program);
    Program_group->setObjectName("Transparent");
    Plot_Program = new Plot_ProgramAmpl(this);
    Program_scheme = new Protocol_Program(QColor(1,1,1,1), this);
    layout_program->setSpacing(2);
    layout_program->setMargin(2);
    layout_program->addWidget(Plot_Program);
    layout_program->addWidget(Program_scheme);

    //... Fluor ...
    Fluor_Box = new QGroupBox(this);
    QHBoxLayout *fluor_layout = new QHBoxLayout();
    Fluor_Box->setLayout(fluor_layout);
    Plot_fluor = new GraphFluorPlot(this);
    fluor_layout->addWidget(Plot_fluor);
    Plot_fluor->current_Fn->setVisible(false);

    //... Plate ...
    Plate_group = new QGroupBox(this);
    Plate = new PlateTableWidget(0,0, this);
    Plate->setFocusPolicy(Qt::NoFocus);
    QHBoxLayout *layout_plate = new QHBoxLayout;
    layout_plate->setMargin(2);
    Plate_group->setLayout(layout_plate);
    Plate_group->setObjectName("Transparent");
    layout_plate->addWidget(Plate);

    //... Samples & Results ...
    Sample_group = new QGroupBox(this);
    Samples = new Protocol_Samples(true, this);
    Samples->setFocusPolicy(Qt::NoFocus);
    QHBoxLayout *layout_samples = new QHBoxLayout;
    layout_samples->setMargin(2);
    Sample_group->setLayout(layout_samples);
    Sample_group->setObjectName("Transparent");
    layout_samples->addWidget(Samples);

    Tab_Analysis->addTab(Fluor_Box, QIcon(":/images/Spectrum_new.png"), "");
    Tab_Analysis->addTab(Program_group, QIcon(":/images/program.png"), "");
    Tab_Analysis->addTab(Sample_group, QIcon(":/images/sample.png"), "");
    Tab_Analysis->addTab(Plate_group, QIcon(":/images/plate.png"), "");
    Tab_Analysis->addTab(Info_group, QIcon(":/images/Info.png"), "");


    layout->addLayout(layout_protocol);
    layout->addSpacing(2);
    layout->addWidget(Tab_Analysis, 1);

    //... List Protocols ...
    //List_Protocols = new Protocol_List(this);
    //List_Protocols->hide();

    //... Choice Type ...
    //Choice_Type = new ChoiceType_Dialog(this);
    //Choice_Type->hide();

    //... Message ...
    message_analysis = new QMessageBox(this);    

    current_Protocol = "";
    current_ID = "";

    qDebug() << "GSL max: " << GSL_MAX_INT(100,777);

}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Analysis_page::~Analysis_page()
{

    delete Name_Analysis;
    delete Clear_Analysis;
    delete Open_Analysis;
    delete Save_Analysis;

    delete Info;
    delete Program_scheme;
    delete Plot_Program;
    delete Plot_fluor;
    delete Samples;
    delete Plate;

    delete Info_group;
    delete Program_group;
    delete Fluor_Box;
    delete Sample_group;
    delete Plate_group;

    delete Tab_Analysis;
    //delete List_Protocols;
    //delete Choice_Type;

    delete message_analysis;

    delete AnalysisGroupBox;
    delete Prot;
}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Analysis_page::readsettings()
{
    /*translator.load(":/translations/analysis_page_ru.qm");
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
       translator.load(":/translations/analysis_page_ru.qm");
    }
    if(lang == "en")
    {
       translator.load(":/translations/analysis_page_en.qm");
    }

    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//--- open_ProtocolFromServer(QString)
//-----------------------------------------------------------------------------
void Analysis_page::open_ProtocolCompleted(QString id)
{
    QVariant returned_Value;
    QVariant id_prot = id;

    qDebug() << "open_Protocol from Server: " << id;

    //if(!id.isEmpty())
    {
        //emit sWait_Process(wOpen, 100, tr("Save Protocol..."));
        QObject *obj = (QObject*)(pweb->rootObject());
        QMetaObject::invokeMethod(obj, "getWebCompleted",
                                  Q_RETURN_ARG(QVariant, returned_Value),
                                  Q_ARG(QVariant, id_prot));
    }
}
//-----------------------------------------------------------------------------
//--- open_USBProtocol()
//-----------------------------------------------------------------------------
void Analysis_page::open_USBProtocol()
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
        message_analysis->setStandardButtons(QMessageBox::Ok);
        message_analysis->setIcon(QMessageBox::Warning);
        message_analysis->button(QMessageBox::Ok)->animateClick(7000);
        text = tr("USB-Flash is absent!");
        message_analysis->setText(text);
        message_analysis->exec();
        repaint();
        qApp->processEvents();

        emit sRejimeDevButtons(2,0);

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
        }
    }

    List_Protocols = new Protocol_List(this);
    List_Protocols->Load_Protocols(&map_USB, true);

    emit sRejimeDevButtons(2,2);
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
        fn.setFile(fileName);
        qDebug() << "Key_results: " << List_Protocols->Key_result;

        emit sWait_Process(wOpenFile, 100, tr("Open USB Protocol..."));
        load_fromXML(fileName);

        if(fn.exists()) current_Protocol = fileName;
        Tab_Analysis->setCurrentIndex(0);
        repaint();

        emit sFinished_WaitProcess();
        qApp->processEvents();
    }

    delete List_Protocols;

    map_USB.clear();
    map_USBfile.clear();

    emit sRejimeDevButtons(2,0);

}
//-----------------------------------------------------------------------------
//--- save_Manually()
//-----------------------------------------------------------------------------
void Analysis_page::save_Manually()
{
    int type;

    if(current_Protocol.isEmpty()) return;

    if(Choice_Type)
    {
        qDebug() << "Delete Choice_Type...";
        //delete Choice_Type;
    }

    Choice_Type = new ChoiceType_Dialog(this);
    Choice_Type->mask = 0x00ff;

    emit sRejimeDevButtons(2,3);
    connect(Choice_Type, SIGNAL(sKeyPress(int)), this, SLOT(slot_KeyPress(int)));

    //Choice_Type->open();
    Choice_Type->exec();
    //Choice_Type->hide();

    type = Choice_Type->type;
    Choice_Type->disconnect();


    switch(type)
    {
    case 0:     save_Protocol();    break;
    case 1:     save_USBProtocol(); break;

    case 2:     //break;
    default:
                //emit sRejimeDevButtons(2,0);
                break;
    }

    emit sRejimeDevButtons(2,0);
}
//-----------------------------------------------------------------------------
//--- slot_KeyPress(int key)
//-----------------------------------------------------------------------------
void Analysis_page::slot_KeyPress(int key)
{
    qDebug() << "Analysis: Get KeyPress: " << key;
    emit sKeyPress(key);
}
//-----------------------------------------------------------------------------
//--- save_USBProtocol()
//-----------------------------------------------------------------------------
void Analysis_page::save_USBProtocol()
{
    bool res;
    QString text;
    QString file_name, new_file, old_file;
    QFileInfo fi;
    QDir usb_Dir("/home/user/prog/dev_gui/usb-flash");


    if(current_Protocol.isEmpty()) return;
    fi.setFile(current_Protocol);
    if(!fi.exists()) return;

    int usb_find = system("mount | grep usb-flash");
    if(usb_find != 0)
    {
        message_analysis->setStandardButtons(QMessageBox::Ok);
        message_analysis->setIcon(QMessageBox::Warning);
        message_analysis->button(QMessageBox::Ok)->animateClick(7000);
        text = tr("USB-Flash is absent!");
        message_analysis->setText(text);
        message_analysis->exec();
        repaint();
        qApp->processEvents();

        return;
    }

    qDebug() << "save_USBProtocol(): " << current_Protocol << fi.exists();

    file_name = fi.fileName();
    old_file = fi.absoluteFilePath();
    new_file = usb_Dir.absolutePath() + "/" + file_name;
    fi.setFile(new_file);

    if(fi.exists())
    {
        message_analysis->setStandardButtons(QMessageBox::Ok);
        message_analysis->setIcon(QMessageBox::Warning);
        message_analysis->button(QMessageBox::Ok)->animateClick(7000);
        text = QString("%1 (%2) %3").arg(tr("This file")).arg(file_name).arg(tr("is already exists!"));
        message_analysis->setText(text);
        message_analysis->exec();
        repaint();
        qApp->processEvents();

        return;
    }


    res =  QFile::copy(old_file, new_file);

    qDebug() << "copy to usb: " << res << old_file << new_file;

    message_analysis->setStandardButtons(QMessageBox::Ok);
    if(res)
    {
        message_analysis->button(QMessageBox::Ok)->animateClick(5000);
        message_analysis->setIcon(QMessageBox::Information);
        text = tr("Protocol has been successfully saved!");
    }
    else
    {
        message_analysis->setIcon(QMessageBox::Warning);
        text = tr("Attention! Protocol IS NOT saved!");
    }
    message_analysis->setText(text);
    message_analysis->exec();

    return;
}

//-----------------------------------------------------------------------------
//--- save_Protocol()
//-----------------------------------------------------------------------------
void Analysis_page::save_Protocol()
{
    QFile file;
    QFileInfo fi;
    QString reg_number = "";
    QString text;
    int res;
    bool replace = true;

    QVariant id_prot, data, name;
    QVariant returned_Value = "";

    QDomDocument    doc;
    QDomElement     root;
    QDomNode        child;
    QDomNode        node;
    QDomNode        item;

    //qDebug() << "current_Protocol: " << current_Protocol;

    if(current_Protocol.isEmpty()) return;

    qDebug() << "List Completed: (save_Protocol) " << *list_protocolsCompleted;


    file.setFileName(current_Protocol);
    fi.setFile(current_Protocol);
    if(!file.exists()) return;

    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }

        file.close();

        //... find reg_number ...
        root = doc.documentElement();
        reg_number = root.firstChildElement("regNumber").text();
        doc.clear();

        //qDebug() << "name: " << reg_number << file.fileName();

        if(reg_number.trimmed().isEmpty()) reg_number = GetRandomString();
        current_ID = reg_number;

        //... check on ID_Protocol ...
        if(list_protocolsCompleted->contains(reg_number))
        {
            message_analysis->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            message_analysis->setIcon(QMessageBox::Warning);
            text = tr("A protocol with the same ID number is exists! Do You want to replace this protocol?");
            message_analysis->setText(text);
            res = message_analysis->exec();
            if(res == QMessageBox::No) replace = false;
        }

        //... send protocol to server ...
        if(file.open(QIODevice::ReadOnly) && replace)
        {
            QTextStream in(&file);
            text = in.readAll();
            file.close();

            id_prot = reg_number;
            data = text;
            name = fi.fileName();

            if(id_prot.toString().size())
            {
                QObject *obj = (QObject*)(pweb->rootObject());
                QMetaObject::invokeMethod(obj, "send_ProtocolToWeb",
                                          Q_RETURN_ARG(QVariant, returned_Value),
                                          Q_ARG(QVariant, id_prot),
                                          Q_ARG(QVariant, data),
                                          Q_ARG(QVariant, name));

                emit sWait_Process(wSaveFile, 100, tr("Save Protocol..."));
                QTimer::singleShot(2000, this, SLOT(check_SaveProcedure()));
            }
        }
    }
}
//-----------------------------------------------------------------------------
//--- check_SaveProcedure()
//-----------------------------------------------------------------------------
void Analysis_page::check_SaveProcedure()
{
    bool sts = false;
    QString text;

    sFinished_WaitProcess();

    qDebug() << "List Completed: (check_SaveProcedure()) " << *list_protocolsCompleted;
    qDebug() << "current_ID: " << current_ID;

    if(list_protocolsCompleted->contains(current_ID)) sts = true;

    message_analysis->setStandardButtons(QMessageBox::Ok);

    if(sts)
    {
        message_analysis->button(QMessageBox::Ok)->animateClick(5000);
        message_analysis->setIcon(QMessageBox::Information);
        text = tr("Protocol has been successfully saved!");
    }
    else
    {
        message_analysis->setIcon(QMessageBox::Warning);
        text = tr("Attention! Protocol IS NOT saved!");
    }
    message_analysis->setText(text);
    message_analysis->exec();
}
//-----------------------------------------------------------------------------
//--- open_Manually()
//-----------------------------------------------------------------------------
void Analysis_page::open_Manually()
{
    int type;

    if(Choice_Type)
    {
        qDebug() << "Delete Choice_Type...";
        //delete Choice_Type;
    }

    Choice_Type = new ChoiceType_Dialog(this);
    Choice_Type->mask = 0x0ff0;

    emit sRejimeDevButtons(2,1);
    connect(Choice_Type, SIGNAL(sKeyPress(int)), this, SLOT(slot_KeyPress(int)));

    //Choice_Type->open();
    Choice_Type->exec();
    //Choice_Type->hide();

    type = Choice_Type->type;
    Choice_Type->disconnect();

    switch(type)
    {

    case 1:     open_USBProtocol(); break;
    case 2:     open_Protocol();    break;

    case 0:     //break;
    default:
                emit sRejimeDevButtons(2,0);
                break;
    }

}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Analysis_page::open_Protocol(QString fn)
{
    QMap<QString,QString> map_USB;
    QMap<QString,QString> map_USBfile;
    QString text;
    QDir dir_output(qApp->applicationDirPath() + "/output");
    QFileInfo fi;
    int num = 0;

    if(fn.isEmpty())
    {
       foreach(QString fileName, dir_output.entryList(QDir::Files))
       {
            fi.setFile(dir_output, fileName);
            if(fi.exists() && fi.suffix() == "rt")
            {
                num++;
                text = QString::number(num);
                map_USB.insert(text, fi.fileName() + "; ");
                map_USBfile.insert(text, fi.absoluteFilePath());
            }
       }

       List_Protocols = new Protocol_List(this);
       List_Protocols->Load_Protocols(&map_USB, true);

       emit sRejimeDevButtons(2,2);
       connect(List_Protocols, SIGNAL(sKeyPress(int)), this, SLOT(slot_KeyPress(int)));

       //List_Protocols->open();
       List_Protocols->exec();
       //List_Protocols->hide();
       qApp->processEvents();
       List_Protocols->disconnect();

       if(List_Protocols->Key_result.isEmpty()) {;}
       else
       {
           fn = map_USBfile.value(List_Protocols->Key_result);
       }

       delete List_Protocols;

       map_USB.clear();
       map_USBfile.clear();
    }

    emit sRejimeDevButtons(2,0);

    if(fn.isEmpty())
    {
        qApp->processEvents();
        return;
    }
    else
    {
        fi.setFile(fn);

        load_fromXML(fn);
        if(fi.exists()) current_Protocol = fn;
        // Analysis
        //Sleep(5000);
    }

    Tab_Analysis->setCurrentIndex(0);
    repaint();

    qApp->processEvents();
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
bool Analysis_page::load_fromXML(QString fn)
{
    int i,j,k;
    int id, num_fn, ch;
    int all_measure;
    int num = 0;
    double value;
    QMap<int,int> map_ActiveChannel;

    clear_Protocol();

    bool sts = Read_XML(Prot, fn);
    qApp->processEvents();

    //... map_ActiveChannel ...
    for(i=0; i<COUNT_CH; i++)
    {
        if(Prot->active_Channels & (0x0f<<4*i))
        {
            map_ActiveChannel.insert(i,num);
            num++;
        }
    }


    //... Load Exposure ...
    k = 0;
    for(i=0; i<COUNT_CH; i++)
    {
        id = k*2;
        if(!(Prot->active_Channels & (0x0f<<4*i)) || Prot->meas.size() <= id)
        {
            Prot->Exposure.push_back((short)0);
        }
        else
        {
            rt_Measurement *meas =  Prot->meas.at(id);
            Prot->Exposure.push_back(meas->exp_value);
            k++;
        }
    }

    //... xml_protocol ...
    QFileInfo fi(fn);
    if(fi.exists())
    {
       Prot->xml_filename = fi.fileName();
    }


    //... Name ...
    Name_Analysis->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #C8FFC8, stop: 1 #64FF64)}");
    Name_Analysis->setText(Prot->name);

    //... Info ...
    Info->fill_Info(Prot);
    qApp->processEvents();

    //... Program ...
    Plot_Program->draw_Program(Prot);
    Program_scheme->draw_Program(Prot);
    qApp->processEvents();

    //... Samples ..
    Samples->fill_Samples(Prot);
    qApp->processEvents();

    //... Plate ...
    Plate->fill_Plate(Prot);
    qApp->processEvents();

    //... Fluor ...
    Plot_fluor->slot_NewProtocol(Prot);
    Plot_fluor->current_fn = div(Prot->meas.size(), num*2).quot;  //Prot->count_MC + Prot->count_PCR;

        //... Load measure data ...
        all_measure = Prot->count_MC + Prot->count_PCR;
        qDebug() << "Prot->meas.size(): " << Prot->meas.size();
        for(i=0; i<Prot->meas.size(); i++)
        {
            rt_Measurement* measure = Prot->meas.at(i);
            if(measure->num_exp > 0) continue;
            num_fn = measure->fn;
            ch = map_ActiveChannel.value(measure->optical_channel, -1);
            if(ch < 0) continue;

            for(j=0; j<Prot->count_Tubes; j++)
            {
                value = 0x0fff & measure->measurements.at(j);
                value -= measure->blk_exp;
                id = num_fn + j*all_measure + ch*Prot->count_Tubes*all_measure;
                if(id >= Plot_fluor->Y.size()) continue;
                Plot_fluor->Y.replace(id,value);
            }
        }
        //...


    Plot_fluor->Draw_Chart(Prot, Plot_fluor->Fluor_Box->currentIndex());
    qApp->processEvents();


}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Analysis_page::clear_Protocol()
{
    qDebug() << "clear_Protocol: ";
    current_Protocol.clear();
    current_ID.clear();

    //... Name ...
    Name_Analysis->setText(tr("No Protocol..."));
    Name_Analysis->setStyleSheet("QLabel{border: 1px solid #111; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC)}");

    //... Info ...
    Info->clear_Info();

    //... Program ...
    Plot_Program->clear_Program();
    Program_scheme->clear_scheme();

    //... Plate ...
    Plate->clear_Plate();

    //... Fluor ...
    Plot_fluor->Clear_Graph();
    Plot_fluor->Delete_Curve();

    //... Samples ...
    Samples->clear_Samples();

    QTimer::singleShot(200, this, SLOT(repaint()));
}



