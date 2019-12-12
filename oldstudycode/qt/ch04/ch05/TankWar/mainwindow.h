#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "wararea.h"
//1.实现多个坦克
//2.实现子弹Bullet
//3.实现子弹Bullet
//子弹池  QVe
//5.边界问题ctor<Bullect> bullects
//4.实现地图绘制
//6.坦克移动效果

//7.坦克爆炸效果




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createMenus();

private:
    WarArea *warArea;







};

#endif // MAINWINDOW_H
