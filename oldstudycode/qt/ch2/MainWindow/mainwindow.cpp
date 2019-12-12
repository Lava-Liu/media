#include "mainwindow.h"
#include <QLineEdit>
#include <QStatusBar>
#include <QTextEdit>
void MainWindow::createMenus()
{   //filemenu
    fileMenu = menuBar()->addMenu("&File");
    newAction = fileMenu->addAction("New");
    openAction = fileMenu->addAction("Open");

    saveMenu = fileMenu->addMenu("Save");
    txtAction = saveMenu->addAction("txt");
    saveMenu->addSeparator();
    docAction = saveMenu->addAction("doc");

    fileMenu->addSeparator();//添加分割线

    exitAction = fileMenu->addAction("Exit");
    exitAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_X));//设置快捷键

//    QKeySequence    组合键


    //editMenu
    editMenu = menuBar()->addMenu("&Edit");
    undoAction = editMenu->addAction("Undo");
    redoAction = editMenu->addAction("Redo");


                        connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));//triggered触发

}



void MainWindow::createToolBars()
{
    mainToolBar = addToolBar("Main");
    //mainToolBar = new QToolBar("Main",this);
    //addToolBar(Qt::LeftToolBarArea,mainToolBar);
//    mainToolBar->setMovable(false);

    mainToolBar->setFloatable(false);


    prevAction = mainToolBar->addAction("Prev");
//    prevAction->setIcon(QIcon(":/icons/rightArrow.png"));
//    mainToolBar->setIconSize(QSize(100,100));
    nextAction = mainToolBar->addAction("Next");
    QLineEdit *serachLine = new QLineEdit(this);
    mainToolBar->addWidget(serachLine);

    mainToolBar->addSeparator();
    mainToolBar->addAction(exitAction);






}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,500);

    //file = menuBar()
    createMenus();
    createToolBars();


    QTextEdit *textEdit=new QTextEdit(this);
    setCentralWidget(textEdit);

    statusBar()->showMessage("welcome",1000);
}

MainWindow::~MainWindow()
{

}
