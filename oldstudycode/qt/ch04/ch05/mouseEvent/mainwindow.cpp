#include "mainwindow.h"
#include <QStatusBar>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400,300);
    setFont(QFont("Monospace",20));

    //打开鼠标追踪
    //setMouseTracking(true);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //statusBar()->showMessage("Press");
    QString message("Press");

    if(event->buttons() & Qt::LeftButton)
    {
        message.prepend(" Left ");
    }
    if(event->buttons() & Qt::RightButton)
    {
        message.prepend(" Right ");
    }
    if(event->buttons() & Qt::MidButton)
    {
        message.prepend(" Mid ");
    }





    /*switch(event->button())
    {
    case Qt::LeftButton:
        message.prepend("Left");
        break;
    case Qt::RightButton:
        message.prepend("Right");
        break;
    case Qt::MidButton:
        message.prepend("Min");
        break;
    default:
        break;
    }*/


    message.append(" at ");
    message.append(QString("%1 , %2").arg(event->globalX()).arg(event->globalY()));

    statusBar()->showMessage(message);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    statusBar()->showMessage("Release");
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    statusBar()->showMessage("Move to");
    QString message("Move to");
    message.append(QString("(%1,%2)").arg(event->x()).arg(event->y()));
    statusBar()->showMessage(message);
}


void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    statusBar()->showMessage("Doubleclicked");
}


MainWindow::~MainWindow()
{

}
