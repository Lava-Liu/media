#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
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
    QTextEdit *infoPad;

    QUdpSocket *udpServerSocket;

public slots:
    void dataReceive();
};

#endif // WIDGET_H
