#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QStackedLayout>
#include <QtNetwork/QTcpSocket>
#include <QTextCodec>
#include "readthread.h"
#include <QLabel>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void savePicture();
    ReadThread th1;
private:
    QPushButton  *connectBtn;
    QPushButton *disconnectBtn;
    QStackedLayout *sLayout;
    QLineEdit    *ipLine;
    QLineEdit    *messageLine;
    QTextEdit    *infoPad;

    //QTcpSocket   *tcpSocket;
    QLabel     *label;
    QImage image;
protected:
    void paintEvent(QPaintEvent *);

public slots:
    void connectBtnClicked();
    void disconnectBtnClicked();
    void socketConnected();
    void socketDisconnected();
    void sendMessage();
    void setPicture(QPixmap);

    void showImage(QByteArray);
};

#endif // WIDGET_H
