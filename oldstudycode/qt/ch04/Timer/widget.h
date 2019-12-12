#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QLabel>
#include <QStackedLayout>
#include <QTimer>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLabel    *timerPad;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *clearBtn;
    QStackedLayout *sLayout;

    int min;
    int sec;
    int msec;
    QTimer *timer;

public slots:
    void startBtnClicked();
    void stopBtnClicked();
    void clearBtnClicked();

    void flushTime();

};

#endif // WIDGET_H
