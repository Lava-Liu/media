#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>
#include <QtNetwork/QTcpSocket>
#include <QPixmap>
class ReadThread : public QThread
{
    Q_OBJECT
public:
    ReadThread();
    QTcpSocket *clientSocket;
protected:
    void run();

signals:
    void sendImg(QPixmap);

    void sendData(QByteArray);

};

#endif // READTHREAD_H
