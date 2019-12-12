#include "mainwindow.h"
#include <QStatusBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFont(QFont("M",20));
    resize(300,300);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    //statusBar()->showMessage("WheelEcvent",500);
    QString message;
    switch(event->orientation())
    {
    case Qt::Horizontal:
        message.append("Hor");
        break;
    case Qt::Vertical:
        message.append("Ver");
        break;
    }

    message.append(QString("%1").arg(event->delta()));
    statusBar()->showMessage(message,500);

}


MainWindow::~MainWindow()
{

}
