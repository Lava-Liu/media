#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>
//#include <QReadWriteLock>
//#include "global.h"
//QReadWriteLock rwLock;



class ReadThread : public QThread
{
public:
    ReadThread();


protected:
    void run();




};

#endif // READTHREAD_H
