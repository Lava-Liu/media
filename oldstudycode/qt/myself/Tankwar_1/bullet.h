#ifndef BULLET_H
#define BULLET_H
#include "movingunit.h"
#include <QPoint>
#include <QRect>
#include <QImage>
#include <QPainter>
#include <QTimer>
//enum Direction
//{
//    Up,
//    Down,
//    Left,
//    Right
//};


//坦克抓图选区
const QRect bulletBodyRect(0,0,8,8);
const QRect bullet2BodyRect(8,0,8,8);


const QRect emptyBullet(0,0,0,0);


class Bullet : public MovingUnit
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = 0);
    int speed()const;
    void setSpeed(int speed);
    int &rSpeed();
    Direction direction()const;
    void setDirection(Direction direct);

    void setCurPos(QPoint point);
    QPoint getCurPos();

    void forward();//当前的方向
    void stop();//停止移动



    void drawSelf(QPainter &painter);//绘制自身


    void setImageRect(QRect rect);



private:
    int counter;
    int curSpeed;//速度
    Direction curDirect;//方向
    QPoint curPos;//位置
    QRect  imageRect;//抓图区域
    QImage bulletBodyImg;//车身贴图

    QTimer *movingTimer;
    QTimer *changeTimer;

signals:

public slots:
    void movingForward();
    void changeBody();

};

#endif // BULLET_H
