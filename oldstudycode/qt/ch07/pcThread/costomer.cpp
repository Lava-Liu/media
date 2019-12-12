#include "costomer.h"
#include <QDebug>
#include <QMutex>
#include <QWaitCondition>

extern int global;
extern QMutex mutex;
extern QWaitCondition cond;
extern int flag;

Costomer::Costomer()
{
}

void Costomer::run()
{
    while(1)
    {

      mutex.lock();

      while(global <= 0)//解决供不应求问题
      {
          flag++;

          //等待cond信号通知
          cond.wait(&mutex);

          flag--;
      }

      int temp = global;
      temp--;
      sleep(1);
      qDebug() <<"Constomer:" <<global << "-->" << temp;
      global = temp;

      mutex.unlock();
      usleep(20);

  }




}
