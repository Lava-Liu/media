#include "widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    min(0),sec(0),msec(0)
{
    //setFont(QFont("Monspace",12,QFont::Bold));
    setFixedSize(400,50);
    timerPad = new QLabel(this);
    timerPad->setFont(QFont("dsa",20,QFont::Black));
    timerPad->setText("00'00''000");
    startBtn = new QPushButton("Start",this);
//    startBtn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    stopBtn  = new QPushButton("Stop",this);


    sLayout = new QStackedLayout;
    sLayout->addWidget(startBtn);
    sLayout->addWidget(stopBtn);
    sLayout->setCurrentIndex(0);//设置索引



    clearBtn = new QPushButton("Clear",this);
    //clearBtn->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(timerPad);
    hLayout->addLayout(sLayout);
    hLayout->addWidget(clearBtn);

    setLayout(hLayout);


    connect(startBtn,SIGNAL(clicked()),this,SLOT(startBtnClicked()));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(stopBtnClicked()));
    connect(clearBtn,SIGNAL(clicked()),this,SLOT(clearBtnClicked()));

    timer = new QTimer(this);
    timer->setInterval(1);

    connect(timer,SIGNAL(timeout()),this,SLOT(flushTime()));


}

void Widget::startBtnClicked()
{
    sLayout->setCurrentIndex(1);
    timer->start();//开启计时器

    clearBtn->setEnabled(false);
}

void Widget::stopBtnClicked()
{
    sLayout->setCurrentIndex(0);
    timer->stop();

    clearBtn->setEnabled(true);
}
void Widget::clearBtnClicked()
{
    min = 0;
    sec = 0;
    msec = -1;
    flushTime();

}

//void widget::addTImeValue()


void Widget::flushTime()
{
    msec++;
    if(msec == 1000)
    {
        sec++;
        msec = 0;
        if(sec == 60)
        {
            min++;
            sec = 0;
            if(min == 60)
            {
                min = 0;
            }
        }
    }
    QString timeStr;
    timeStr.sprintf("%02d'%02d''%03d",min,sec,msec);
    timerPad->setText(timeStr);
}


Widget::~Widget()
{

}
