#include "widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    resize(300,300);
    infoPad = new QTextEdit(this);
    infoPad->setReadOnly(true);

    QVBoxLayout *vLayout = new  QVBoxLayout;
    vLayout->addWidget(infoPad);

    setLayout(vLayout);

    udpServerSocket = new QUdpSocket(this);
    //绑定到10000端口上
    udpServerSocket->bind(10000);
    connect(udpServerSocket,SIGNAL(readyRead()),this,SLOT(dataReceive()));

}


void Widget::dataReceive()
{
    QByteArray message;
    while(udpServerSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpServerSocket->pendingDatagramSize());
        udpServerSocket->readDatagram(datagram.data(),//char *
                                      datagram.size());
        message.append(datagram);

    }
    infoPad->append(message);


}



Widget::~Widget()
{

}
