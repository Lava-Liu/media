#include "wararea.h"
#include <QPainter>
#include <QKeyEvent>

WarArea::WarArea(QWidget *parent) :
    QWidget(parent)
{
    tank = new Tank(this);//构建一个tank
    //tank->setDirection(Down);
    //tank->forward();

    updateTimer = new QTimer(this);
    updateTimer->setInterval(20);//50Fps

    connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));

    updateTimer->start();

}

void WarArea::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    switch(event->key())
    {
    case Qt::Key_Up:
            tank->setDirection(Up);
            tank->forward();
            break;
    case Qt::Key_Down:
            tank->setDirection(Down);
            tank->forward();
            break;
    case Qt::Key_Left:
            tank->setDirection(Left);
            tank->forward();
            break;
    case Qt::Key_Right:
            tank->setDirection(Right);
            tank->forward();
            break;

    }
}

void WarArea::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    tank->stop();
}


void WarArea::paintEvent(QPaintEvent *)
{
     QPainter painter(this);

     //测试背景
     painter.save();
     painter.setBrush(QBrush(Qt::green));
     painter.drawRect(0,0,width(),height());
     painter.restore();

     //绘制坦克
     tank->drawSelf(painter);


}


