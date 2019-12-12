#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>
//#include <QtNetwork/QTcpSocket>
#include <QPixmap>
class ReadThread : public QThread
{
    Q_OBJECT
public:
    ReadThread();

protected:
    void run();

//private:
    //QTcpSocket tcp;
signals:
    void sendData(QByteArray);

};

#endif // READTHREAD_H
