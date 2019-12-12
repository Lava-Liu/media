#include "widget.h"
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300,150);

    nameLable = new QLabel(this);
    nameLable->setText("username:");
    lineEdit1 = new QLineEdit(this);
    QHBoxLayout *hLayout1 = new QHBoxLayout;
    hLayout1->addWidget(nameLable);
    hLayout1->addWidget(lineEdit1);
//    setLayout(hLayout1);


    pwdLable = new QLabel(this);
    pwdLable->setText("passwd:     ");
    lineEdit2 = new QLineEdit(this);
    lineEdit2->setEchoMode(QLineEdit::Password);
    //设置显示模式
    QHBoxLayout *hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(pwdLable);
    hLayout2->addWidget(lineEdit2);


    okBtn = new QPushButton(this);
    okBtn->setText("OK");
    cancelBtn = new QPushButton(this);
    cancelBtn->setText("Cancel");
    QHBoxLayout *hLayout3 = new QHBoxLayout;
    hLayout3->addStretch();
    hLayout3->addWidget(okBtn);
    hLayout3->addStretch();
    hLayout3->addWidget(cancelBtn);
    hLayout3->addStretch();



    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    vLayout->addLayout(hLayout3);

    setLayout(vLayout);


    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(close()));

}

Widget::~Widget()
{

}
