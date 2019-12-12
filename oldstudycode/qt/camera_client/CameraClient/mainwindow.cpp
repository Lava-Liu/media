#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    videoBoard = new VideoBoard;
    setCentralWidget(videoBoard);
}

MainWindow::~MainWindow()
{

}
