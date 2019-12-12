#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),th2('B')
{
    th1.start();
    th2.start();


}


Widget::~Widget()
{

}
