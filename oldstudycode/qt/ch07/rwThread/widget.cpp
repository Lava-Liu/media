#include "widget.h"




Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    rTh1.start();
    rTh2.start();
    wTh1.start();
    wTh2.start();


}

Widget::~Widget()
{

}
