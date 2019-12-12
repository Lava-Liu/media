#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QLabel>
#include <QtNetwork/QTcpSocket>
#include <QStackedLayout>
#include <QTimer>
#include "picutreget.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QLabel      *label;
    QTcpSocket  *tcpSocket;



    QStackedLayout *sLayout;

    QImage   picture;
    QTimer   *timer;

    QThread  th1;
protected:
    void paintEvent(QPaintEvent *);



public slots:

    //void startBtnClicket();
    void getPicture(QImage iamge);
    void startBtnClicked();
    void stopBtnClicked();
};

#endif // WIDGET_H
