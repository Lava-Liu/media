
 #include "widget.h"
#include <QPainter>
#include <QTimer>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent),rubbitStartPos(50,50),tortoiseStartPos(50,230)
{

    rubbitCurPos = rubbitStartPos;
    tortoiseCurpos = tortoiseStartPos;

    resize(800,500);
    finishLinePos = 700;
    rubbitTh.setSpeed(5);
    tortoiseTh.setSpeed(6);

    connect(&rubbitTh,SIGNAL(curPosChanged(int)),this,SLOT(rubbitMoving(int)));
    connect(&tortoiseTh,SIGNAL(curPosChanged(int)),this,SLOT(tortoiseMoving(int)));

    rubbitTh.start();
    tortoiseTh.start();


    movingTimer = new QTimer;
    movingTimer->setInterval(20);
    connect(movingTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(movingTimer,SIGNAL(timeout()),this,SLOT(winerEventHandler()));

    movingTimer->start();


}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //画兔子
    painter.drawImage(rubbitCurPos,QImage(":/rubbit_2.png"));
    //画乌龟
    painter.drawImage(tortoiseCurpos,QImage(":/tortoise_2.png"));

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);

    painter.setPen(pen);
    painter.drawLine(finishLinePos,0,finishLinePos,height());


}

void Widget::rubbitMoving(int curPos)
{
    rubbitCurPos.rx() = rubbitStartPos.x() +curPos;
}
void Widget::tortoiseMoving(int curPos)
{
    tortoiseCurpos.rx() =tortoiseStartPos.x()+curPos;
}

void Widget::winerEventHandler()
{
    if(rubbitCurPos.x()+120 >finishLinePos)
    {
        raceOver("rabbit");
    }
    else if(tortoiseCurpos.x()+120 > finishLinePos)
    {
        raceOver("tortoise");
    }
}

void Widget::raceOver(const QString &winer)
{

        rubbitTh.terminate();
        tortoiseTh.terminate();
        movingTimer->stop();
        disconnect(movingTimer,SIGNAL(timeout()),this,SLOT(winerEventHandler()));
        QMessageBox::information(this,"Race over",QString("Winer is %1!").arg(winer),QMessageBox::Ok);


}

Widget::~Widget()
{

}
