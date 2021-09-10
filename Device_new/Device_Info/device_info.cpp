#include "device_info.h"
#include "request_dev.h"
#include "protocol_lib.h"


//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Device_Info::Device_Info(QWidget *parent): QTreeWidget(parent)
{
    readsettings();

    clear_Info();
    Delegate_Info = new ItemDelegate_DeviceInformation();
    setItemDelegate(Delegate_Info);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Device_Info::~Device_Info()
{
    clear();
    delete Delegate_Info;
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_Info::clear_Info()
{
    clear();
    setColumnCount(2);

    QStringList list;
    list << tr("Parameter") << tr("Value");
    setHeaderLabels(list);

    header()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    header()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Device_Info::fill_Info(QMap<QString,QString> *map)
{
    clear_Info();

    QTreeWidgetItem *item;
    QString text, str;
    QStringList list;


    // Name
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("Name of Device"));
    item->setText(1, map->value(INFODEV_serName));

    // Version
    list = map->value(INFODEV_version).split("\r\n");
    foreach(text, list)
    {
        str = "";
        if(text.contains("OPTICS")) str = tr("Version");
        if(text.contains("AMPX")) str = tr(" ");
        if(text.contains("SMOT")) str = tr(" ");
        if(!str.isEmpty())
        {
            item = new QTreeWidgetItem(this);
            item->setText(0, str);
            item->setText(1, text);
        }
    }

    // FluorMask
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("FluorMask"));
    item->setText(1, map->value(INFODEV_devMask));

    // TypeBlock
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("TypeBlock"));
    item->setText(1, map->value(INFODEV_thermoBlock));

    // Expozition
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("Exposure"));
    item->setText(1, map->value("Exposure"));

}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Device_Info::readsettings()
{
    translator.load(":/translations/device_info_ru.qm");
    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void ItemDelegate_DeviceInformation::paint(QPainter *painter,
                                     const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const
{
    QString text;
    int active_ch;
    bool ok;
    int i;

    painter->setFont(qApp->font());
    QPixmap pixmap(":/images/fam_flat.png");

    //QPalette pal = option.palette;
    QStyleOptionViewItem  viewOption(option);
    viewOption.state &= ~QStyle::State_HasFocus;    // disable state HasFocus

    QStyledItemDelegate::paint(painter, viewOption, index);


    text = index.data().toString();
    //qDebug() << "tree: " << index.row() << index.column() << text;
    if(index.row() == 4 && index.column() == 1)
    {
        text = text.replace(" ","").trimmed();
        active_ch = text.toInt(&ok, 16);

        for(i=0; i<COUNT_CH; i++)
        {
            if(active_ch & (0x1<<i))
            {
                switch(i)
                {
                    case 0: pixmap.load(":/images/fam_flat.png");    break;
                    case 1: pixmap.load(":/images/hex_flat.png");    break;
                    case 2: pixmap.load(":/images/rox_flat.png");    break;
                    case 3: pixmap.load(":/images/cy5_flat.png");    break;
                    case 4: pixmap.load(":/images/cy55_flat.png");   break;
                    default: pixmap.load(":/images/disable_flat.png");   break;
                }
            }
            else
            {
                pixmap.load(":/images/disable.png");
            }

            painter->drawPixmap(option.rect.x() + 18*i + 100, option.rect.y(), pixmap);
        }
    }
}

