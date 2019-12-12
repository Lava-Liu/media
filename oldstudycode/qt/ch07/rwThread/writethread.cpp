#include "writethread.h"
#include <QDebug>
#include <QReadWriteLock>

extern QReadWriteLock rwLock;


WriteThread::WriteThread()
{
}



void WriteThread::run()
{
    rwLock.lockForWrite();
    qDebug()<< "I am writing !";
    sleep(3);
    qDebug() << "write over!";
    rwLock.unlock();
}
