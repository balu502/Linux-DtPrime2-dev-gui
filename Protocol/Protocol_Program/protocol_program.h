#ifndef PROTOCOL_PROGRAM_H
#define PROTOCOL_PROGRAM_H

#include <QObject>
#include <QGroupBox>
#include <QBoxLayout>
#include <QTreeWidget>
#include <QFont>
#include <QString>
#include <QSettings>
#include <QTextCodec>
#include <QPoint>
#include <QToolBar>
#include <QPushButton>
#include <QButtonGroup>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>
#include <QSplashScreen>
#include <QPixmap>
#include <QDateTime>
#include <QLabel>
#include <QStatusBar>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QPalette>
#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QEventLoop>
#include <QEvent>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QCloseEvent>
#include <QTranslator>
#include <QProcess>
#include <QTemporaryFile>
#include <QThread>
#include <QGraphicsDropShadowEffect>
#include <QMovie>
#include <QUrl>
#include <QDialog>
#include <QMap>
#include <QHeaderView>
#include <QStyledItemDelegate>
#include <QPalette>
#include <QStyleOptionViewItem>
#include <QPainter>
#include <QScrollArea>
#include <QDomDocument>

#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_symbol.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_zoomer.h"
#include "qwt_picker.h"
#include "qwt_plot_canvas.h"
#include "qwt_curve_fitter.h"
#include "qwt_date_scale_draw.h"
#include "qwt_date_scale_engine.h"
#include "qwt_date.h"
#include "qwt_scale_widget.h"

#include "protocol_lib.h"

#include "protocol_program_global.h"

//-----------------------------------------------------------------------------
class ColorCurve: public QwtPlotCurve
{

public:
    ColorCurve(QWidget *parent = NULL){}
    virtual ~ColorCurve() {}
    QVector<QColor> color_lev;

    virtual void drawLines( QPainter *painter,
                            const QwtScaleMap &xMap, const QwtScaleMap &yMap,
                            const QRectF &canvasRect, int from, int to ) const
    {
        int i,j;

        for(i=from; i< to; i++)
        {
            j = div(i,2).quot;
            if(div(i,2).rem) painter->setPen(Qt::darkGreen);
            else painter->setPen(color_lev.at(j));

            QwtPlotCurve::drawLines( painter, xMap, yMap, canvasRect, i, i+1);
        }
    }

};
//-----------------------------------------------------------------------------

class PROTOCOL_PROGRAMSHARED_EXPORT Plot_ProgramAmpl: public QwtPlot
{
    Q_OBJECT

public:
    Plot_ProgramAmpl(QWidget *parent = NULL);
    virtual ~Plot_ProgramAmpl();

    //QwtPlotCurve *curve;
    ColorCurve      *curve;
    QwtPlotGrid     *grid;
    QLabel          *name_program;
    QLabel          *param_program;

    //void readCommonSettings();
    //QTranslator translator;
    //QString style;

public slots:
    void clear_Program(void);
    void draw_Program(rt_Protocol*);
};

//-----------------------------------------------------------------------------
enum block_Type {bUnknown, bCycle, bMelt, bPause, bHold};

class Block_Pro
{

public:
    QVector<QString>    Level;
    QVector<short>      Measure;
    int                 Num_Cycle;
    block_Type          Type_Block;
    QVector<short>      Incr_Temp;
    QVector<short>      Incr_Time;
    QVector<short>      Gradient;

    Block_Pro()
    {
        Level.reserve(16);
        Measure.reserve(16);
        Num_Cycle = 0;
        Type_Block = bCycle;
        Incr_Temp.reserve(16);
        Incr_Time.reserve(16);
        Gradient.reserve(16);
    }
    ~Block_Pro()
    {
        Level.clear();
        Measure.clear();
        Incr_Temp.clear();
        Incr_Time.clear();
        Gradient.clear();
    }
};
//-----------------------------------------------------------------------------
class PROTOCOL_PROGRAMSHARED_EXPORT Protocol_Program: public QScrollArea
{
    Q_OBJECT

public:
    Protocol_Program(QColor = Qt::transparent, QWidget *parent = NULL);

    QLabel label_Program;

    void readsettings();
    QTranslator translator;

    void draw_Program(rt_Protocol*, int draw_Level = -1);
    void clear_scheme();
};

#endif // PROTOCOL_PROGRAM_H
