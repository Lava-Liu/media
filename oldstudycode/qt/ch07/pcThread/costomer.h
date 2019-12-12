#ifndef COSTOMER_H
#define COSTOMER_H

#include <QThread>

class Costomer : public QThread
{
public:
    Costomer();


protected:
    void run();

};

#endif // COSTOMER_H
