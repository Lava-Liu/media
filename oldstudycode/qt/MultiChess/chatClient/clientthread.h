#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>

class ClientThread : public QThread
{
    Q_OBJECT
public:
    ClientThread();

    int connet_to_server();
    void run();

signals:
   void sendSockfd(int);

private:
    int sockfd;


};

#endif // CLIENTTHREAD_H
