#include "mybutton.h"
#include <QPainter>
#include <QPixmap>
#include <QIcon>
MyButton::MyButton():gamer(true),live(false),stop(false)
{
    counter =0;
    timer = new QTimer;
    timer->setInterval(300);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    this->setIcon(QIcon(QPixmap(":/board.png")));




}
void MyButton::setIndex(int x,int y)
{
    row=x;
    column=y;

}
void MyButton::setTimer(bool b)
{
    if(b==true)
    {
        timer->start();
        live=true;
    }
    if(b==false)
    {
        timer->stop();
        //counter=-1;
        stop=true;
        update();
    }
}

QString MyButton::getIndex()
{
    QString str;
    str.sprintf("%d,%d",row,column);
    return str;
}

void MyButton::paintEvent(QPaintEvent *e)
{

    QPushButton::paintEvent(e);
    counter++;
    usleep(200);
    //this->setIcon(QIcon(QPixmap(":/board,png")));


    if(counter%5==0 &&gamer==true &&live==true)
    {
        QPainter painter(this);
       //painter.save();

       painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/black.png"));


        //painter.restore();

    }

    if(counter%5 == 0 &&gamer == false &&live==true)
    {
       QPainter painter(this);
       //painter.save();

       painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/white.png"));


       //painter.restore();

    }
    if(stop==true &&gamer==true &&live==true)
    {
        QPainter painter(this);
       //painter.save();

       painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/black.png"));


       // painter.restore();

    }

    if(stop == true &&gamer == false &&live==true)
    {
       QPainter painter(this);
       //painter.save();

       painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/white.png"));


      // painter.restore();

    }




}










