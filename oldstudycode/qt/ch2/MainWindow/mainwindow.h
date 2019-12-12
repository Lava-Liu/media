#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createMenus();
    void createToolBars();//init toolbar
private:
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *saveMenu;
    QAction *newAction;
    QAction *openAction;
    QAction *exitAction;

    QAction *undoAction;
    QAction *redoAction;

    QAction *txtAction;
    QAction *docAction;

    QToolBar *mainToolBar;
    QAction  *prevAction;
    QAction   *nextAction;

};

#endif // MAINWINDOW_H
