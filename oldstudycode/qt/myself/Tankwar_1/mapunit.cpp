#include "mapunit.h"

MapUnit::MapUnit(QObject *parent) :MapImg(":/map.png")
    ,AbstructUnit(parent)
{
}
QRect MapUnit::grass()
{
    return grassRect;
}
QRect MapUnit::metal()
{
    return metalRect;
}
QRect MapUnit::brick()
{
    return brickRect;
}
QRect MapUnit::bush()
{
    return bushRect;
}
QRect MapUnit::water1()
{
    return water1Rect;
}
QRect MapUnit::water2()
{
    return water2Rect;
}
QImage MapUnit::getMapImg()
{
    return MapImg;
}
