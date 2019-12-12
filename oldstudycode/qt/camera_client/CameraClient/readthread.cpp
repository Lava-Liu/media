#include "readthread.h"
#include <QByteArray>
#include <QImage>
#include <QDebug>
#include <netdb.h>
#include <string>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <QDebug>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <QByteArray>
#include <QPixmap>
#include <QImageReader>
#include <fcntl.h>
#include <QtNetwork/QTcpSocket>
ReadThread::ReadThread()
{   
}

void ReadThread::run()
{
    QTcpSocket tcp;
    tcp.connectToHost("127.0.0.1",10000);

    if(!tcp.waitForConnected()){
        qDebug() << "connect error";
    }else{
        qDebug() << "connect success";
    }

    QByteArray data;
    while(!data.contains("<data>")){
        tcp.waitForReadyRead();
        data.append(tcp.readAll());
    }

    data.remove(0,6);
    while(!data.contains("<data>")){
        tcp.waitForReadyRead();
        data.append(tcp.readAll());
    }

    int index = data.indexOf("<data>");
    qDebug() << "index: " << index;

    emit sendData(data.left(index));
}
