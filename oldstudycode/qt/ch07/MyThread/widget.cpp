#include "widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    th1.start();
    th2.start();


    connect(&th1,SIGNAL(finished()),this,SLOT(threadFinished()));
    connect(&th1,SIGNAL(terminated()),this,SLOT(threadTerminate()));
}


void Widget::threadFinished()
{
    qDebug( ) << "FInshed signal!";
}
void Widget::threadTerminate()
{
    qDebug() << "Terminated!";
}



Widget::~Widget()
{
    th1.terminate();

    th1.wait();
    th2.terminate();
    th2.wait();
}




