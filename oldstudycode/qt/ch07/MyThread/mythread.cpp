#include "mythread.h"
#include <QDebug>


MyThread::MyThread()
{
}


void MyThread::run()
{

    //线程处理函数,不能被直接调用需要通过start间接调用
    while(1)
    {
        qDebug() << currentThreadId();
        sleep(1);
    }



}
