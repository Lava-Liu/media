#include "bullet.h"

Bullet::Bullet(QObject *parent) :curPos(-32,-32 ),imageRect(bulletBodyRect),bulletBodyImg(":/bullet.png")
        ,MovingUnit(parent),counter(0)

{
    curSpeed  = 5;
    curDirect = Up;
    //curPos = QPoint(0,0);

    movingTimer = new QTimer(this);
    movingTimer->setInterval(20);

    changeTimer = new QTimer(this);
    changeTimer->setInterval(30);


    connect(movingTimer,SIGNAL(timeout()),this,SLOT(movingForward()));

    connect(changeTimer,SIGNAL(timeout()),this,SLOT(changeBody()));
}


void Bullet::drawSelf(QPainter &painter)
{
    painter.save();

    painter.drawImage(curPos,bulletBodyImg,imageRect);

    painter.restore();
}

int  Bullet::speed()const
{
    return curSpeed;
}

void Bullet::setSpeed(int speed)

{
    curSpeed = speed;
}

int &Bullet::rSpeed()
{
    return curSpeed;
}

Direction Bullet::direction()const
{
    return curDirect;
}

void Bullet::setDirection(Direction direct)
{
    curDirect = direct;

    //修改坦克的贴图
    //imageRect = tankBodyDirextion[curDirect];
}

void Bullet::forward()
{
    movingTimer->start();
}

void Bullet::stop()
{
    movingTimer->stop();
    curPos.setX(-32);
    curPos.setY(-32);
}

void Bullet::movingForward()
{
    //根据方向和速度来移动坦克的位置
    switch(curDirect)
    {
    case Up:
        curPos.ry()-= curSpeed;
        if(curPos.ry()<0)
        {
            movingTimer->stop();
        }
        break;
    case Down:
        curPos.ry()+=curSpeed;
        if(curPos.ry()>600-8)
        {
            movingTimer->stop();
        }
        break;
    case Left:
        curPos.rx()-=curSpeed;
        if(curPos.rx()<0)
        {
            movingTimer->stop();
        }
        break;
    case Right:
        curPos.rx()+=curSpeed;
        if(curPos.rx()>800-8)
        {
            movingTimer->stop();
        }
        break;
    }
}

void Bullet::setCurPos(QPoint point)
{
    point.setX(point.x()+14);
    point.setY(point.y()+14);
    curPos =point;
}

QPoint Bullet::getCurPos()
{
    return curPos;
}
void Bullet::changeBody()
{
    if(((counter++)%2)==0)
    {
        imageRect = bullet2BodyRect;
    }else
    {
        imageRect = bulletBodyRect;
    }
}

void Bullet::setImageRect(QRect rect)
{
    imageRect = rect;
}
