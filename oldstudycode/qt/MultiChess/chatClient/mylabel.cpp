#include "mylabel.h"
#include <QPainter>
#include <QPixmap>
#include <QRect>
MyLabel::MyLabel():curPlayer(true)
{
}

void MyLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //QPixmap  pixMap(":/rubbit_2.png");

    //QRect target(0,0,width(),height());
    //QRect source(0,0,pixMap.width(),pixMap.height());
    if(curPlayer==true)
    {
      painter.drawPixmap(QRect(0,0,width(),height()),QPixmap(":/black.png"));
    }
    if(curPlayer==false)
    {
      painter.drawPixmap(QRect(0,0,width(),height()),QPixmap(":/white.png"));
    }


}
