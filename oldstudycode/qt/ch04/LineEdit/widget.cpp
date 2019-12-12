#include "widget.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    statusBar = new QStatusBar(this);
    //statusBar->;


    setFont(QFont("Monospace",20));
    lineEdit = new QLineEdit(this);

    nameLabel = new QLabel(this);
    nameLabel->setText("0");

    lineEdit2 = new QLineEdit(this);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget((lineEdit));
    hLayout->addWidget(nameLabel);
    hLayout->addWidget(lineEdit2);
    //setLayout(hLayout);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(statusBar);
    vLayout->addLayout(hLayout);
    setLayout(vLayout);

//   connect(lineEdit,SIGNAL(returnPressed()),lineEdit,SLOT(clear()));
//    connect(lineEdit,SIGNAL(returnPressed()),lineEdit2,SLOT(clear()));
//    connect(lineEdit2,SIGNAL(returnPressed()),lineEdit,SLOT(clear()));
//    connect(lineEdit,SIGNAL(textChanged(QString)),lineEdit2,SLOT(setText(QString)));
    connect(lineEdit2,SIGNAL(returnPressed()),lineEdit2,SLOT(clear()));
    connect(lineEdit,SIGNAL(returnPressed()),this,SLOT(updateMessage()));
    connect(lineEdit,SIGNAL(textEdited(QString)),this,SLOT(inputingState(QString)));
    connect(this,SIGNAL(textNumChanged(int)),nameLabel,SLOT(setNum(int)));
}




void Widget::updateMessage()
{

    static int counter;
    counter++;
    if(counter == 3)
    {
       qDebug()<< "third!";
       //断开已经连接的信号与槽
       //1精确断开
//       disconnect(lineEdit,SIGNAL(returnPressed()),this,SLOT(updateMessage()));
       //2.模糊断开
         lineEdit2->disconnect();//与它连接的所有槽函数全部断开
    }

    lineEdit2->setText(lineEdit->text());
    lineEdit->clear();
}

void Widget::inputingState(QString)
{


    statusBar->showMessage("Inputing!",1000);
    //发信号
    emit textNumChanged(lineEdit->text().size());

}



Widget::~Widget()
{

}
