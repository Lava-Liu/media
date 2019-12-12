#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>

class Producer : public QThread
{
public:
    Producer();

protected:
    void run();

};

#endif // PRODUCER_H
