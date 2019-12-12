#include "tank.h"
#include <QTimer>

Tank::Tank() :
    curPos(0,0),imageRect(upTankBodyRect),tankBodyImg(":/tanks.png")
{

    curSpeed  = 2;
    curDirect = Up;
    //curPos = QPoint(0,0);

    movingTimer = new QTimer;
    movingTimer->setInterval(20);

    connect(movingTimer,SIGNAL(timeout()),this,SLOT(movingForward()));
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
}

void Tank::stop()
{
    movingTimer->stop();
}

void Tank::movingForward()
{
    //根据方向和速度来移动坦克的位置
    switch(curDirect)
    {
    case Up:
        curPos.ry()-= curSpeed;
        break;
    case Down:
        curPos.ry()+=curSpeed;
        break;
    case Left:
        curPos.rx()-=curSpeed;
        break;
    case Right:
        curPos.rx()+=curSpeed;
        break;
    }
}
