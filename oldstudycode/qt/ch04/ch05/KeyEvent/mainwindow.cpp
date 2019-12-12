#include "mainwindow.h"
#include <QStatusBar>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400,300);
    setFont(QFont("Monospace",20));


}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //if(event->isAutoRepeat())
        //return;
    //statusBar()->showMessage("Key Press");




    qDebug()<< "pressed!" << event->isAutoRepeat();

    QString message("pressed:");
    switch(event->key())
    {
    case Qt::Key_Up:
        message.prepend("Up ");
        break;
    case Qt::Key_Down:
        message.prepend("Down ");
        break;
    case Qt::Key_Left:
        message.prepend("Left ");
        break;
    case Qt::Key_Right:
        message.prepend("Right ");
        break;

    }

    switch(event->key())
    {
    case Qt::Key_F:
        message.prepend("Enter ");
        //break;
        if(event->modifiers() & Qt::ControlModifier)
        {
            QMessageBox::information(this,"Info","Ctrl + F!",QMessageBox::Ok);
        }

    }
    switch(event->key())
    {
    case Qt::Key_Return:
        if(event->modifiers() & Qt::ControlModifier
           && event->modifiers() & Qt::AltModifier)
        {
           QMessageBox::information(this,"Info","Ctrl +Alt+enter ",QMessageBox::Ok);

        }

    }
    if(event->modifiers() & Qt::ControlModifier && event->modifiers() & Qt::ShiftModifier)
    {
       QMessageBox::information(this,"Info","Ctrl + Shift!",QMessageBox::Ok);
    }


    if(event->key() == Qt::Key_Up
       && event->key() == Qt::Key_Down
       && event->key() == Qt::Key_Left
       && event->key() == Qt::Key_Right)
    {
        //statusBar()->showMessage("up+down+left+right");
       QMessageBox::information(this,"Info","just do it !",QMessageBox::Ok);
    }


    if(event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_Return)
    {
            QMessageBox::information(this,"Info","Ctrl + Enter!",QMessageBox::Ok);

    }


statusBar()->showMessage(message);




}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    statusBar()->showMessage("Key Release");
    qDebug() << "Released!" << event->isAutoRepeat();
}


MainWindow::~MainWindow()
{

}
