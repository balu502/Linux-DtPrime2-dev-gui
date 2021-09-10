#include "protocol_info.h"

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Protocol_Info::Protocol_Info(QWidget *parent): QTreeWidget(parent)
{
    readsettings();

    clear_Info();
    Delegate_Info = new ItemDelegate_Information();
    setItemDelegate(Delegate_Info);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Protocol_Info::~Protocol_Info()
{
    clear();
    delete Delegate_Info;
}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Protocol_Info::readsettings()
{
    /*translator.load(":/translations/protocol_info_ru.qm");
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
       translator.load(":/translations/protocol_info_ru.qm");
    }
    if(lang == "en")
    {
       translator.load(":/translations/protocol_info_en.qm");
    }

    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Protocol_Info::clear_Info()
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
void Protocol_Info::fill_Info(rt_Protocol *prot)
{
    int i;
    rt_Preference *preference;

    if(prot == NULL) return;

    QTreeWidgetItem *item;
    QString text;
    int num;


    // 1. Name of Protocol
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("Name of Protocol"));
    text = prot->name;
    item->setText(1, text);

    // 2. Name of Program
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("Name of Program"));
    text = prot->PrAmpl_name;
    item->setText(1, text);

    // 3. ID Prpotocol
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("ID of Protocol"));
    text = prot->regNumber;

        // Find Web_Protocol property
        for(i=0; i<prot->preference_Pro.size(); i++)
        {
            preference = prot->preference_Pro.at(i);
            if(preference->name == "Web_Protocol" && text == preference->value)
            {
                text += "  (Web)";
                break;
            }
        }
    item->setText(1, text);

    // 4. Operator
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("Operator"));
    text = prot->owned_by;
    item->setText(1, text);



    // 5. BarCode
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("BarCode"));
    text = prot->barcode;
    item->setText(1, text);

    // 6. Type_Plate
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("Type of Plate"));
    num = prot->count_Tubes;
    text = QString::number(num);
    item->setText(1, text);

    // 7. ActiveChannels
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("AciveChannels"));
    num = prot->active_Channels;
    text = QString("0x%1").arg(num,5,16);
    item->setText(1, text);

    // 8. File of Protocol
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("File of protocol"));
    text = prot->xml_filename;
    item->setText(1, text);

    // 9. Device
    item = new QTreeWidgetItem(this);
    item->setText(0, tr("Device RT"));
    text = prot->SerialName;    
    if(text.isEmpty()) text = "...";
    text += "  (Exp: ";
    for(i=0; i<prot->Exposure.size(); i++)
    {
        if(i) text += ",";
        text += QString("%1").arg(prot->Exposure.at(i));
    }
    text += ")";

    if(prot->Exposure.size() == 0 && prot->SerialName.trimmed().isEmpty()) text = "";

    item->setText(1, text);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void ItemDelegate_Information::paint(QPainter *painter,
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
    if(index.row() == 6 && index.column() == 1)
    {
        text = text.replace(" ","").trimmed();
        active_ch = text.toInt(&ok, 16);

        for(i=0; i<5; i++)
        {
            if(active_ch & (0xf<<4*i))
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
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void PlateTableWidget::fill_Plate(rt_Protocol *prot)
{
    int i,j;
    QStringList header;
    QTableWidgetItem* item;
    int col, row;
    int current_col, current_row;
    int pos;
    int code_ch;
    int kind;
    QString text;

    QMap<int,rt_Tube*>::iterator id_tube;

    prot->Plate.PlateSize(prot->count_Tubes, row, col);

    //... create table_plate ...
    clear();
    setRowCount(row);
    setColumnCount(col);

    //... Data ...
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            pos = i*col + j;
            item = new QTableWidgetItem();
            setItem(i,j,item);
            text = "";
            if(prot->enable_tube.at(pos))
            {
                text = QString("%1").arg(prot->color_tube.at(pos));
            }
            item->setText(text);
        }
    }

    //... Headers ...
    QFont f = qApp->font();
    f.setPointSize(f.pointSize()-2);
    verticalHeader()->setFont(f);
    horizontalHeader()->setFont(f);

    header.clear();
    for(i=0; i<col; i++) header.append(QString::number(i+1));   // Column Header
    setHorizontalHeaderLabels(header);
    for(i=0; i<col; i++) horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    header.clear();
    for(i=0; i<row; i++) header.append(QChar(0x41 + i));        // Row Header
    setVerticalHeaderLabels(header);
    for(i=0; i<row; i++) verticalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void PlateItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QColor color,rgb;
    //int r,g,b;
    int rad;
    int x,y;
    double X,Y,R;
    int pos,value;
    int width,height;
    QString text = index.data().toString();
    QRect rect = option.rect;
    //QBrush brush;
    bool ok;

    //QPalette pal = option.palette;
    QStyleOptionViewItem  viewOption(option);
    viewOption.state &= ~QStyle::State_HasFocus;    // disable state HasFocus

    QStyledItemDelegate::paint(painter, viewOption, index);

    //__1. Background
    painter->fillRect(option.rect, QColor(255,255,255));

    //__2. Enable Tube
    //pos = index.column() + index.row() * index.model()->columnCount();

    if(text.length())
    {
        value = text.toInt(&ok);
        if(!ok) value = 0;
        color = value;

        //painter->fillRect(rect, color);
        rad = rect.height()-2;
        y = rect.y()+1;
        x = rect.x() + (rect.width()-rad)/2;
        painter->setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter->setBrush(QBrush(color, Qt::SolidPattern));
        painter->drawEllipse(x,y, rad, rad);
    }




}
