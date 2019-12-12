#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QStackedLayout>
#include <QTextCodec>
#include <QtNetwork/QTcpServer>
#include <QTcpSocket>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *sendBtn;
    QPushButton *listenBtn;
    QPushButton *stopBtn;
    QLineEdit   *lineEdit;
    QTextEdit   *textEdit;
    QLabel      *label;

    QStackedLayout *sLayout;

    QTcpServer  *tcpServer;
    QTcpSocket  *clientSocket;



public slots:
    void listenBtnClicked();
    void stopBtnClicked();
    void sendMessage();
    void newConnectComing();




};

#endif // WIDGET_H
