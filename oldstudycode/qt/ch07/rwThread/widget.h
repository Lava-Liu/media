#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include "readthread.h"
#include "writethread.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    ReadThread rTh1;
    ReadThread rTh2;
    WriteThread wTh1;
    WriteThread wTh2;


};

#endif // WIDGET_H
