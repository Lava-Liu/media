#include "mypushbutton.h"
#include <QGridLayout>
#include <QDebug>
MyPushButton::MyPushButton(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *gLayout = new QGridLayout;
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            buttons[i][j]=new MyButton;
            buttons[i][j]->setIndex(i,j);
            buttons[i][j]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
            gLayout->addWidget(buttons[i][j],i,j,1,1);
        }
    }
    gLayout->setSpacing(0);
    setLayout(gLayout);

}

void MyPushButton::restoreButton()
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            buttons[i][j]->setEnabled(false);
            buttons[i][j]->live=false;
            buttons[i][j]->counter=0;
            buttons[i][j]->gamer=true;
            buttons[i][j]->setTimer(false);
            buttons[i][j]->stop=false;
        }
    }

}

void MyPushButton::setButtonEnable(bool chose)
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            buttons[i][j]->setEnabled(chose);
        }
    }
}

void MyPushButton::getButtonClickSignal()
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            connect(buttons[i][j],SIGNAL(clicked()),this,SLOT(buttonClicked()));
            //QString str;
            //str.sprintf("%d,%d",i,j);
            //emit sendButtonIndex(str);
        }
    }
}


void MyPushButton::buttonClicked()
{
    QString str;
    str=((MyButton *)sender())->getIndex();
    if(((MyButton *)sender())->live==true)
    {
       emit sendErrorMessage();
    }else
    {
       //qDebug() << str;
       emit sendButtonIndex(str);
    }
}
