#include "producer.h"
#include <QDebug>
#include <QMutex>
#include <QWaitCondition>



int global;
QMutex mutex;
QWaitCondition cond;
int flag;

Producer::Producer()
{
}


void Producer::run()
{
    while(1)
    {
        mutex.lock();

        while(global > 0)//解决供过于求问题
        {
            mutex.unlock();
            usleep(500);
            mutex.lock();
        }

        int tmp = global;
        sleep(1);
        tmp+=10;
        qDebug()<<"Producer: "<<global << "-->" << tmp;
        global=tmp;


        while(!flag)//保证消费者在等待状态
        {
            mutex.unlock();
            usleep(500);
            mutex.lock();
        }

        //唤醒等待线程
        cond.wakeAll();

        mutex.unlock();
        usleep(200);

    }
}
