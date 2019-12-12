#include "mainwindow.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    resize(500,500);



}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.scale(1.5,1.5);
    //保存画家的状态
    //画笔，画刷，坐标系....
    painter.save();


    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);



    //画线
    painter.drawLine(0,0,200,200);

    QPoint p1(200,0);
    QPoint p2(0,200);
    painter.drawLine(p1,p2);


    QLine line(100,0,0,100);
    painter.drawLine(line);

    //画点
    painter.drawPoint(50,30);


    painter.restore();

    //矩形
    painter.drawRect(0,0,200,200);
    painter.save();

    painter.rotate(45);



    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QRect rect(50,50,100,100);
    //painter.drawRect(rect);
    //0painter.save();
    painter.translate(100,100);
    painter.rotate(45);
    painter.drawRect(-50,-50,100,100);


    painter.restore();


    //画圆
    painter.drawEllipse(0,0,200,200);
    //painter.drawEllipse(rect);
    painter.drawEllipse(QPoint(100,100),200,100);

    painter.save();
    //brush.setColor(Qt::yellow);
    painter.setBrush(brush);

    //painter.drawEllipse(rect);
    painter.restore();


    painter.drawChord(rect,-90*16,180*16);





}


MainWindow::~MainWindow()
{

}
