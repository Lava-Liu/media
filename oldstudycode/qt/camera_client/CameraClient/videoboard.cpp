#include "videoboard.h"
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
VideoBoard::VideoBoard(QWidget *parent) :
    QWidget(parent)
{

    label = new QLabel("iamges",this);
    th1.start();
    connect(&th1,SIGNAL(sendData(QByteArray)),this,SLOT(showPixmap(QByteArray)));


}


void VideoBoard::showPixmap(QByteArray img)
{
    QPixmap pixmap;
    pixmap.loadFromData(img);
    label->setPixmap(pixmap);
    label->update();
}
