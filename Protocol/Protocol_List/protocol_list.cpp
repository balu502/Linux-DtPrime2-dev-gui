#include "protocol_list.h"

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Protocol_List::Protocol_List(QWidget *parent):  QDialog(parent)
{
    readsettings();

    //setFixedSize(600,250);
    //move(160,160);

    setFixedSize(695,360);
    move(98,75);

    /*setStyleSheet(
                  "background-color: #ffffff; border: 1px solid black;"
                  //"QPushButton::enabled {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC);}"
                 );*/

    QFont f = qApp->font();
    f.setPointSize(16);

    //QStringList pp;
    header_name << tr("Name") << tr("ID") << tr("BarCode");
    Key_result = "";

    tree_Protocols = new QTreeWidget(this);
    tree_Protocols->clear();
    tree_Protocols->setColumnCount(3);
    tree_Protocols->setHeaderLabels(header_name);
    tree_Protocols->setFocusPolicy(Qt::NoFocus);
    tree_Protocols->setFont(f);
    tree_Protocols->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tree_Protocols->setStyleSheet("QScrollBar:horizontal {border: 0px solid transparent;background:transparent; width:0px; margin: 0px 0px 0px 0px;}");

    apply_Button = new QPushButton(tr("Apply"), this);
    apply_Button->setDisabled(true);
    cancel_Button = new QPushButton(tr("Cancel"), this);
    //cancel_Button->setStyleSheet("QPushButton::enabled {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC);}");
    //apply_Button->setStyleSheet("QPushButton::enabled {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FAFAFA, stop: 1 #CCCCCC);}");

    //le = new QLineEdit(this);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(0);
    setLayout(layout);


    QHBoxLayout *layout_control = new QHBoxLayout();
    layout_control->setMargin(4);
    //layout_control->addWidget(le, 0, Qt::AlignLeft);
    layout_control->addWidget(apply_Button, 1, Qt::AlignRight);
    layout_control->addWidget(cancel_Button, 0, Qt::AlignRight);

    layout->addWidget(tree_Protocols, 1);
    layout->addLayout(layout_control);

    connect(cancel_Button, SIGNAL(released()), this, SLOT(close())); //SLOT(reject()));
    connect(apply_Button, SIGNAL(released()), this, SLOT(Apply())); //SLOT(accept()));
    connect(tree_Protocols, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(Change_CurrentItem()));


}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Protocol_List::~Protocol_List()
{
    tree_Protocols->clear();
    delete tree_Protocols;

    delete cancel_Button;
    delete apply_Button;

    //delete le;
}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Protocol_List::readsettings()
{
    /*translator.load(":/translations/protocol_list_ru.qm");
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
       translator.load(":/translations/protocol_list_ru.qm");
    }
    if(lang == "en")
    {
       translator.load(":/translations/protocol_list_en.qm");
    }

    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Protocol_List::Load_Protocols(QMap<QString, QString> *map, bool use_files)
{
    int i;
    QString str, text;
    QTreeWidgetItem *item, *curr_item;
    QStringList list_item;

    if(use_files) header_name.replace(0, tr("Name (protocols files *.rt)"));
    else header_name.replace(0, tr("Name"));
    tree_Protocols->setHeaderLabels(header_name);

    tree_Protocols->clear();

    for(i=0; i<map->size(); i++)
    {
        str = map->keys().at(i);
        text = map->value(str);
        list_item = text.split(";");
        item = new QTreeWidgetItem(tree_Protocols);
        item->setText(0, list_item.at(0));
        item->setText(1, str);
        item->setText(2, list_item.at(1));

        if(!i) curr_item = item;
    }
    tree_Protocols->resizeColumnToContents(0);
    tree_Protocols->resizeColumnToContents(1);

    if(map->size()) tree_Protocols->setCurrentItem(curr_item);
    //tree_Protocols->setColumnWidth(0, tree_Protocols->columnWidth(0)*1.1);

}

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Protocol_List::Change_CurrentItem()
{
    QTreeWidgetItem *item = tree_Protocols->currentItem();
    if(tree_Protocols->currentItem())
    {
        apply_Button->setDisabled(false);
        //Key_result = item->text(1);
    }
    else
    {
        apply_Button->setDisabled(true);
        //Key_result = "";
    }
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Protocol_List::Apply()
{
    QTreeWidgetItem *item = tree_Protocols->currentItem();
    if(item)
    {
        Key_result = item->text(1);
    }

    //hide();
    close();
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Protocol_List::Down_CurrentItem()
{
    int count = tree_Protocols->topLevelItemCount();
    if(count == 0) return;

    QTreeWidgetItemIterator it(tree_Protocols);

    while(*it)
    {

        if((*it)->isSelected())
        {
            ++it;
            if(*it)
            {
                tree_Protocols->setCurrentItem(*it);
            }

            break;
        }

        ++it;
    }
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Protocol_List::Up_CurrentItem()
{
    int count = tree_Protocols->topLevelItemCount();
    if(count == 0) return;

    QTreeWidgetItemIterator it(tree_Protocols);

    while(*it)
    {

        if((*it)->isSelected())
        {
            --it;
            if(*it)
            {
                tree_Protocols->setCurrentItem(*it);
            }

            break;
        }

        ++it;
    }
}

//-----------------------------------------------------------------------------
//--- showEvent
//-----------------------------------------------------------------------------
void Protocol_List::showEvent(QShowEvent *event)
{
    Key_result = "";

}
//-----------------------------------------------------------------------------
//--- keyPressEvent
//-----------------------------------------------------------------------------
void Protocol_List::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "List KeyPress: " << e ; //e->key();

    int key = e->key();
    emit sKeyPress(key);

    //QDialog::keyPressEvent(e);

    //e->accept();
}

//-----------------------------------------------------------------------------
//--- ChoiceType
//-----------------------------------------------------------------------------
ChoiceType_Dialog::ChoiceType_Dialog(QWidget *parent)
    : QDialog(parent)
{
    setFixedSize(350,100);

    QSize size = qApp->desktop()->size();
    move((size.width() - width())/2, (size.height() - height())/2);
    //Qt::WindowFlags flags = 0;
    //setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint);
    //setWindowFlags(Qt::Popup);

    //setWindowFlags(Qt::ToolTip);
    //setStyleSheet("border: 1px solid #777");

    group_Choice = new QButtonGroup(this);
    Ethernet_Button = new QPushButton(QIcon(":/images/www-48.png"),"", this);
    USB_Button = new QPushButton(QIcon(":/images/usb_48.png"),"", this);
    Local_Button = new QPushButton(QIcon(":/images/local_disk-48.png"),"", this);
    cancel_Button = new QPushButton(QIcon(":/images/back.png"),"", this);    

    Ethernet_Button->setFixedSize(64,64);
    USB_Button->setFixedSize(64,64);
    Local_Button->setFixedSize(64,64);
    cancel_Button->setFixedSize(64,64);

    Ethernet_Button->setIconSize(QSize(32,32));
    USB_Button->setIconSize(QSize(32,32));
    Local_Button->setIconSize(QSize(32,32));
    cancel_Button->setIconSize(QSize(32,32));

    QHBoxLayout *layout = new QHBoxLayout;
    setLayout(layout);
    layout->addWidget(Ethernet_Button);
    layout->addWidget(USB_Button);
    layout->addWidget(Local_Button);
    layout->addStretch(1);
    layout->addWidget(cancel_Button);    

    group_Choice->addButton(Ethernet_Button);
    group_Choice->addButton(USB_Button);
    group_Choice->addButton(Local_Button);
    group_Choice->addButton(cancel_Button);
    connect(group_Choice, SIGNAL(buttonReleased(QAbstractButton*)), this, SLOT(close_Choice(QAbstractButton*)));

    mask = 0xfff;
}
//-----------------------------------------------------------------------------
//--- ~ChoiceType_Dialog
//-----------------------------------------------------------------------------
ChoiceType_Dialog::~ChoiceType_Dialog()
{
    delete Ethernet_Button;
    delete USB_Button;
    delete Local_Button;
    delete cancel_Button;   
}
//-----------------------------------------------------------------------------
//--- close_Choice
//-----------------------------------------------------------------------------
void ChoiceType_Dialog::close_Choice(QAbstractButton *button)
{

    if(button == Ethernet_Button)   type = 0;
    if(button == USB_Button)   type = 1;
    if(button == Local_Button)   type = 2;
    if(button == cancel_Button)   type = -1;

    close();
    //hide();
}
//-----------------------------------------------------------------------------
//--- showEvent
//-----------------------------------------------------------------------------
void ChoiceType_Dialog::showEvent(QShowEvent *event)
{
    int i;
    bool state;
    type = -1;

    for(i=0; i<3; i++)
    {
        state = mask & (0x0f<<4*i);

        switch(i)
        {
        case 0:                     //Ethernet
                Ethernet_Button->setEnabled(state);
                break;
        case 1:                     // USB
                USB_Button->setEnabled(state);
                break;
        case 2:                     // Local
                Local_Button->setEnabled(state);
                break;
        }
    }

}
//-----------------------------------------------------------------------------
//--- keyPressEvent
//-----------------------------------------------------------------------------
void ChoiceType_Dialog::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "Choice KeyPress: " << e->key() << this;

    int key = e->key(); // - 0x1000030;

    emit sKeyPress(key);


    /*switch(key)
    {
    case 0:     QTimer::singleShot(100, Ethernet_Button, SLOT(click()));    break;
    case 1:     QTimer::singleShot(100, USB_Button, SLOT(click()));         break;
    case 2:     QTimer::singleShot(100, Local_Button, SLOT(click()));    break;
    case 3:     QTimer::singleShot(100, cancel_Button, SLOT(click()));    break;
    default:    break;
    }*/


    //e->accept();
}
//-----------------------------------------------------------------------------
//--- Event
//-----------------------------------------------------------------------------
/*bool ChoiceType_Dialog::event(QEvent *e)
{

    qDebug() << "Event: " << e;

    return QDialog::event(e);
}*/
