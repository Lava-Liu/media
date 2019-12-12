#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QLineEdit>
#include <QtNetwork/QUdpSocket>
#include <QTextEdit>
#include <QTextCodec>



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLineEdit *messageLine;
    QTextEdit *infoPad;
    QUdpSocket *udpClientSocket;
public slots:
    void sendMessage();


};

#endif // WIDGET_H
