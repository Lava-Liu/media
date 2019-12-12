#ifndef TANK_H
#define TANK_H
#include "movingunit.h"
#include <QPoint>
#include <QRect>
#include <QImage>
#include <QPainter>
#include <QTimer>


//坦克抓图选区
const QRect upTankBodyRect(0,0,32,32);
const QRect downTankBodyRect(0,32,32,32);
const QRect leftTankBodyRect(0,64,32,32);
const QRect rightTankBodyRect(0,96,32,32);
const QRect tankBodyDirextion[]=
{
    upTankBodyRect,
    downTankBodyRect,
    leftTankBodyRect,
    rightTankBodyRect
};

const QRect upTankBodyRect2(32,0,32,32);
const QRect downTankBodyRect2(32,32,32,32);
const QRect leftTankBodyRect2(32,64,32,32);
const QRect rightTankBodyRect2(32,96,32,32);
const QRect tankBodyDirextion2[]=
{
    upTankBodyRect2,
    downTankBodyRect2,
    leftTankBodyRect2,
    rightTankBodyRect2
};


const QRect upTankBodyRect3(64,0,32,32);
const QRect downTankBodyRect3(64,32,32,32);
const QRect leftTankBodyRect3(64,64,32,32);
const QRect rightTankBodyRect3(64,96,32,32);
const QRect tankBodyDirextion3[]=
{
    upTankBodyRect3,
    downTankBodyRect3,
    leftTankBodyRect3,
    rightTankBodyRect3
};



class Tank : public MovingUnit
{
    Q_OBJECT
public:
    explicit Tank(QObject *parent = 0);
    int speed()const;
    void setSpeed(int speed);
    int &rSpeed();
    Direction direction()const;
    void setDirection(Direction direct);
    QPoint getCurPoint();
    void setCurPoint(QPoint point);
    void setImageRect(QRect rect);
    QImage getTankBodyImage();
    void forward();//当前的方向
    void stop();//停止移动



    void drawSelf(QPainter &painter);//绘制自身



private:
    int counter;

    int curSpeed;//速度
    Direction curDirect;//方向
    QPoint curPos;//位置
    QRect  imageRect;//抓图区域
    QImage tankBodyImg;//车身贴图


    QTimer *movingTimer;
    QTimer *changeTimer;


signals:

public slots:
    void movingForward();
    void changeBody();
};

#endif // TANK_H
