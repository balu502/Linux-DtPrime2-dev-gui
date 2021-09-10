#ifndef SETTINGS_PAGE_H
#define SETTINGS_PAGE_H

#include <QMainWindow>

#include <QObject>
#include <QGroupBox>
#include <QBoxLayout>
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
#include <QLineEdit>
#include <QListWidget>
#include <QFileDialog>
#include <QCheckBox>
#include <QDomDocument>
#include <QImage>
#include <QPainter>
#include <QtMath>
#include <QToolButton>

#include "settings_page_global.h"
#include "edit_ip.h"
#include "protocol_list.h"
#include "request_dev.h"
#include "device_param.h"
#include "protocol_lib.h"

#define LEFT_OFFSET 66          // offset for 96,384
#define H_IMAGE 292             // heigth image
#define W_IMAGE_COEF 390        // width image (width/coef: 752/1.93)
#define W_IMAGE 752
#define W_REALIMAGE 825         //
#define H_REALIMAGE 312         //
#define TOP_OFFSET 5
#define COEF_IMAGE 1.93         //


class Image_Widget;

class SETTINGS_PAGESHARED_EXPORT Settings_page: public QMainWindow
{
    Q_OBJECT

public:
    Settings_page(QWidget *parent = 0);
    ~Settings_page();

    ChoiceType_Dialog *Choice_Type;
    Protocol_List   *List_Protocols;

    QGroupBox   *SettingsGroupBox;
    QTabWidget  *Tab_Settings;

    QGroupBox   *Link_Type;
    QPushButton *Ethernet_Button;
    QPushButton *USB_Button;
    QButtonGroup *group_setLinks;

    QGroupBox   *IP_Address;
    QPushButton *ip_address;
    QLabel      *ip_label;
    QPushButton *netmask;
    QLabel      *netmask_label;
    QPushButton *gateway;
    QLabel      *gateway_label;
    QButtonGroup *group_ip;

    QGroupBox   *Diagnostic;
    QListWidget *View_cmd;

    QGroupBox   *Upgrate;
    QPushButton *upgrate_soft;
    QMessageBox *message_settings;

    QGroupBox   *ScreenShot;
    QDialog     *Dialog_Screenshot;
    QPushButton *Make_ScreenShot;
    QCheckBox   *make_screenshot;

    QGroupBox   *Device_Settings;
    QTabWidget  *Settings;
    QGroupBox   *Measure_HeightTubes;
    QPushButton *measure_height;
    QGroupBox   *Exposure_Change;
    QGroupBox   *Video_Box;
    QGroupBox   *Control_Box;
    QImage      *Image;
    Image_Widget *image_Widget;
    QPushButton *measure_Button;
    QPushButton *save_Expo_Button;
    //QCheckBox   *Paint_Mask;
    QToolButton *Paint_Mask;
    QComboBox   *Fluor_Box;
    QPushButton   *Exposure;
    QLabel      *mask_label;


    //...
    QVector<quint16> Digit;         //
    QVector<quint16> Digit_soft;    //
    QVector<int> BUF_Video;         // video buffer

    QVector<short> *XY;
    qint16 *Rx;
    qint16 *Ry;
    QVector<qint8> *offset_XY;
    QMap<QString,QString> *map_InfoDevice;
    QVector<quint16> *Expozition;
    QVector<quint16> Initial_Expo;

    int Count_Tubes;
    QString version_HW;
    double COEF_EXPO_v4;
    //...
    //--- methods ---
    void Treat_VideoImage(QVector<ushort>&, QVector<int>&);
    void Draw_VideoImage(QVector<int>&);
    void Draw_Mask(QPainter*);

    int Round(double);

    Edit_IP *edit_ip;

    void Read_IP();

    void readsettings();
    QTranslator translator;



public slots:
    void GetLogData(QString);   // get logData from Device
    void slot_RunStart();
    void slot_RunStop();
    void measure_Height();
    void Get_Image();
    void Get_Picture(QMap<QString,QByteArray>*);
    void Clear_Image();
    void Get_RefreshInfoDevice();
    void Change_Fluor(int);
    bool Check_ExpoForSave();
    void Save_Exposure();

signals:
    void changeLink(int);
    void update_Software();
    void meas_HeightTubes();
    void MakeMeasure_Request(int,int,int);
    void RefreshInfoDevice();
    void SaveExpo(int,QString);

private slots:  
    void clicked_LinkButtons(QAbstractButton *button);
    void Editing_IP(QAbstractButton *button);
    void Editing_Expo();
    void Write_IP();
    void Upgrade_Soft();
    void Create_ScreenShot();

    void open_USBProtocol();
};
//-----------------------------------------------------------------------------
class Image_Widget: public QWidget
{
    Q_OBJECT

public:
    Image_Widget(QImage *i, QWidget *parent = 0);

protected:
        void paintEvent(QPaintEvent*) Q_DECL_OVERRIDE;
        //void mousePressEvent(QMouseEvent*) Q_DECL_OVERRIDE;
        //void mouseReleaseEvent(QMouseEvent*) Q_DECL_OVERRIDE;
        //void mouseMoveEvent(QMouseEvent*) Q_DECL_OVERRIDE;

public slots:
        void Optic_Mask(bool);
private:
        QImage  *image;
        Settings_page   *p_video;
        bool state;
};

#endif //PROTOCOL_PAGE_H
