#ifndef CHATTHREAD_H
#define CHATTHREAD_H

#include <QThread>

class ChatThread : public QThread
{
    Q_OBJECT
public:
    ChatThread();
    int sockfd;
    void run();

signals:
    void sendChatMessage(QString);
    void sendCommandMessage(QString);


};

#endif // CHATTHREAD_H
