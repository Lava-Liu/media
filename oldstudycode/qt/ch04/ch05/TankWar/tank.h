#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QPoint>
#include <QRect>
#include <QImage>
#include <QPainter>
#include <QTimer>
   // QRect movingRageRect;
   // QTimer *movingActTimer;
enum Direction
{
    Up,
    Down,
    Left,
    Right
};


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


class Tank : public QObject
{
    Q_OBJECT
public:
    explicit Tank(QObject *parent = 0);

    int speed()const;
    void setSpeed(int speed);
    int &rSpeed();
    Direction direction()const;
    void setDirection(Direction direct);

    void forward();//当前的方向
    void stop();//停止移动



    void drawSelf(QPainter &painter);//绘制自身



private:
    int curSpeed;//速度
    Direction curDirect;//方向
    QPoint curPos;//位置
    QRect  imageRect;//抓图区域
    QImage tankBodyImg;//车身贴图

    QTimer *movingTimer;

signals:

public slots:
    void movingForward();

};

#endif // TANK_H
