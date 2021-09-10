#include "protocol_samples.h"

//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Protocol_Samples::Protocol_Samples(bool results, QWidget *parent): QTreeWidget(parent)
{
    readsettings();

    view_results = results;

    expanded_Sample = new QPushButton(QIcon(":/images/expanded_tree.png"), "", this);
    expanded_Sample->setIconSize(QSize(48,48));
    expanded_Sample->setFixedSize(32,32);
    expanded_Sample->move(565,35);
    //expanded_Sample->setFocusPolicy(Qt::NoFocus);
    expanded_Sample->setFlat(true);
    connect(expanded_Sample, SIGNAL(released()), this, SLOT(change_Expanded()));

    setAutoScroll(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setFocusPolicy(Qt::NoFocus);
    //QHBoxLayout *layout = new QHBoxLayout;
    //setLayout(layout);
    //layout->addWidget(expanded_Sample, 0, Qt::AlignRight);

    clear_Samples();


}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Protocol_Samples::readsettings()
{
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
       translator.load(":/translations/protocol_sample_ru.qm");
    }
    if(lang == "en")
    {
       translator.load(":/translations/protocol_sample_en.qm");
    }

    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//--- change_Expanded()
//-----------------------------------------------------------------------------
void Protocol_Samples::change_Expanded()
{
    int i;
    bool sts;
    QTreeWidgetItem *item_sample;

    if(!topLevelItemCount()) return;


    expanded_Sample->blockSignals(true);

    sts = topLevelItem(0)->isExpanded();
    sts = !sts;

    if(sts == false) expanded_Sample->setIcon(QIcon(":/images/expanded_tree.png"));
    else expanded_Sample->setIcon(QIcon(":/images/not_expanded_tree.png"));

    for(i=0; i<topLevelItemCount(); i++)
    {
        item_sample = topLevelItem(i);
        item_sample->setExpanded(sts);
    }

    expanded_Sample->blockSignals(false);

    //repaint();
    //qApp->processEvents();
}

//-----------------------------------------------------------------------------
//--- clear_Samples()
//-----------------------------------------------------------------------------
void Protocol_Samples::clear_Samples()
{
    int i;
    int count_col = 1;

    clear();
    if(view_results) count_col = 6;
    setColumnCount(1);

    QStringList list;
    list << tr("Samples / Tubes / Channels");
    if(view_results) list << "Cp" << "Ct" << "S%" << "aFF" << "K+";
    setHeaderLabels(list);
    expanded_Sample->setVisible(false);

    if(view_results)
    {
        setColumnWidth(0, 400);
        header()->setSectionResizeMode(0,QHeaderView::Fixed);
        for(i=1; i<count_col; i++)
        {
            setColumnWidth(i, 50);
            header()->setSectionResizeMode(i,QHeaderView::Stretch);
        }

    }

    //header()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}
//-----------------------------------------------------------------------------
//--- fill_Samples(rt_Protocol *prot)
//-----------------------------------------------------------------------------
void Protocol_Samples::fill_Samples(rt_Protocol *prot)
{
    int i,j,k,m;
    int col,row;
    int id_channel, id_tube;
    int num = 0;
    rt_GroupSamples *source;
    rt_Sample       *sample;
    rt_Tube         *tube;
    rt_Channel      *channel;
    rt_Test         *test;

    if(prot == NULL) return;

    //expanded_Sample->setVisible(true);
    expanded_Sample->setIcon(QIcon(":/images/not_expanded_tree.png"));

    prot->Plate.PlateSize(prot->count_Tubes, row, col);

    QTreeWidgetItem *item_sample;
    QTreeWidgetItem *item_tube;
    QTreeWidgetItem *item_ch;
    QString text;

    QIcon icon_ch;

    for(i=0; i<prot->Plate.groups.size(); i++)
    {
        source = prot->Plate.groups.at(i);
        for(j=0; j<source->samples.size(); j++)
        {
            sample = source->samples.at(j);
            test = sample->p_Test;
            item_sample = new QTreeWidgetItem(this);
            item_sample->setFlags(item_sample->flags() & ~Qt::ItemIsSelectable);
            text = QString("%1:  %2 (%3)").arg(num+1).arg(sample->Unique_NameSample).arg(test->header.Name_Test);
            item_sample->setText(0, text);
            item_sample->setExpanded(true);

            for(k=0; k<sample->tubes.size(); k++)
            {
                tube = sample->tubes.at(k);
                id_tube = tube->ID_Tube;
                item_tube = new QTreeWidgetItem(item_sample);
                item_tube->setFlags(item_tube->flags() & ~Qt::ItemIsSelectable);
                text = QString("%1-%2:  (%3)").arg(num+1).arg(k+1).arg(Convert_IndexToName(tube->pos, col));
                item_tube->setText(0, text);
                item_tube->setExpanded(true);

                for(m=0; m<tube->channels.size(); m++)
                {
                    channel = tube->channels.at(m);
                    id_channel = channel->ID_Channel;
                    item_ch = new QTreeWidgetItem(item_tube);
                    item_ch->setFlags(item_ch->flags() & ~Qt::ItemIsSelectable);
                    text = FindNameByTest(test, id_tube, id_channel);
                    item_ch->setText(0, text);

                    switch(id_channel)
                    {
                    case 0:     icon_ch.addFile(":/images/fam_flat.png");   break;
                    case 1:     icon_ch.addFile(":/images/hex_flat.png");   break;
                    case 2:     icon_ch.addFile(":/images/rox_flat.png");   break;
                    case 3:     icon_ch.addFile(":/images/cy5_flat.png");   break;
                    case 4:     icon_ch.addFile(":/images/cy55_flat.png");   break;
                    default:    icon_ch.addFile(":/images/disable_flat.png");   break;
                    }
                    item_ch->setIcon(0, icon_ch);

                    if(view_results)    // Results
                    {
                        item_ch->setText(1, "...");
                        item_ch->setText(2, "...");
                    }
                }
            }
            num++;
        }
    }
}
