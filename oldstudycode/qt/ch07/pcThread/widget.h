#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include "costomer.h"
#include "producer.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


private:
    Costomer cTh1;
    Costomer cTh2;
    Producer pTh1;
    Producer pTh2;


};

#endif // WIDGET_H
