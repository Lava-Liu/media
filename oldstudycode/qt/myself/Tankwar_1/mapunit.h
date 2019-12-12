#ifndef MAPUNIT_H
#define MAPUNIT_H
#include "abstructunit.h"
#include <QRect>
#include <QImage>

const QRect grassRect(0,0,32,32);
const QRect metalRect(32,0,32,32);
const QRect brickRect(64,0,32,32);
const QRect bushRect(0,32,32,32);
const QRect water1Rect(32,0,32,32);
const QRect water2Rect(64,0,32,32);

class MapUnit : public AbstructUnit
{
    Q_OBJECT
public:
    explicit MapUnit(QObject *parent = 0);

    QRect grass();
    QRect metal();
    QRect brick();
    QRect bush();
    QRect water1();
    QRect water2();
    QImage getMapImg();
private:
    QRect  imageRect;//抓图区域
    QImage MapImg;//车身贴图

signals:

public slots:

};

#endif // MAPUNIT_H
