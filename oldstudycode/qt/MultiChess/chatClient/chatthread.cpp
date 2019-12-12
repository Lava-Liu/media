#include "chatthread.h"

ChatThread::ChatThread()
{
}

void ChatThread::run()
{
    char buffer[1024];
    int len=0;
    QString str;
    while(1)
    {
        memset(buffer,0,sizeof(buffer));
        read(sockfd,buffer,sizeof(buffer));

        len=strlen(buffer);
        str = buffer;
        str.left(len);
        if(str.contains("<Command:>"))
        {
            str.remove(0,10);
            emit sendCommandMessage(str);
            continue;
        }


        emit sendChatMessage(str);
    }


}
