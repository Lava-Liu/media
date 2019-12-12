#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include "mybutton.h"

class MyPushButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);
    void setButtonEnable(bool);
    void getButtonClickSignal();
    void restoreButton();
    MyButton  *buttons[30][30];



signals:
    void sendButtonIndex(QString);
    void sendErrorMessage();
public slots:
    void buttonClicked();

};

#endif // MYPUSHBUTTON_H
