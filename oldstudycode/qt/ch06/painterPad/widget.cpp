#include "widget.h"
#include <QColorDialog>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton(this);
    //QColorDialog::getColor();

    connect(button,SIGNAL(clicked()),this,SLOT(getColor()));

}


void Widget::getColor()
{
    qDebug()<<QColorDialog::getColor();
}


Widget::~Widget()
{

}
