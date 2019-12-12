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

    //map.loadFromData(data.left(index));

    //emit sendImg(map);





    /*
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

    char buffer[4096];
    //int len=0;
    QString str;
    QByteArray pic;
    QByteArray frame;
    QPixmap img;
    QByteArray temp;
    unsigned int n_read;

    char *information = "connect success!";
    write(fd,information,strlen(information));


    while(1)
    {
        memset(buffer,0,sizeof(buffer));
        n_read = read(fd,buffer,sizeof(buffer));
        //len=strlen(buffer);
        str = buffer;

        str.left(n_read);

        pic.append(str.toAscii());
        //qDebug() << pic;
        if(pic.contains("<data>"))
        {

           temp=pic.right(pic.indexOf("<data>")+6);
           //qDebug() << temp;
           if(temp.contains("<data>"))
           {
               int index = pic.indexOf("<data>",2);
               qDebug() << "index : " << index;
               qDebug() << pic;
               //frame = temp.left(temp.indexOf("<data>"));
               //qDebug() << frame;
               pic.remove(0,6);


               frame=pic.left(index);
               img.loadFromData(frame);
               emit sendImg(img);
               qDebug() << frame;
               qDebug() << frame.size();

               int fd2=open("new.jpg",O_CREAT|O_RDWR|O_TRUNC,0777);
               if(fd2 < 0)
               {
                       fprintf(stderr,"opem: %s\n",strerror(errno));
                       exit(1);
               }
               write(fd2,frame.data(),frame.size());
               close(fd2);

               if(img.loadFromData(frame)==true)
               {
                   qDebug() << "success!";
               }else
               {
                   qDebug() << "false!";
               }

               pic.remove(0,pic.indexOf("<data>"));


               qDebug() << "deal success!";

  */


       }






