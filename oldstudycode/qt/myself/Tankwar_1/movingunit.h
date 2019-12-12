#ifndef MOVINGUNIT_H
#define MOVINGUNIT_H
#include "abstructunit.h"
enum Direction
{
    Up,
    Down,
    Left,
    Right
};

class MovingUnit : public AbstructUnit
{
    Q_OBJECT
public:
    explicit MovingUnit(QObject *parent = 0);

signals:

public slots:

};

#endif // MOVINGUNIT_H
