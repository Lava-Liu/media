#include "widget.h"
//#include <QMutex>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pTh1.start();
    pTh2.start();
    cTh1.start();
    cTh2.start();




}

Widget::~Widget()
{

}
