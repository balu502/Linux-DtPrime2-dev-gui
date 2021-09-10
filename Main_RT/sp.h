#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QTimer>
#include <QApplication>
#include <QStyleOptionProgressBarV2>
#include <QProgressBar>
#include <QGroupBox>
#include <QString>
#include <QWidget>
#include <QDialog>
#include <QSettings>
#include <QTranslator>
#include <QPushButton>
#include <QBoxLayout>
#include <QTabWidget>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QIcon>
#include <QFont>
#include <QShowEvent>
#include <QDebug>
#include <QFontDialog>
#include <QTranslator>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>
#include <QMouseEvent>


class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    SplashScreen(QApplication *app, QString lang = "en", QWidget *parent = 0, int param = 0);
    virtual ~SplashScreen();



    int m_progress;
    QApplication *app;
    QProgressBar *progress;
    QGroupBox *box;
    QGroupBox *box_web;
    QLabel    *name;
    QLabel    *icon;
    QLabel    *web_address;
    QLabel    *version;
    QLabel    *last_mod;
    QLabel    *logo;

    QLabel    *web_info;

    QLabel    *StandBy_Label;

    //void readCommonSettings();
    //QString lang;


signals:
    void s_PowerWakeup(int);

public slots:
    void Get_IP(QString);
    void Set_StandBy(QString);
    void Set_ShutDown(QString);

    void setProgress()
    {
      m_progress += 5;
      if (m_progress > 100)
        m_progress = 100;
      if (m_progress < 0)
        m_progress = 0;
      update();
      app->processEvents();
    }



private:
    QTimer *timer;




protected:
    void mousePressEvent(QMouseEvent * event);
    //void drawContents(QPainter *painter);

};

#endif // SPLASHSCREEN_H
