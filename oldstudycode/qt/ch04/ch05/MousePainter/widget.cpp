#include "widget.h"
#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
        resize(500,500);


}


void Widget::mousePressEvent(QMouseEvent *event)
{

    QPoint p1;

     if(event->buttons() & Qt::LeftButton)
    {
         //QPoint p1(event->x(),event->y());
            p1.setX(event->x());
            p1.setY(event->y());
    }
     if(event->buttons() & Qt::RightButton )
     {

          QPoint p2(event->x(),event->y());
        //break;
          QPainter painter(this);
          QPen pen;
           pen.setWidth(3);

          painter.drawLine(p1,p2);
      }
}






Widget::~Widget()
{

}
