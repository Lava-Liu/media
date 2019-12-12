#ifndef WARAREA_H
#define WARAREA_H

#include <QWidget>
#include "tank.h"

class WarArea : public QWidget
{
    Q_OBJECT
public:
    explicit WarArea(QWidget *parent = 0);

private:
    Tank *tank;
    QTimer *updateTimer;
signals:

public slots:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
};

#endif // WARAREA_H
