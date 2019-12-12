#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QResizeEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}


void Widget::showEvent(QShowEvent *)
{
    QMessageBox::information(
            this,"Information","showEvent",QMessageBox::Ok);
}

void Widget::closeEvent(QCloseEvent *)
{
    QMessageBox::information(
            this,"Information","closeEvent",QMessageBox::Ok);
}

void Widget::resizeEvent(QResizeEvent *event)
{
        qDebug()<<"resizeEvent";
        qDebug()<<event->oldSize() << " -- > "<< event->size();
}


Widget::~Widget()
{

}
