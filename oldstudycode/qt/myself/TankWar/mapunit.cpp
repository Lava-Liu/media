#include "mapunit.h"

MapUnit::MapUnit():MapImg(":/map.png")
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
