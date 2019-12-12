#include "widget.h"
#include <QPainter>
#include <QPoint>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(500,500);



}


void Widget::drawCross(QPainter &painter, const QPoint &p)
{
    painter.save();

    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::DashLine);
    pen.setWidth(2);
    painter.setPen(pen);

    painter.translate(p);
    painter.drawLine(-10,0,10,0);
    painter.drawLine(0,-10,0,10);

    painter.restore();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPoint satrtPos(50,150);
    drawCross(painter,satrtPos);

    QPainterPath path;


    QPoint endPoint(450,150);
    drawCross(painter,endPoint);
    QPoint c1(150,10);
    drawCross(painter,c1);
    QPoint c2(350,10);
    drawCross(painter,c2);

    path.moveTo(satrtPos);
    path.cubicTo(c1,c2,endPoint);
    painter.drawPath(path);





}



Widget::~Widget()
{

}
