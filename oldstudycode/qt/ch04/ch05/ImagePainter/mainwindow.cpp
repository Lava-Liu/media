#include "mainwindow.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,500);
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//ctrate a painter and give him this
    QImage image(":/air.png");
    QPoint pos(50,50);
    painter.translate(300,0);//移动坐标系
    painter.rotate(90);//转动坐标系


    //painter.drawImage(pos,image);
    //painter.drawImage(300,50,image);

    QRect srcRect(60,0,60,300);
    QRect tarRect(50,130,100,100);
    //painter.drawImage(pos,image,srcRect);
    painter.drawImage(tarRect,image);



}


MainWindow::~MainWindow()
{

}
