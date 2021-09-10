#ifndef EDIT_IP_H
#define EDIT_IP_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QApplication>
#include <QDialog>
#include <QSettings>
#include <QTranslator>
#include <QPushButton>
#include <QButtonGroup>
#include <QBoxLayout>
#include <QGridLayout>
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
#include <QLineEdit>

enum EditState {sIP = 0, sExpo};

class Edit_IP: public QDialog
{
    Q_OBJECT

public:
    Edit_IP(QWidget *parent = 0);
    ~Edit_IP();

    QGroupBox   *edit_box;
    QGroupBox   *button_box;
    QGroupBox   *control_box;

    QPushButton *apply_Button;
    QPushButton *cancel_Button;
    QLineEdit   *edit_text;
    QPushButton *one_Button;
    QPushButton *two_Button;
    QPushButton *three_Button;
    QPushButton *four_Button;
    QPushButton *five_Button;
    QPushButton *six_Button;
    QPushButton *seven_Button;
    QPushButton *eight_Button;
    QPushButton *nine_Button;
    QPushButton *zero_Button;
    QPushButton *back_Button;
    QPushButton *point_Button;
    QButtonGroup *group_Button;

    QAbstractButton *button;
    EditState state_Edit;

private slots:
    void send_Text(QAbstractButton*);
    void apply();

signals:
    void apply_net();

};

#endif // EDIT_IP_H
