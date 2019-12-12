#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void drawCross(QPainter &painter,const QPoint &p);

protected:
    void paintEvent(QPaintEvent *);



};

#endif // WIDGET_H
