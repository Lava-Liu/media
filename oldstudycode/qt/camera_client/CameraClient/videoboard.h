#ifndef VIDEOBOARD_H
#define VIDEOBOARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "readthread.h"

class VideoBoard : public QWidget
{
    Q_OBJECT
public:
    explicit VideoBoard(QWidget *parent = 0);

private:
    QLabel *label;
    ReadThread th1;


signals:

public slots:
    void showPixmap(QByteArray);

};

#endif // VIDEOBOARD_H
