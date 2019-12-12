#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPoint>
#include "animalth.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


private:
    const QPoint rubbitStartPos;
    const QPoint tortoiseStartPos;

    QPoint rubbitCurPos;
    QPoint tortoiseCurpos;




    int finishLinePos;

    AnimalTh rubbitTh;
    AnimalTh tortoiseTh;

    QTimer *movingTimer;

    void raceOver(const QString &winer);

protected:
    void paintEvent(QPaintEvent *);

public slots:
    void rubbitMoving(int curPos);
    void tortoiseMoving(int curPos);
    void winerEventHandler();
};

#endif // WIDGET_H
