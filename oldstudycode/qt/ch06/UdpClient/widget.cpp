#include "widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    infoPad = new QTextEdit(this);
    infoPad->setReadOnly(true);

    messageLine = new QLineEdit(this);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(infoPad);
    vLayout->addWidget(messageLine);

    setLayout(vLayout);

    udpClientSocket = new QUdpSocket(this);

    connect(messageLine,SIGNAL(returnPressed()),this,SLOT(sendMessage()));



}

void Widget::sendMessage()
{
    QByteArray message;
    message = messageLine->text().toUtf8();

    messageLine->clear();
    udpClientSocket->writeDatagram(message,QHostAddress("127.0.0.1"),10000);

    infoPad->append("Datagram sent!");
}


Widget::~Widget()
{

}
