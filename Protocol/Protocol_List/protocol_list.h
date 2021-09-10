#ifndef PROTOCOL_LIST_H
#define PROTOCOL_LIST_H

#include <QMainWindow>

#include <QObject>
#include <QGroupBox>
#include <QBoxLayout>
#include <QTreeWidget>
#include <QFont>
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
#include <QShowEvent>
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
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>
#include <QUrl>
#include <QDialog>
#include <QMap>
#include <QDomDocument>
#include <QKeyEvent>
#include <QLineEdit>
#include <QTreeWidgetItem>
#include <QTreeWidgetItemIterator>

#include "protocol_list_global.h"


//-----------------------------------------------------------------------------
class PROTOCOL_LISTSHARED_EXPORT ChoiceType_Dialog: public QDialog
{
    Q_OBJECT

public:
    ChoiceType_Dialog(QWidget *parent = 0);
    ~ChoiceType_Dialog();

    virtual void showEvent(QShowEvent * event);
    virtual void keyPressEvent(QKeyEvent *e);
    //virtual bool event(QEvent *e);

    QPushButton *cancel_Button;
    QPushButton *Ethernet_Button;
    QPushButton *USB_Button;
    QPushButton *Local_Button;
    QButtonGroup *group_Choice;


    int type;
    int mask;

private slots:
    void close_Choice(QAbstractButton*);

signals:
    void sRejimeDevButtons(int,int);
    void sKeyPress(int);

};

//-----------------------------------------------------------------------------
class PROTOCOL_LISTSHARED_EXPORT Protocol_List: public QDialog
{
    Q_OBJECT

public:
    Protocol_List(QWidget *parent = 0);
    ~Protocol_List();

    virtual void showEvent(QShowEvent * event);
    virtual void keyPressEvent(QKeyEvent *e);

    QTreeWidget *tree_Protocols;
    QPushButton *apply_Button;
    QPushButton *cancel_Button;

    QLineEdit *le;

    QString Key_result;
    QStringList header_name;

    void readsettings();
    QTranslator translator;

public slots:
    void Load_Protocols(QMap<QString,QString>*, bool use_files = false);
    void Change_CurrentItem();
    void Apply();

    void Down_CurrentItem();
    void Up_CurrentItem();

signals:
    void sKeyPress(int);

};

#endif // PROTOCOL_LIST_H
