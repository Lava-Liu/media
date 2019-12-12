#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{


    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    label = new QLabel("qq会员年终特惠，年费会员只要588元,还不快点和你的小伙伴加入qq会员~",this);
    label->setFixedHeight(50);

    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->setFixedSize(600,400);

    listenBtn = new QPushButton("开启服务器",this);
    stopBtn   = new QPushButton("关闭服务器",this);
    sendBtn   = new QPushButton("发送",this);
    sLayout = new QStackedLayout;
    sLayout->addWidget(listenBtn);
    sLayout->addWidget(stopBtn);
    sLayout->setCurrentIndex(0);

    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("请在这里输入");
    lineEdit->setFixedHeight(60);
    lineEdit->setAlignment(Qt::AlignRight);

    QHBoxLayout * hLayout = new QHBoxLayout;
    hLayout->addLayout(sLayout);
    hLayout->addStretch(1);
    hLayout->addWidget(sendBtn);

    QVBoxLayout * vLayout = new QVBoxLayout;
    vLayout->addWidget(label);
    vLayout->addWidget(textEdit);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(lineEdit);

    setLayout(vLayout);

    connect(listenBtn,SIGNAL(clicked()),this,SLOT(listenBtnClicked()));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(stopBtnClicked()));

    tcpServer = new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),SLOT(newConnectComing()));


}

void Widget::listenBtnClicked()
{
    sLayout->setCurrentIndex(1);
    tcpServer->listen(QHostAddress::Any,10000);
}

void Widget::stopBtnClicked()
{
    sLayout->setCurrentIndex(0);
    tcpServer->close();
}

void Widget::sendMessage()
{
    QByteArray message;
    message = clientSocket->readAll();
    textEdit->append(clientSocket->peerAddress().toString()+":");
    textEdit->append("\t"+message);
}

void Widget::newConnectComing()
{
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(sendMessage()));

}

Widget::~Widget()
{

}
