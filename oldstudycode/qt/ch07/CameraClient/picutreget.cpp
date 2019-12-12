#include "picutreget.h"
#include <QByteArray>
#include <QDebug>



PicutreGet::PicutreGet()
{
    clientSocket=new QTcpSocket(this);


}

void PicutreGet::run()
{
   qDebug()  << "wait for start!";
   clientSocket->connectToHost("127.0.0.1",10000);
   qDebug()  << "connect success!";
   QByteArray frame;


    QByteArray picture;
    while(1)
     {
     clientSocket->isReadable();
     qDebug() << "ready read!";
     //clientSocket->isReadable();
     picture.append(clientSocket->readAll());

     if(picture.contains("--"))
     {
      QByteArray y("/n/n");
      picture.remove(0,picture.indexOf(y)+2);
      QByteArray z("--");
      frame = picture.left(picture.indexOf(z));
      QImage img;
      img.loadFromData(frame);
      img.save("1.jpeg");
      break;
      }
      }








    //frame.
   //framImg.save("pict1.jpeg","jpeg");
    //framImg.loadFromData(frame);

    //emit sendPicture(framImg);


}



