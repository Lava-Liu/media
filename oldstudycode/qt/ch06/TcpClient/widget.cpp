#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QByteArray>
#include <QImage>
#include <QPainter>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));


    ipLine = new QLineEdit(this);
    ipLine->setInputMask("000.000.000.000;_");

    connectBtn = new QPushButton("Connect",this);
    disconnectBtn = new QPushButton("Disconnect",this);
    sLayout = new QStackedLayout;
    sLayout->addWidget(connectBtn);
    sLayout->addWidget(disconnectBtn);
    sLayout->setCurrentIndex(0);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(ipLine);
    hLayout->addLayout(sLayout);

    messageLine = new QLineEdit(this);
    messageLine->setPlaceholderText("Please input your message");
    messageLine->setEnabled(false);


    infoPad = new QTextEdit(this);
    infoPad->setReadOnly(true);
    infoPad->setFixedHeight(300);

    label = new QLabel("image",this);


    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(messageLine);
    vLayout->addWidget(infoPad);
    vLayout->addWidget(label);
    setLayout(vLayout);

    connect(connectBtn,SIGNAL(clicked()),this,SLOT(connectBtnClicked()));
    connect(disconnectBtn,SIGNAL(clicked()),this,SLOT(disconnectBtnClicked()));
    connect(messageLine,SIGNAL(returnPressed()),this,SLOT(sendMessage()));

    //tcpSocket = new QTcpSocket(this);

    //connect(tcpSocket,SIGNAL(connected()),this,SLOT(socketConnected()));
    //connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));
    //connect(&th1,SIGNAL(sendImg(QPixmap)),this,SLOT(setPicture(QPixmap)));
    connect(&th1,SIGNAL(sendData(QByteArray)),this,SLOT(showImage(QByteArray)));
}

void Widget::setPicture(QPixmap img)
{
   label->setPixmap(img);
}
void Widget::connectBtnClicked()
{
    ipLine->setEnabled(false);
    sLayout->setCurrentIndex(1);
    infoPad->append("connected to" + ipLine->text());
    //tcpSocket->connectToHost(ipLine->text(),10000);
    //th1.clientSocket=tcpSocket;
    th1.start();
    //savePicture();


}

void Widget::showImage(QByteArray data)
{
    image.loadFromData(data);
    update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(QRect(0,0,width(),height()),image);
}

void Widget::savePicture()
{
    /*
    QByteArray frame;
    QString str;
    str.append("I am connect!");
    tcpSocket->write(str.toUtf8());

     QByteArray picture;
     while(1)
     {

      if(tcpSocket->isReadable()==true)
     {
      qDebug() << "ready read!";
      //clientSocket->isReadable();
      //picture=tcpSocket->readAll();

      //qDebug() << picture.size();
        qDebug() << tcpSocket->read(1024);
      if(picture.contains("<end>"))
      {//QByteArray y("<end>");
        //picture.remove(0,picture.indexOf(y)+2);
        qDebug() << picture;
        QByteArray z("<end>");
        picture.remove(0,6);
        frame = picture.left(picture.indexOf(z));
        qDebug() << frame;
        QImage img;
        img.loadFromData(frame);
        img.save("1.jpeg");
        qDebug()<<"save success!";
        break;
       }
       usleep(20);
      }

     }
     */
}

void Widget::disconnectBtnClicked()
{
    sLayout->setCurrentIndex(0);

    //tcpSocket->disconnectFromHost();


    ipLine->setEnabled(true);
}

void Widget::socketConnected()
{
    infoPad->append("Connected to  Host successfully!");
    messageLine->setEnabled(true);
}

void Widget::socketDisconnected()
{
    infoPad->append("Already disconnected from host!");
    messageLine->setEnabled(false);
    messageLine->clear();

}

void Widget::sendMessage()
{
    QByteArray message;
    message = messageLine->text().toUtf8();
    //tcpSocket->write(message);
    messageLine->clear();
    infoPad->append("Me:");
    infoPad->append("\t" + message);

}


Widget::~Widget()
{

}
