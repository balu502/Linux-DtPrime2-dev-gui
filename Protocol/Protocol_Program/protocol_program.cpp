#include "protocol_program.h"


//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Protocol_Program::Protocol_Program(QColor color, QWidget *parent):
    QScrollArea(parent)
{
    readsettings();

    setWidget(&label_Program);
    setWidgetResizable(true);
    setFixedWidth(300);

    if(color != Qt::transparent)
    {
        setStyleSheet("background-color: #EFFAFC;"); // #EAF8FB;"); //rgb(215, 240, 247);");
        //else setStyleSheet("background-color:rgb(153, 217, 234);");
    }
}
//-----------------------------------------------------------------------------
//--- readsettings()
//-----------------------------------------------------------------------------
void Protocol_Program::readsettings()
{
    /*translator.load(":/translations/protocol_program_ru.qm");
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
       translator.load(":/translations/protocol_program_ru.qm");
    }
    if(lang == "en")
    {
       translator.load(":/translations/protocol_program_en.qm");
    }

    qApp->installTranslator(&translator);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Protocol_Program::clear_scheme()
{
    QPixmap pixmap_NULL;
    label_Program.setPixmap(pixmap_NULL);
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
void Protocol_Program::draw_Program(rt_Protocol *prot, int DRAW_Level)
{
    int i,j;
    QString text,temp,time,meas,tmp;
    bool new_block = true;
    QVector<QString> str;
    QStringList s;
    double dvalue;
    short val;
    QByteArray ba("\xB0\x43");
    int height_pm = 0;
    QPixmap pixmap_foto(":/images/foto.png");
    QPixmap pixmap_fotoMC(":/images/foto_mc.png");
    QPixmap pixmap_incr;
    QFont f;
    bool grad_step = false;
    bool gradient = false;

    QVector<QString> pr = prot->program;
    if(pr.size() < 2) {clear_scheme(); return;}

    QVector<Block_Pro*> Blocks;
    Block_Pro   *block;

    int y_0,y_1;
    QPolygon polygon;
    int offset;

    int draw_block = -1;
    int draw_level = -1;
    bool draw_status = false;
    if(DRAW_Level >= 0)
    {
        draw_status = (bool)(DRAW_Level & 0x000001);
        draw_level = (DRAW_Level & 0x00ff00) >> 8;
        draw_block = (DRAW_Level & 0xff0000) >> 16;

        if(draw_block == 0)
        {
            draw_block = -1;
            draw_level = -1;
            draw_status = false;
        }
    }


    for(i=0; i<pr.size(); i++)
    {
        text = pr.at(i);
        if(text.indexOf("XPRG") == 0)
        {
            s = text.split(QRegExp("\\s+"));
            tmp = s.at(3);
            val = tmp.toShort();
            if(val >= 4) grad_step = true;
            continue;
        }
        if(text.indexOf("XTCH") == 0)
        {
            gradient = true;
            continue;
        }
        if(text.indexOf("XLEV") == 0)
        {
            if(new_block)
            {
                block = new Block_Pro();
                Blocks.append(block);
                block->Num_Cycle = 1;
            }
            new_block = false;

            s = text.split(QRegExp("\\s+"));
            //temperature
            temp = s.at(1);
            dvalue = temp.toDouble();
            dvalue /= 100.;
            temp = QString::number(dvalue,'f',1) + " " + QString::fromLatin1(ba);
            //time
            time = s.at(2);
            dvalue = time.toDouble();
            time = QDateTime::fromTime_t(dvalue).toString("mm:ss");
            //measure
            meas = s.at(6);
            val = meas.toShort();
            block->Measure.append(val);
            if(val == 2) block->Type_Block = bMelt;

            //gradient
            tmp = s.at(5);
            val = tmp.toShort();
            if(val != 0 && !gradient) val = 0;
            block->Gradient.append(val);
            gradient = false;
            //incr_time
            tmp = s.at(4);
            val = tmp.toShort();
            block->Incr_Time.append(val);
            //incr_temp
            tmp = s.at(3);
            val = tmp.toShort();
            block->Incr_Temp.append(val);

            if(i+1 < pr.size())
            {
                //i++;
                text = pr.at(i+1);
                if(text.indexOf("XLEV") != 0 && text.indexOf("XTCH") != 0) new_block = true;
                if(text.indexOf("XPAU") == 0) {time = "Pause"; block->Type_Block = bPause;}
                if(text.indexOf("XHLD") == 0) {time = "Hold"; block->Type_Block = bHold;}
                if(text.indexOf("XCYC") == 0)
                {
                    s = text.split(QRegExp("\\s+"));
                    tmp = s.at(1);
                    block->Num_Cycle = tmp.toInt();
                }
            }

            block->Level.append(temp + " - " + time);
            str.append(temp + " - " + time);
        }
    }

    // Height Pixmap:
    for(i=0; i<Blocks.size(); i++)
    {
        block = Blocks.at(i);
        height_pm += 16 + block->Level.size()*16;
    }

    QPixmap pixmap(240,height_pm);
    pixmap.fill(QColor("transparent"));
    //pixmap.fill();

    QPainter painter(&pixmap);
    QPen myPen(Qt::black, 1, Qt::SolidLine);
    painter.setPen(myPen);

    f = QApplication::font();
    f.setPointSize(8);
    painter.setFont(f);

    height_pm = 0;
    for(i=0; i<Blocks.size(); i++)
    {
        block = Blocks.at(i);
        if(block->Type_Block == bHold) myPen.setColor(Qt::blue);
        else myPen.setColor(Qt::black);
        painter.setPen(myPen);

        for(j=0; j<block->Level.size(); j++)
        {
            //... draw current(On_Line) level
            if(draw_block == i+1 && draw_level == j && block->Type_Block != bHold)
            {
                myPen.setColor(Qt::red);
                if(draw_status) f.setBold(true);
                painter.setFont(f);
                painter.setPen(myPen);
            }

            //...

            if(!j) y_0 = height_pm;
            height_pm += 16;
            if(!j) painter.drawText(5, height_pm, QString("%1.").arg(i+1));
            painter.drawText(20, height_pm, block->Level.at(j));

            offset = 115;
            if(block->Measure.at(j) == 1) {painter.drawPixmap(offset, height_pm-14, pixmap_foto); offset += 20;}
            if(block->Measure.at(j) == 2) {painter.drawPixmap(offset, height_pm-14, pixmap_fotoMC); offset += 20;}

            if(block->Incr_Temp.at(j) != 0)
            {
                pixmap_incr.load(":/images/incr_temp.png");
                painter.drawPixmap(offset, height_pm-14, pixmap_incr);
                offset += 20;
            }
            if(block->Incr_Time.at(j) != 0)
            {
                pixmap_incr.load(":/images/incr_time.png");
                painter.drawPixmap(offset, height_pm-14, pixmap_incr);
                offset += 20;
            }
            if(block->Gradient.at(j) != 0)
            {
                pixmap_incr.load(":/images/grad.png");
                if(grad_step) pixmap_incr.load(":/images/grad_step.png");
                painter.drawPixmap(offset, height_pm-14, pixmap_incr);
                offset += 20;
            }

            if(block->Type_Block != bHold)
            {
                myPen.setColor(Qt::black);
                f.setBold(false);
                painter.setFont(f);
                painter.setPen(myPen);
            }

        }
        y_1 = height_pm;
        height_pm += 16;


        if(block->Num_Cycle > 1)
        {
            y_0 += 2;
            y_1 += 2;
            polygon.clear();
            polygon << QPoint(200,y_0) << QPoint(205,y_0) << QPoint(205,y_1) << QPoint(200,y_1);
            painter.drawPolyline(polygon);
            text = QString(" x %1").arg(block->Num_Cycle);
            painter.drawText(205, y_0 + (y_1-y_0)/2 + 6, text);
        }
    }


    label_Program.setPixmap(pixmap);



    for(i=0; i<Blocks.size(); i++) delete Blocks.at(i);
    Blocks.clear();
}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Plot_ProgramAmpl::Plot_ProgramAmpl(QWidget *parent):
    QwtPlot(parent)
{
    QwtText title_Y;

    //readCommonSettings();

    canvas()->setCursor(Qt::ArrowCursor);
    //canvas()->installEventFilter(this);
    //canvas()->setMouseTracking(true);

    //curve = new QwtPlotCurve();
    curve = new ColorCurve();
    curve->setStyle(QwtPlotCurve::Lines);
    curve->attach(this);

    QColor color_bg = 0xEAF8FB; //0x99D9EA;
    //if(style == "fusion") color_bg = 0xEAF8FB;
    setCanvasBackground(color_bg);

    QFont axisFont("Arial", 8, QFont::Normal);
    setAxisFont(QwtPlot::yLeft, axisFont);

    setAxisScale(QwtPlot::yLeft,0.,100.);
    enableAxis(QwtPlot::xBottom,false);
    enableAxis(QwtPlot::yLeft,true);

    grid = new QwtPlotGrid;
    grid->setMajorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);


    name_program = new QLabel();
    QHBoxLayout *plot_H1_layout = new QHBoxLayout();
    plot_H1_layout->addStretch(1);
    plot_H1_layout->addWidget(name_program);
    param_program = new QLabel();
    QHBoxLayout *plot_H2_layout = new QHBoxLayout();
    plot_H2_layout->addWidget(param_program);
    QVBoxLayout *plot_V_layout = new QVBoxLayout();
    plot_V_layout->addLayout(plot_H1_layout);
    plot_V_layout->addStretch(1);
    plot_V_layout->addLayout(plot_H2_layout);
    canvas()->setLayout(plot_V_layout);

    QFont f = parent->font();
    f.setBold(true);
    f.setPointSize(12);
    name_program->setFont(f);
    //f.setPointSize(8);
    f.setBold(false);
    param_program->setFont(f);

    //title_Y.setText("Temperature,°C");
    //setAxisTitle(QwtPlot::yLeft, title_Y);

}
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
Plot_ProgramAmpl::~Plot_ProgramAmpl()
{
    delete curve;
    delete name_program;
    delete param_program;
}
//-----------------------------------------------------------------------------
//--- clear_Program()
//-----------------------------------------------------------------------------
void Plot_ProgramAmpl::clear_Program()
{
    name_program->setText("");
    param_program->setText("");
    curve->setData(NULL);
    replot();
}
//-----------------------------------------------------------------------------
//--- draw_Program()
//-----------------------------------------------------------------------------
void Plot_ProgramAmpl::draw_Program(rt_Protocol *prot)
{
    int i;
    double value_x = 0;
    double value_y;
    QVector<double> x,y;
    QColor color;
    int count = prot->PrAmpl_value.size();
    QString text;
    QwtText title_Y;
    QFont f = qApp->font();


    curve->color_lev.clear();

    for(i=0; i<count; i++)
    {
        value_x += 5;
        x.push_back(value_x);
        value_x += prot->PrAmpl_time.at(i);
        x.push_back(value_x);

        value_y = prot->PrAmpl_value.at(i);
        y.push_back(value_y);
        y.push_back(value_y);

        switch(prot->PrAmpl_color.at(i))
        {
            default:
            case 0: color = Qt::darkGreen;  break;
            case 1: color = Qt::red;        break;
            case 2: color = Qt::red;        break;
            case 3: color = Qt::blue;   break;
        }
        curve->color_lev.push_back(color);
    }

    curve->setSamples(x,y);

    //... name ...
    QVector<QString> program = prot->program;
    for(i=0; i<program.size(); i++)
    {
        text = program.at(i);
        if(text.startsWith("XSAV"))
        {
           text = text.mid(5);
           break;
        }
        else text = "";
    }
    f.setBold(true);
    name_program->setFont(f);
    name_program->setText(text);

    //... param ...
    if(program.size())
    {
        text = QString("PCR = %1;  MC = %2;").arg(prot->count_PCR).arg(prot->count_MC);
        param_program->setText(text);
    }
    else param_program->setText("");


    f.setBold(true);
    //f.setPointSize(12);
    title_Y.setText(tr("Temperature,°C"));
    title_Y.usedFont(f);

    setAxisTitle(QwtPlot::yLeft, title_Y);

    updateAxes();
    replot();
}
