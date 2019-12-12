#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTextBrowser>
#include <QTextEdit>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include "mypushbutton.h"
#include "mytextedit.h"
#include "mylabel.h"
#include <QTimer>
#include <QtNetwork/QTcpSocket>
#include "clientthread.h"
#include "chatthread.h"
#include <QTextCodec>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    int sockfd;
    bool gamer;
    bool curPlayer;
    int chessNum;


    int myX;
    int myY;
    int tmpX;
    int tmpY;


    bool isWiner(int ,int ,bool,int );

private:
    QTextBrowser *textBrowser;
    //QTextEdit    *textEdit;
    MyTextEdit   *textEdit;
    QListWidget  *listWidget;
    QPushButton  *startBtn;
    QLabel       *timeLabel;
    QLabel       *curPlayerLabel;
    MyLabel       *pictureLabel;

    MyPushButton *chessBoard;

    QTimer      *gamerTimer;
    int sec;
    int min;
    int hor;

    ClientThread connetThread;
    ChatThread   chatThread;


public slots:
    void textEditReturnPressed(QString);
    void startBtnClicked();
    void gmerTimerStart();
    void clientConnectHandler(int);
    void chatMessageHandler(QString);
    void commandMessageHandler(QString);
    void chessMessageHandler(QString);
    void chessErrorHandler();
};

#endif // WIDGET_H
