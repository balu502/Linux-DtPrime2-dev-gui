#include "sp.h"

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
SplashScreen::SplashScreen(QApplication *aApp, QString lang, QWidget *parent, int param) :
    QSplashScreen(parent), app(aApp), m_progress(0)

{
    //WCHAR buffer[1024];
    //DWORD buf_size = 1024;
    QString name_PC;
    QString version_info;
    QString ver;
    QString app_name;

    //readCommonSettings();
    //version_info = GetVersion();

    QFont f("Times New Roman", 28, QFont::Bold);
    QPixmap pix(":/images/dna_2.ico");
    QPixmap pix_logo(":/images/dna_logo_eng_3.png");
    QPixmap pix_logo_rus(":/images/dna_logo_rus_3.png");

    setStyleSheet(
                "QProgressBar:horizontal {border: 1px solid gray; background: #99FAFAFA; padding: 1px;}"
                "QProgressBar::chunk:horizontal {background: qlineargradient(x1: 0, y1: 0.1, x2: 1, y2: 0.1, stop: 0 #B5D8E6, stop: 1 #29647A);}"
                //"QProgressBar::chunk:horizontal {background: qlineargradient(x1: 0, y1: 0.1, x2: 1, y2: 0.1, stop: 0 #CCCCFF, stop: 1 #6464FF);}"
                "QGroupBox {border: 1px solid gray; background: #88FAFAFA; border-radius: 3px; margin-top: 1ex;}"
                "QLabel#Gray {color: #404040;}"
                 );

    if(!param) this->setPixmap(QPixmap(":/images/dna_start_wide.png"));
    else this->setPixmap(QPixmap(":/images/dna_start_semiwide.png"));

    //setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint | Qt::Dialog);
    //setCursor(Qt::BusyCursor);
    //setFixedSize(450, 336);


    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);
    layout->setMargin(4);

    QHBoxLayout *main_layout = new QHBoxLayout;
    main_layout->setMargin(2);

    box = new QGroupBox(this);
    box->setFixedWidth(this->width() * 0.98);
    box->setFixedHeight(80);
    box->move((this->width()-box->width())/2., (this->height()-box->height())/2.5);
    box->setLayout(main_layout);
    int dx = (this->width()-box->width())/2.;

    //qDebug() << "w,h: " << this->width() << this->height();


    if(!param)
    {
        progress = new QProgressBar(box);
        progress->setMinimum(0);
        progress->setMaximum(100);
        progress->setFixedWidth(box->width() * 0.98);
        progress->setFixedHeight(12);
        progress->setTextVisible(false);
        progress->move((box->width()-progress->width())/2., box->height()*0.80);
    }




    icon = new QLabel(box);
    icon->setPixmap(pix);

    //ver = version_info.split("\t").at(0);
    //app_name = QString(APP_NAME) + " " + ver.split(".").at(0) + "." + ver.split(".").at(1);
    name = new QLabel("DT_Pro 1.1", box);   //"RealTime 9.1"
    name->setFont(f);

    //::GetComputerNameW(buffer, &buf_size);
    //name_PC = QString::fromStdWString(buffer);
    name_PC = "...";

    main_layout->addWidget(icon, 0, Qt::AlignLeft | Qt::AlignVCenter);
    main_layout->addWidget(name, 1, Qt::AlignLeft | Qt::AlignVCenter);


    QVBoxLayout *v_layout = new QVBoxLayout;
    v_layout->setSpacing(1);
    web_address = new QLabel(name_PC, box);
    web_address->setObjectName("Gray");
    version = new QLabel(tr("version:") + " " + APP_VERSION/*version_info.split("\t").at(0)*/ + "  (32bit)", box);
    version->setObjectName("Gray");
    last_mod = new QLabel(tr("last mod.:") + " " + QString("%1").arg(__DATE__), box);
    last_mod->setObjectName("Gray");

    v_layout->addWidget(web_address, 0, Qt::AlignRight);
    v_layout->addStretch(2);
    v_layout->addWidget(version, 0, Qt::AlignLeft);
    v_layout->addWidget(last_mod, 0, Qt::AlignLeft);
    if(!param)
    {
        QLabel *label = new QLabel("", box);
        v_layout->addWidget(label, 1, Qt::AlignLeft);
    }

    main_layout->addLayout(v_layout);


    box_web = new QGroupBox(this);
    box_web->setFixedHeight(50);
    box_web->setFixedWidth(50*4.1 - 20);
    QHBoxLayout *h_layout = new QHBoxLayout;
    box_web->setLayout(h_layout);
    h_layout->setMargin(0);

    logo = new QLabel(box_web);
    logo->setScaledContents(true);
    logo->setFixedHeight(40);
    logo->setFixedWidth(40*4.11);
    if(lang == "ru") logo->setPixmap(pix_logo_rus);
    else logo->setPixmap(pix_logo);
    h_layout->addWidget(logo,0, Qt::AlignCenter);


    //box_web->move(this->width()-box_web->width()-dx, dx);
    web_info = new QLabel("www.dna-technology/po/", this);
    web_info->setObjectName("Gray");

    layout->addWidget(web_info, 0, Qt::AlignRight);
    layout->addStretch(1);
    layout->addWidget(box_web, 0, Qt::AlignRight);


    if(!param)
    {
        //timer = new QTimer();
        //connect(timer,SIGNAL(timeout()),this,SLOT(setProgress()));
        //timer->start(100);
    }

    return;

    int width = this->width();
    int height = this->height();
    setFixedSize(width, height);    
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
SplashScreen::~SplashScreen()
{
    qDebug() << "splash delete...";
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void SplashScreen::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse_press_even: ";
    emit s_PowerWakeup(2);

    QSplashScreen::mousePressEvent(event);
}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void SplashScreen::Get_IP(QString ip)
{
    web_address->setText(ip);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void SplashScreen::Set_StandBy(QString message)
{
    StandBy_Label = new QLabel(message, this);
    StandBy_Label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    StandBy_Label->setAlignment(Qt::AlignCenter);
    StandBy_Label->setFixedWidth(500);
    StandBy_Label->setFixedHeight(70);
    QFont Font("Times New Roman", 32);
    Font.setBold(true);
    StandBy_Label->setFont(Font);
    StandBy_Label->setStyleSheet("QLabel {color : red; border: 1px solid red; background-color: white;}");
    StandBy_Label->raise();
    StandBy_Label->move((width()-StandBy_Label->width())/2, (height()-StandBy_Label->height())/2);
    StandBy_Label->setVisible(true);

}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void SplashScreen::Set_ShutDown(QString message)
{
    StandBy_Label->setText(message);
}
