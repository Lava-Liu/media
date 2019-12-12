#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QTimer>
#include <QImage>
#include <QString>


class MyButton : public QPushButton
{
public:
    MyButton();
    void setIndex(int ,int );
    void setTimer(bool);
    QString getIndex();
    int counter;
    bool gamer;
    bool live;
    bool stop;

protected:
    void paintEvent(QPaintEvent *);

private:
    int row;
    int column;
    QImage chessImg;
    QTimer *timer;

};

#endif // MYBUTTON_H
