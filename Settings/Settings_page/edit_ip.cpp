#include "edit_ip.h"


//-----------------------------------------------------------------------------
//--- Edit_IP
//-----------------------------------------------------------------------------
Edit_IP::Edit_IP(QWidget *parent)
    : QDialog(parent)
{
    setFixedSize(260,440);

    setWindowFlags(Qt::ToolTip);
    setStyleSheet("border: 1px solid #777");
    move(270,20);

    state_Edit = sIP;

    //...
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(2);
    layout->setSpacing(2);
    setLayout(layout);

    //... edit ...
    edit_box = new QGroupBox(this);
    edit_box->setObjectName("Transparent");
    QHBoxLayout *layout_edit = new QHBoxLayout;
    layout_edit->setMargin(2);
    layout_edit->setSpacing(2);
    edit_box->setLayout(layout_edit);
    edit_text = new QLineEdit(this);
    edit_text->setFixedHeight(40);
    edit_text->setFocusPolicy(Qt::NoFocus);
    edit_text->setAlignment(Qt::AlignCenter);
    layout_edit->addWidget(edit_text);

    QFont f = qApp->font();
    f.setBold(true);
    f.setPointSize(f.pointSize()+2);
    edit_text->setFont(f);

    //... button ...
    button_box = new QGroupBox(this);
    button_box->setObjectName("Transparent");
    QGridLayout *layout_grid = new QGridLayout;
    button_box->setLayout(layout_grid);
    one_Button = new QPushButton("1",this);
    one_Button->setFixedSize(64,64);
    two_Button = new QPushButton("2",this);
    two_Button->setFixedSize(64,64);
    three_Button = new QPushButton("3",this);
    three_Button->setFixedSize(64,64);
    four_Button = new QPushButton("4",this);
    four_Button->setFixedSize(64,64);
    five_Button = new QPushButton("5",this);
    five_Button->setFixedSize(64,64);
    six_Button = new QPushButton("6",this);
    six_Button->setFixedSize(64,64);
    seven_Button = new QPushButton("7",this);
    seven_Button->setFixedSize(64,64);
    eight_Button = new QPushButton("8",this);
    eight_Button->setFixedSize(64,64);
    nine_Button = new QPushButton("9",this);
    nine_Button->setFixedSize(64,64);
    zero_Button = new QPushButton("0",this);
    zero_Button->setFixedSize(64,64);
    point_Button = new QPushButton(".",this);
    point_Button->setFixedSize(64,64);
    back_Button = new QPushButton("clear",this);
    back_Button->setFixedSize(64,64);

    group_Button = new QButtonGroup(this);
    group_Button->addButton(one_Button);
    group_Button->addButton(two_Button);
    group_Button->addButton(three_Button);
    group_Button->addButton(four_Button);
    group_Button->addButton(five_Button);
    group_Button->addButton(six_Button);
    group_Button->addButton(seven_Button);
    group_Button->addButton(eight_Button);
    group_Button->addButton(nine_Button);
    group_Button->addButton(zero_Button);
    group_Button->addButton(point_Button);
    group_Button->addButton(back_Button);

    layout_grid->addWidget(one_Button, 0, 0);
    layout_grid->addWidget(two_Button, 0, 1);
    layout_grid->addWidget(three_Button, 0, 2);
    layout_grid->addWidget(four_Button, 1, 0);
    layout_grid->addWidget(five_Button, 1, 1);
    layout_grid->addWidget(six_Button, 1, 2);
    layout_grid->addWidget(seven_Button, 2, 0);
    layout_grid->addWidget(eight_Button, 2, 1);
    layout_grid->addWidget(nine_Button, 2, 2);
    layout_grid->addWidget(zero_Button, 3, 0);
    layout_grid->addWidget(point_Button, 3, 1);
    layout_grid->addWidget(back_Button, 3, 2);


    //... control ...
    control_box = new QGroupBox(this);
    control_box->setObjectName("Transparent");
    QHBoxLayout *layout_control = new QHBoxLayout;
    layout_control->setMargin(2);
    layout_control->setSpacing(2);
    control_box->setLayout(layout_control);
    cancel_Button = new QPushButton(tr("Cancel"), this);
    apply_Button = new QPushButton(tr("Apply"), this);
    layout_control->addWidget(apply_Button, 1, Qt::AlignRight);
    layout_control->addWidget(cancel_Button, 0, Qt::AlignRight);


    //...
    layout->addWidget(edit_box,0,Qt::AlignTop);
    //layout->addStretch(1);
    layout->addWidget(button_box, 1);
    layout->addWidget(control_box,0,Qt::AlignBottom);


    connect(group_Button, SIGNAL(buttonReleased(QAbstractButton*)), this, SLOT(send_Text(QAbstractButton*)));
    connect(cancel_Button, SIGNAL(released()), this, SLOT(close()));
    connect(apply_Button, SIGNAL(released()), this, SLOT(apply()));
}
//-----------------------------------------------------------------------------
//--- ~Edit_IP
//-----------------------------------------------------------------------------
Edit_IP::~Edit_IP()
{
    delete edit_box;
    delete control_box;
}
//-----------------------------------------------------------------------------
//--- send_Text(QAbstractButton *button)
//-----------------------------------------------------------------------------
void Edit_IP::send_Text(QAbstractButton *button)
{
    QString str = button->text();
    QString text = edit_text->text();
    if(button == back_Button)
    {
        if(text.length())
        {
            text.remove(text.length()-1, 1);
            edit_text->setText(text);
        }
    }
    else  edit_text->setText(QString("%1%2").arg(text).arg(str));

}
//-----------------------------------------------------------------------------
//--- apply()
//-----------------------------------------------------------------------------
void Edit_IP::apply()
{
    button->setText(edit_text->text());
    if(state_Edit == sIP) emit apply_net();
    close();
}
