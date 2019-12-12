#include "tank.h"

Tank::Tank(QObject *parent) :curPos(0,0),imageRect(upTankBodyRect),tankBodyImg(":/tanks.png")
       ,MovingUnit(parent),counter(0)
{
    curSpeed  = 2;
    curDirect = Up;
    //curPos = QPoint(0,0);

    movingTimer = new QTimer(this);
    movingTimer->setInterval(20);

    changeTimer = new QTimer(this);
    changeTimer->setInterval(30);


    connect(movingTimer,SIGNAL(timeout()),this,SLOT(movingForward()));

    connect(changeTimer,SIGNAL(timeout()),this,SLOT(changeBody()));

}

void Tank::drawSelf(QPainter &painter)
{
    painter.save();

    painter.drawImage(curPos,tankBodyImg,imageRect);

    painter.restore();
}

int  Tank::speed()const
{
    return curSpeed;
}

void Tank::setSpeed(int speed)

{
    curSpeed = speed;
}

int &Tank::rSpeed()
{
    return curSpeed;
}

Direction Tank::direction()const
{
    return curDirect;
}

void Tank::setDirection(Direction direct)
{
    curDirect = direct;

    //修改坦克的贴图
    imageRect = tankBodyDirextion[curDirect];
}

void Tank::forward()
{
    movingTimer->start();
    changeTimer->start();
}

void Tank::stop()
{
    movingTimer->stop();
    changeTimer->stop();
}

void Tank::movingForward()
{


    //根据方向和速度来移动坦克的位置
    switch(curDirect)
    {
    case Up:
        curPos.ry()-= curSpeed;
        //imageRect = tankBodyDirextion2[curDirect];
        if(curPos.ry()<0)
        {
            movingTimer->stop();
        }
        break;
    case Down:
        curPos.ry()+=curSpeed;
        //imageRect = tankBodyDirextion2[curDirect];
        if(curPos.ry()>600-32)
        {
            movingTimer->stop();
        }
        break;
    case Left:
        curPos.rx()-=curSpeed;
        //imageRect = tankBodyDirextion2[curDirect];
        if(curPos.rx()<0)
        {
            movingTimer->stop();
        }
        break;
    case Right:
        curPos.rx()+=curSpeed;
        //imageRect = tankBodyDirextion2[curDirect];
        if(curPos.rx()>800-32)
        {
            movingTimer->stop();
        }
        break;
    }

}

QPoint Tank::getCurPoint()
{
    return curPos;
}

void Tank::changeBody()
{
    if(((counter++)%2)==0)
    {
        imageRect = tankBodyDirextion2[curDirect];
    }else
    {
        imageRect = tankBodyDirextion[curDirect];
    }
}
void Tank::setImageRect(QRect rect)
{
    imageRect = rect;
}
void Tank::setCurPoint(QPoint point)
{
    curPos = point;
}

QImage Tank::getTankBodyImage()
{
    return tankBodyImg;
}
