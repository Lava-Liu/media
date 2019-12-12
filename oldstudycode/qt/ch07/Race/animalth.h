#ifndef ANIMALTH_H
#define ANIMALTH_H

#include <QThread>

class AnimalTh : public QThread
{
    Q_OBJECT
public:
    AnimalTh();
    void setSpeed(int speed);


protected:
    void run();

private:
    int curPos;
    int curSpeed;

signals:
    void curPosChanged(int);

  };

#endif // ANIMALTH_H
