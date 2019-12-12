#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QMutex>


class Thread : public QThread
{
public:
    Thread(char ch = 'A');



protected:
    void run();

private:
    char ch;
    static QMutex mutex;



};



#endif // THREAD_H
