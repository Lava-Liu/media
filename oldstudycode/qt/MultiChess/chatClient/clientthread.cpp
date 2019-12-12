#include "clientthread.h"
#include <netdb.h>
#include <string>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <QDebug>
#include <sys/socket.h>
#include <arpa/inet.h>


ClientThread::ClientThread()
{

}

void ClientThread::run()
{

    sockfd=connet_to_server();
    emit sendSockfd(sockfd);
}

int ClientThread::connet_to_server()
{
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd<0)
    {
        fprintf(stderr,"socket:%s\n",strerror(errno));
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));

    addr.sin_family=AF_INET;
    addr.sin_port=ntohs(10000);
    inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr.s_addr);


    if(::connect(fd,(struct sockaddr *)&addr,sizeof(addr))<0)
    {
        fprintf(stderr,"connect:%s\n",strerror(errno));
        exit(1);
    }

    qDebug() << "connect success!";

    return fd;

}


