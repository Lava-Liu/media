
#include "wararea.h"
#include <QPainter>
#include <QPoint>
#include <QKeyEvent>
#include <QVector>
#include <QRect>
#include <QDebug>
WarArea::WarArea(QWidget *parent) :
        QWidget(parent),counter(0),bombImg(":/blowup.png"),imageRect(bomb1)
{
    map = new MapUnit;
    tank = new Tank(this);//构建一个tank

    badTank = new Tank(this);
    badTank->setImageRect(downTankBodyRect3);
    QPoint p1(400,200);
    badTank->setCurPoint(p1);

    for(int i=0;i<10;i++)
    {
        bullet[i] =new Bullet(this);
        list.push_front(bullet[i]);
    }
    iter  = list.begin();

    //bullet = new Bullet(this);
    //tank->setDirection(Down);
    //tank->forward();

    updateTimer = new QTimer(this);
    updateTimer->setInterval(20);//50Fps

    bombTimer = new QTimer(this);
    bombTimer->setInterval(500);

    connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(bombTimer,SIGNAL(timeout()),this,SLOT(startBomb()));

    updateTimer->start();

}

void WarArea::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    switch(event->key())
    {
    case Qt::Key_Up:
            tank->setDirection(Up);
            tank->forward();
            break;
    case Qt::Key_Down:
            tank->setDirection(Down);
            tank->forward();
            break;
    case Qt::Key_Left:
            tank->setDirection(Left);
            tank->forward();
            break;
    case Qt::Key_Right:
            tank->setDirection(Right);
            tank->forward();
            break;
    case Qt::Key_Space:

            (*iter)->setCurPos(tank->getCurPoint());
            (*iter)->setDirection(tank->direction());
            (*iter)->forward();
            iter++;

            //list.pop_front()
            //list.push_back(list.first());
            //list.pop_front();
            //list.push_front(list.at(1));

    }
}


void WarArea::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    tank->stop();
}


void WarArea::paintEvent(QPaintEvent *)
{
     QPainter painter(this);

     //测试背景
     painter.save();
     //painter.setBrush(QBrush(Qt::green));
     //painter.drawRect(0,0,width(),height());
     for(int i=0;i<800;i+=32)
     {
         for(int j=0;j<600;j+=32)
         {
            QPoint point(i,j);
             painter.drawImage(point,map->getMapImg(),map->grass());
     //painter.drawImage();
         }
     }



     painter.restore();

     QRect rect((badTank->getCurPoint()).x(),(badTank->getCurPoint()).y(),32,32);





    QRect badrect(0,0,0,1);



     QVector<Bullet *>::iterator iter2 = list.begin();
     for(iter2;iter2!=list.end();iter2++)
     {

         (*iter2)->drawSelf(painter);
         //if(((*iter2)->getCurPos()).x() < 0 || ((*iter2)->getCurPos()). x()> 800)
         //{
             //Bullet *bul =*iter;
           //  list.push_back(*iter2);
             //list.pop_front();
       //}
        QRect rect2(((*iter2)->getCurPos()).x(),((*iter2)->getCurPos()).y(),8,8);

        if( !rect.intersects(rect2) )
        {
             badTank->drawSelf(painter);
        }else
        {
            qDebug()<<"intersects invoed!";



            painter.save();

            badTank->setImageRect(badrect);
            painter.drawImage(badTank->getCurPoint(),bombImg,imageRect);
            imageRect = bombDirextion[counter++];

            painter.restore();
            qDebug() << counter;
            if(counter >= 7)
            {
                (*iter2)->setImageRect(badrect);
                (*iter2)->stop();
            }


//            bomb(painter);
//            bombTimer->start();
        }
//        if((bullet[0]->getCurPos().x()<8 || (bullet[0]->getCurPos()).y()<8))
//        {
//            qDebug()<<"delete";
//            delete bullet[0];
//        }

     }

     //绘制坦克
     tank->drawSelf(painter);








}
//void WarArea::bomb(QPainter &painter)
//{
//    painter.save();

////    painter.drawImage(badTank->getCurPoint(),bombImg,imageRect);
////    imageRect = bombDirextion[counter];
//    if(counter == 7)
//    {
//        bombTimer->stop();
//        counter = 0;
//    }

//    painter.restore();
//}

//void WarArea::startBomb()
//{
//    //counter++;
//}
