#include "mainwindow.h"
#include <QMenuBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenus();
    resize(800,600);
    warArea = new WarArea(this);
    warArea->setFocus();//设置焦点

    setCentralWidget(warArea);
}


void MainWindow::createMenus()
{
    menuBar()->addMenu("&Game");
    menuBar()->addMenu("&Help");

}


MainWindow::~MainWindow()
{

}
