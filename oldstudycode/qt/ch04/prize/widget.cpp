#include "widget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    qsrand(time(0));

    setFont(QFont("Monospace",40,QFont::Black));
    //setFixedSize(500,350);

    spinBox1 = new QSpinBox(this);
    spinBox1->setRange(1,6);
    //spinBox1->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    //spinBox1->setValue(1);
    spinBox2 = new QSpinBox(this);
    spinBox2->setRange(1,6);

    //spinBox2->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    spinBox3 = new QSpinBox(this);
    spinBox3->setRange(1,6);
    //spinBox3->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    label1 = new QLabel("$",this);
    //label1->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    label2 = new QLabel("$",this);
    //label2->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    label3 = new QLabel("$",this);
    //label3->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    QGridLayout *gLayout = new QGridLayout;
    gLayout->addWidget(spinBox1,0,0);
    gLayout->addWidget(spinBox2,0,1);
    gLayout->addWidget(spinBox3,0,2);
    gLayout->addWidget(label1,1,0);
    gLayout->addWidget(label2,1,1);
    gLayout->addWidget(label3,1,2);

    startBtn = new QPushButton("Start",this);
    stopBtn  = new QPushButton("Stop",this);

    sLayout = new QStackedLayout;
    sLayout->addWidget(startBtn);
    sLayout->addWidget(stopBtn);
    sLayout->setCurrentIndex(0);


    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(gLayout);
    //vLayout->addStretch();
    vLayout->addLayout(sLayout);
    //vLayout->addStretch();
    //QGridLayout *gLayout2 = new QGridLayout;
    //gLayout2->addLayout(gLayout,0,0,2,1);
    //gLayout2->addLayout(sLayout,2,0,1,1);
    setLayout(vLayout);




    timer = new QTimer(this);
    timer->setInterval(1);


    connect(timer,SIGNAL(timeout()),this,SLOT(flushNum()));

    connect(startBtn,SIGNAL(clicked()),this,SLOT(startBtnClicked()));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(stopBtnClicked()));



}

QString Widget::getRand()
{
    QString str;
    str.sprintf("%d",qrand()%6+1);
    return str;
}
void Widget::flushNum()
{
    label1->setText(getRand());
    label2->setText(getRand());
    label3->setText(getRand());
}

void Widget::startBtnClicked()
{
    sLayout->setCurrentIndex(1);
    timer->start();
    spinBox1->setEnabled(false);
    spinBox2->setEnabled(false);
    spinBox3->setEnabled(false);
}
void Widget::stopBtnClicked()
{
    sLayout->setCurrentIndex(0);
    timer->stop();
    spinBox1->setEnabled(true);
    spinBox2->setEnabled(true);
    spinBox3->setEnabled(true);

    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::red);

    QPalette palette2;
    palette2.setColor(QPalette::WindowText,Qt::black);

    if(spinBox1->value()==label1->text().toInt())
    {
        label1->setPalette(palette);
    }else
    {
        label1->setPalette(palette2);
    }
    if(spinBox2->value()==label2->text().toInt())
    {
        label2->setPalette(palette);
    }else

    {
        label2->setPalette(palette2);
    }


    if(spinBox3->value()==label3->text().toInt())
    {
        label3->setPalette(palette);
    }else


    {
        label3->setPalette(palette2);
    }


    //if(spinBox1->value())
    if(spinBox1->value()==label1->text().toInt()
        &&spinBox2->value()==label2->text().toInt()
        &&spinBox3->value()==label3->text().toInt())
    {
        QMessageBox::warning(this,
                             "congradulation!",
                             "You have win a big prize!",QMessageBox::Ok);
    }



}





Widget::~Widget()
{

}
