#include "thread.h"
#include <QDebug>

QMutex Thread::mutex;

Thread::Thread(char ch):ch(ch)
{

}

void Thread::run()
{
    while(1)
    {

        mutex.lock();
        qDebug() << ch;
        qDebug() << ch << ch;
        sleep(1);
        mutex.unlock();
        usleep(20);
    }
}

