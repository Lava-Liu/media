#include "widget.h"
#include <QVBoxLayout>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    startBtn = new QPushButton("Start",this);
    stopBtn  = new QPushButton("Stop",this);

    sLayout  = new QStackedLayout;
    sLayout->addWidget(startBtn);
    sLayout->addWidget(stopBtn);
    sLayout->setCurrentIndex(0);


    label = new QLabel(this);
    label->setFixedSize(400,600);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(label);
    vLayout->addLayout(sLayout);

    timer = new QTimer;
    timer->setInterval(20);

    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    connect(startBtn,SIGNAL(clicked()),this,SLOT(startBtnClicked()));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(stopBtnClicked()));
    //th1.start();
    //qDebug() << "thread start !";




   // connect(&th1,SIGNAL())


}

void Widget::startBtnClicked()
{
    th1.start();
}
void Widget::stopBtnClicked()
{

}

void Widget::paintEvent(QPaintEvent *)
{

}

void Widget::getPicture(QImage iamge)
{
    picture = iamge;
}


Widget::~Widget()
{

}
