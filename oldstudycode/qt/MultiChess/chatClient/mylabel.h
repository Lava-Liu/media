#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QPixmap>

class MyLabel : public QLabel
{
public:
    MyLabel();
    bool curPlayer;

protected:
    void paintEvent(QPaintEvent *);




};

#endif // MYLABEL_H
