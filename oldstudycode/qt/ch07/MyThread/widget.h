#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include "mythread.h"



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();



private:
    MyThread th1;
    MyThread th2;

public slots:
    void threadFinished();
    void threadTerminate();



};

#endif // WIDGET_H
