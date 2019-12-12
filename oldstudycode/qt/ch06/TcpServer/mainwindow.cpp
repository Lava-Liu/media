#include "mainwindow.h"
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    resize(400,400);
    setFont(QFont("spce",20));

    listenBtn = new QPushButton("Listen",this);
    stopBtn   = new QPushButton("Stop",this);
    sLayout = new QStackedLayout;
    sLayout->addWidget(listenBtn);
    sLayout->addWidget(stopBtn);
    sLayout->setCurrentIndex(0);


    infoPad   = new QTextEdit(this);
    infoPad->setReadOnly(true);
    infoPad->setFixedHeight(400);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(sLayout);
    vLayout->addWidget(infoPad);

    setLayout(vLayout);

    //setCentralWidget(vLayout);

    connect(listenBtn,SIGNAL(clicked()),SLOT(listenBtnclicked()));
    connect(stopBtn,SIGNAL(clicked()),SLOT(stioBtnclicked()));


    tcpServer = new QTcpServer(this);

    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(newConnectionComing()));

    serverTimer = new QTimer;




}

void MainWindow::listenBtnclicked()
{
    sLayout->setCurrentIndex(1);
    infoPad->append("Start listening...");
    tcpServer->listen(QHostAddress::Any,10000);
    if(tcpServer->isListening())
    {
         infoPad->append("Lintening at 10000! ");
    }
}

void MainWindow::stioBtnclicked()
{

    sLayout->setCurrentIndex(0);
    infoPad->clear();
    infoPad->append("Stop listening... ");
    tcpServer->close();//stop work
    if(!tcpServer->isListening())
    {
        infoPad->append("Server closed");
    }

}

void MainWindow::newConnectionComing()
{
    infoPad->append("NewConnection coming!");
    clientSocket = tcpServer->nextPendingConnection();//从服务器获取客户端连接
    clientSocket->peerAddress().toString();
    infoPad->append(clientSocket->peerAddress().toString()+" Connected!");
    connect(clientSocket,SIGNAL(disconnected()),this,SLOT(clientSocketDisconnect()));
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(dataReceive()));
}


void MainWindow::clientSocketDisconnect()
{
    infoPad->append(clientSocket->peerAddress().toString()+"client Socket   Disconnect! ");
}

void MainWindow::dataReceive()
{
    QByteArray message;
    message = clientSocket->readAll();
    infoPad->append(clientSocket->peerAddress().toString() + ":" );
    infoPad->append("\t" + message);
    //QByteArray -- > QString
    //QString(QByteArray)
}




MainWindow::~MainWindow()
{

}



