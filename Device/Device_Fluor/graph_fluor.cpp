#include "graph_fluor.h"

//-----------------------------------------------------------------------------
//--- GraphFluorPlot()
//-----------------------------------------------------------------------------
GraphFluorPlot::GraphFluorPlot(QWidget *parent):
    QwtPlot(parent)
{        
    //readCommonSettings();

    main_widget = parent;

    canvas()->setCursor(Qt::PointingHandCursor);
    canvas()->installEventFilter(this);
    canvas()->setMouseTracking(true);


    grid = new QwtPlotGrid;
    grid->setMajorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);

    setAxisScale(QwtPlot::yLeft,0,100);
    setAxisScale(QwtPlot::xBottom,0,50);


    QFont f = qApp->font();
    f.setBold(false);
    f.setPointSize(f.pointSize()-3);
    setAxisFont(QwtPlot::yLeft, f);
    setAxisFont(QwtPlot::xBottom, f);

    Fluor_Box = new QComboBox(this);
    f = qApp->font();
    f.setPointSize(f.pointSize()+4);
    Fluor_Box->setFont(f);
    Fluor_Box->setStyleSheet(
                "QComboBox::down-arrow {image: url(:/images/down_arrow_wide.png);}");
    //            "QComboBox::drop-down {width: 32px; background-color: #ffffff; border: 1px solid #777; min-width: 32px;}"
    //            );
    QHBoxLayout *graph_H_layout = new QHBoxLayout();
    graph_H_layout->setMargin(0);
    graph_H_layout->addWidget(Fluor_Box, 0, Qt::AlignRight);
    QVBoxLayout *graph_V_layout = new QVBoxLayout();

    current_Fn = new QLabel();
    QFont font_label = qApp->font();
    font_label.setFamily("Times New Roman");
    font_label.setPointSize(18);
    font_label.setBold(true);
    font_label.setItalic(false);
    current_Fn->setFont(font_label);
    current_Fn->setAlignment(Qt::AlignLeft);
    current_Fn->setFrameShape(QFrame::StyledPanel);
    current_Fn->setStyleSheet("QLabel {background-color: #88FAFAFA; color: black; border: 1px solid gray;}");
    QHBoxLayout *graph_Hf_layout = new QHBoxLayout();
    graph_Hf_layout->addWidget(current_Fn,0,Qt::AlignLeft);


    canvas()->setLayout(graph_V_layout);
    graph_V_layout->addLayout(graph_H_layout);
    graph_V_layout->addStretch(1);
    graph_V_layout->addLayout(graph_Hf_layout);

    connect(Fluor_Box, SIGNAL(currentIndexChanged(int)), this, SLOT(change_Fluor(int)));

    current_fn = 0;

    replot();

}
//-----------------------------------------------------------------------------
//--- ~GraphFluorPlot()
//-----------------------------------------------------------------------------
GraphFluorPlot::~GraphFluorPlot()
{
    delete current_Fn;
    delete Fluor_Box;
    delete grid;

    Delete_Curve();
}
//-----------------------------------------------------------------------------
//--- slotRefreshData()
//-----------------------------------------------------------------------------
void GraphFluorPlot::slotRefreshData(QMap<QString,QString> *map)
{
    /*bool ok;
    QString text = map->value(INFO_fn, "0");
    int value = text.toInt(&ok);
    if(!ok) value = 0;

    current_Fn->setText(QString("Fn=%1").arg(value));

    replot();*/

}
//-----------------------------------------------------------------------------
//--- slot_RefreshFluor()
//-----------------------------------------------------------------------------
void GraphFluorPlot::slot_RefreshFluor()
{
    //qDebug() << "slot_RefreshFluor: " << current_Fn;
    Draw_Chart(Prot, Fluor_Box->currentIndex());

}
//-----------------------------------------------------------------------------
//--- Delete_Curve
//-----------------------------------------------------------------------------
void GraphFluorPlot::Delete_Curve()
{
    qDeleteAll(list_Curve.begin(), list_Curve.end());
    list_Curve.clear();

    Fluor_Box->blockSignals(true);
    Fluor_Box->clear();
    Fluor_Box->blockSignals(false);

}
//-----------------------------------------------------------------------------
//--- Clear_Graph
//-----------------------------------------------------------------------------
void GraphFluorPlot::Clear_Graph()
{
    int i;

    for(i=0; i<list_Curve.count(); i++)
    {
        curve = list_Curve.at(i);
        curve->setData(NULL);
    }

    replot();
}
//-----------------------------------------------------------------------------
//--- slot_NewProtocol
//-----------------------------------------------------------------------------
void GraphFluorPlot::slot_NewProtocol(rt_Protocol *prot)
{
    int i;
    int count_ch = 0;

    if(prot->name.isEmpty())
    {
        Delete_Curve();
        qApp->processEvents();
        replot();
        return;
    }

    int all_measure = prot->count_PCR + prot->count_MC;

    for(i=0; i<COUNT_CH; i++) if(prot->active_Channels & (0x0f<<(i*4))) count_ch++;
    current_fn = 0;
    X.clear();
    X.reserve(all_measure);
    for(i=0; i<all_measure; i++) X.push_back((double)(i+1));
    Y.clear();
    Y.reserve(all_measure*count_ch*prot->count_Tubes);
    Y.fill(0.,all_measure*count_ch*prot->count_Tubes);

    Create_Curve(prot);

    replot();
}
//-----------------------------------------------------------------------------
//--- Create_Curve
//-----------------------------------------------------------------------------
void GraphFluorPlot::Create_Curve(rt_Protocol *P)
{
    int i,j;
    QIcon icon;
    QString fluor_name[COUNT_CH] = FLUOR_NAME;
    int first_ch = -1;

    Prot = P;

    Delete_Curve();

    // 1. curves
    for(i=0; i<Prot->count_Tubes; i++)
    {
        curve = new QwtPlotCurve();
        curve->setStyle(QwtPlotCurve::Lines);
        curve->setSymbol( new QwtSymbol(QwtSymbol::Ellipse,
                                        QBrush(Qt::white),
                                        QPen(Qt::black, 1),
                                        QSize(size_symbol,size_symbol)));
        curve->attach(this);
        list_Curve.append(curve);
    }


    // 2. fluor_select
    Fluor_Box->blockSignals(true);
    for(i=0; i<COUNT_CH; i++)
    {
       Fluor_Box->addItem(fluor_name[i]);
       switch(i)
       {
       case 0:  icon.addFile(":/images/fam_flat.png");   break;
       case 1:  icon.addFile(":/images/hex_flat.png");   break;
       case 2:  icon.addFile(":/images/rox_flat.png");   break;
       case 3:  icon.addFile(":/images/cy5_flat.png");   break;
       case 4:  icon.addFile(":/images/cy55_flat.png");   break;
       default: icon.addFile(NULL);   break;
       }

       Fluor_Box->setItemIcon(i,icon);

       if(!(Prot->active_Channels & (0x0f<<i*4)))
       {
          Fluor_Box->setItemData(i,0,Qt::UserRole - 1);
       }
       else
       {
           if(first_ch < 0) first_ch = i;
       }

    }
    Fluor_Box->blockSignals(false);
    Fluor_Box->setVisible(true);
    Fluor_Box->setCurrentIndex(first_ch);

    //...
    Draw_Chart(Prot,first_ch);
    //...

}
//-----------------------------------------------------------------------------
//--- Draw_Chart
//-----------------------------------------------------------------------------
void GraphFluorPlot::Draw_Chart(rt_Protocol *p, int channel)
{
    int i,j;
    QColor color;
    //int r,g,b;
    QColor bg_color[] ={0xD8E2F1,0xD8E9D8,0xFEF0CB,0xFFE6FF,0xFFE6FF};
    QColor curve_color[] = {Qt::blue, Qt::green, Qt::magenta, Qt::red, Qt::darkRed};
    const double *x;
    const double *y;
    int ch = -1;

    int all_measure = p->count_PCR + p->count_MC;
    int count_tubes = p->count_Tubes;

    //qDebug() << "all_meas: " << all_measure << p->count_PCR << p->count_MC;

    //--- active channel ---
    for(i=0; i<=channel; i++)
    {
        if(!(p->active_Channels & (0x0f<<4*i))) continue;
        ch++;
    }
    if(ch < 0) return;

    Clear_Graph();

    setCanvasBackground(bg_color[channel]);
    setAxisAutoScale(QwtPlot::yLeft, true);
    setAxisScale(QwtPlot::xBottom,0,all_measure+1);

    if(current_fn)
    {
        x = &X.at(0);
        y = &Y.at(ch*count_tubes*all_measure);

        for(i=0; i<count_tubes; i++)
        {
            curve = list_Curve.at(i);
            color = p->color_tube.at(i);
            curve->setPen(color, 1 );
            curve->setSamples(x, y+all_measure*i, current_fn);

            if(p->enable_tube.at(i)) curve->setVisible(true);
            else curve->setVisible(false);
        }
        current_Fn->setText(QString("Fn = %1 (%2)").arg(current_fn).arg(all_measure));
    }
    else current_Fn->setText("");


    //...
    updateAxes();
    show();
    replot();
}
//-----------------------------------------------------------------------------
//--- change_Fluor
//-----------------------------------------------------------------------------
void GraphFluorPlot::change_Fluor(int ch)
{
    if(Fluor_Box->hasFocus()) Fluor_Box->clearFocus();
    if(ch >= 0) Draw_Chart(Prot, ch);
    //canvas()->setCursor(Qt::PointingHandCursor);
}
