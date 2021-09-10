#ifndef DEVICE_INFO_H
#define DEVICE_INFO_H

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


#include "device_info_global.h"


//-----------------------------------------------------------------------------
class ItemDelegate_DeviceInformation: public QStyledItemDelegate
{
public:
    ItemDelegate_DeviceInformation()
    {
    }

    void paint (QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};
//-----------------------------------------------------------------------------
class DEVICE_INFOSHARED_EXPORT Device_Info: public QTreeWidget
{
    Q_OBJECT

public:
    Device_Info(QWidget *parent = 0);
    virtual ~Device_Info();

    ItemDelegate_DeviceInformation *Delegate_Info;

    // Lanquage
    void readsettings();
    QTranslator translator;

public slots:
    void clear_Info(void);
    void fill_Info(QMap<QString,QString>*);
    void additioanl_info(QMap<QString,QString>*);   // about Expozition_Def
};

#endif // DEVICE_INFO_H


