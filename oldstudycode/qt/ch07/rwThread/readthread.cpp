#include "readthread.h"
#include <QDebug>
#include <QReadWriteLock>

QReadWriteLock rwLock;



ReadThread::ReadThread()
{
}


void ReadThread::run()
{
    rwLock.lockForRead();
    qDebug()<<"I am reading!";
    sleep(2);
    qDebug() << "Read over!";
    rwLock.unlock();

}
