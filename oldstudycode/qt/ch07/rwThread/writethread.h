#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QThread>
//
#include "global.h"
class WriteThread : public QThread
{
public:
    WriteThread();


protected:
    void run();


};

#endif // WRITETHREAD_H
