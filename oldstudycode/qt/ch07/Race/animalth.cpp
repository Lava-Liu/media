#include "animalth.h"

AnimalTh::AnimalTh()
{
    curPos = 0;
    curSpeed = 0;


}


void AnimalTh::run()
{
    while(1)
    {
        curPos+=curSpeed;
        msleep(50);
        emit curPosChanged(curPos);
    }
}

void AnimalTh::setSpeed(int speed)
{
    curSpeed = speed;
}
