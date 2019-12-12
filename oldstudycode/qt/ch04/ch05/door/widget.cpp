#include "widget.h"
#include <QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    resize(500,500);




}


void Widget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);



    painter.save();

    painter.setPen(pen);



    QRect rect(50,50,300,400);
    painter.drawRect(rect);



    painter.restore();
    painter.save();


    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);


    painter.setBrush(brush);

    QRect rect2(50,50,300,400);

    painter.drawEllipse(rect2);


    painter.restore();

    painter.save();
    pen.setColor(Qt::green);

    QLine line(200,50,50,250);
    pen.setColor(Qt::gray);
    painter.setPen(pen);
    painter.drawLine(line);

    QLine line2(200,50,350,250);
    painter.drawLine(line2);


    painter.restore();

    painter.save();
    QLine line3(50,250,200,450);
    pen.setColor(Qt::green);
    painter.setPen(pen);
    painter.drawLine(line3);

    QLine line4(350,250,200,450);
    painter.drawLine(line4);

    painter.restore();

    painter.save();
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawEllipse(QPoint(300,250),20,20);


}



Widget::~Widget()
{

}
