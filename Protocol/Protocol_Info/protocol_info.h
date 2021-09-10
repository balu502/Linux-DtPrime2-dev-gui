#ifndef PROTOCOL_INFO_H
#define PROTOCOL_INFO_H

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
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDomDocument>

#include "protocol_lib.h"

#include "protocol_info_global.h"

//-----------------------------------------------------------------------------
class PlateItemDelegate: public QStyledItemDelegate
{
public:
    PlateItemDelegate()
    {
    }

    void paint (QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
//-----------------------------------------------------------------------------
class PROTOCOL_INFOSHARED_EXPORT PlateTableWidget: public QTableWidget
{
    Q_OBJECT

public:

    PlateTableWidget(int rows, int cols, QWidget* parent = 0)
                : QTableWidget(rows, cols, parent)
        {
            setSelectionMode(QAbstractItemView::NoSelection);
            setEditTriggers(QAbstractItemView::NoEditTriggers);
            delegate = new PlateItemDelegate();
            setItemDelegate(delegate);
        }
    virtual ~PlateTableWidget(){ delete delegate;}

    PlateItemDelegate *delegate;

public slots:
    void clear_Plate(void) {clear(); setRowCount(0); setColumnCount(0); repaint();}
    void fill_Plate(rt_Protocol*);
};

//-----------------------------------------------------------------------------
class ItemDelegate_Information: public QStyledItemDelegate
{
public:
    ItemDelegate_Information()
    {
    }

    void paint (QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};
//-----------------------------------------------------------------------------
class PROTOCOL_INFOSHARED_EXPORT Protocol_Info: public QTreeWidget
{
    Q_OBJECT

public:
    Protocol_Info(QWidget *parent = 0);
    virtual ~Protocol_Info();

    ItemDelegate_Information *Delegate_Info;

    void readsettings();
    QTranslator translator;

public slots:
    void clear_Info(void);
    void fill_Info(rt_Protocol*);
};

#endif // PROTOCOL_INFO_H
