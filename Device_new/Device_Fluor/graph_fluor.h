#ifndef GRAPH_FLUOR_H
#define GRAPH_FLUOR_H

#define HISTORY 300

#include <QLabel>
#include <QVector>
#include <QList>
#include <QEvent>
#include <QMouseEvent>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QCursor>
#include <QFont>
#include <QApplication>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QPainter>
#include <QBoxLayout>
#include <QPointF>
#include <QMap>
#include <QPixmap>
#include <QSettings>
#include <QTranslator>

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

#include "Graph_Fluor_global.h"
#include "../Device_page/request_dev.h"
#include "protocol_lib.h"


//-----------------------------------------------------------------------------
class GRAPHFLUORSHARED_EXPORT GraphFluorPlot: public QwtPlot
{
    Q_OBJECT      //widget's signal or slot

public:
    GraphFluorPlot(QWidget *parent = NULL);
    virtual ~GraphFluorPlot();

    void Create_Curve(rt_Protocol*);
    void Delete_Curve();
    void Clear_Graph();
    void Draw_Chart(rt_Protocol*, int channel);
    //void Change_Enable(rt_Protocol*, QVector<short>*);
    //void Change_SizeMarker();

    rt_Protocol             *Prot;
    QwtPlotCurve            *curve;
    QVector<QwtPlotCurve*>  list_Curve;
    int size_symbol;

    QVector<double> X;
    QVector<double> Y;
    int current_fn;

    QWidget         *main_widget;

    QComboBox   *Fluor_Box;
    QLabel      *current_Fn;
    QwtPlotGrid *grid;

    // Lanquage
    void readsettings();
    QTranslator translator;

public slots:
    void slot_NewProtocol(rt_Protocol*);
    void slotRefreshData(QMap<QString,QString>*);
    void slot_RefreshFluor();
    void change_Fluor(int type);
};

#endif // GRAPH_FLUOR_H
