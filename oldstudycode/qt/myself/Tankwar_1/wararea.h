#ifndef WARAREA_H
#define WARAREA_H

#include <QWidget>
#include "mapunit.h"
#include "tank.h"
#include "bullet.h"


const QRect bomb1(0,0,32,32);
const QRect bomb2(32,0,32,32);
const QRect bomb3(64,0,32,32);
const QRect bomb4(96,0,32,32);
const QRect bomb5(128,0,32,32);
const QRect bomb6(160,0,32,32);
const QRect bomb7(192,0,32,32);
const QRect bombDirextion[]=
{
    bomb1,
    bomb2,
    bomb3,
    bomb4,
    bomb5,
    bomb6,
    bomb7


};



class WarArea : public QWidget
{
    Q_OBJECT
public:
    explicit WarArea(QWidget *parent = 0);



    void bomb(QPainter &painter);

private:
    int counter;
    Tank *tank;
    Tank *badTank;
    MapUnit *map;
    Bullet *bullet[10];
    QTimer *updateTimer;
    QVector<Bullet *>list;
    QVector<Bullet *>::iterator iter;

    int bombcounter;
    QImage bombImg;
    QTimer *bombTimer;
    QRect  imageRect;



signals:

public slots:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    //void startBomb();

};

#endif // WARAREA_H
