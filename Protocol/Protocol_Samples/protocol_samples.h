#ifndef PROTOCOL_SAMPLES_H
#define PROTOCOL_SAMPLES_H

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

#include "protocol_lib.h"


#include "protocol_samples_global.h"

class PROTOCOL_SAMPLESSHARED_EXPORT Protocol_Samples: public QTreeWidget
{
    Q_OBJECT

public:
    Protocol_Samples(bool results, QWidget* parent = 0);
    QPushButton *expanded_Sample;
    bool view_results;

    void readsettings();
    QTranslator translator;

public slots:
    void clear_Samples(void);
    void fill_Samples(rt_Protocol*);
    void change_Expanded();

};

#endif // PROTOCOL_SAMPLES_H
