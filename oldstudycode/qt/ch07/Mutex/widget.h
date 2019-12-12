#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include "thread.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


private:
    Thread th1;
    Thread th2;



};

#endif // WIDGET_H
