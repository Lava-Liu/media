#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    warArea = new WarArea(this);
    warArea->setFocus();//设置焦点

    setCentralWidget(warArea);

}

MainWindow::~MainWindow()
{

}
