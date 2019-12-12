#ifndef TANK_H
#define TANK_H

#include <QWidget>
#include <QTimer>
#include "movingunit.h"
#include "bullet.h"

class Tank : public MovingUnit
{
    Q_OBJECT
public:
    explicit Tank(QObject *parent,const QRect *bodyRects = tankBodys);
    void setDirection(Direction direct);

    void shoot(QList<Bullet*> &bullets);//发射子弹
    void blowUp();//爆炸
    void hitBullets(QList<Bullet *> &bullets);

private:
    int movingActIndex;
    const QRect *tankBodyRects;//坦克贴图采集备选区域
    bool isDone;

protected slots:
    void switchMovingAction();
    void blowUpAction();

    friend class WarArea;
};

#endif // TANK_H
