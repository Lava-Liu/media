#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,300);
    setFont(QFont("Monospace",20));
    QHBoxLayout *hBox =new QHBoxLayout;
    for(int i=0;i<3;i++)
    {
        buttons[i]=new QPushButton(this);
        buttons[i]->setText(QString("Button %1").arg(i+1));
//        buttons[i]->setGeometry(0,i*50,100,30);
        buttons[i]->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);//水平策略，竖直策略
//        hBox->addWidget(buttons[i]);//向布局管理器添加组建

    }
//    hBox->addStretch(1);//添加弹性因子

    hBox->addWidget(buttons[0]);
//    hBox->addSpacing(100);//设置间隙
    hBox->addWidget(buttons[1]);
//  hBox->addSpacing(200);
    hBox->addWidget(buttons[2]);
//    hBox->addStretch(1);

    hBox->setContentsMargins(0,0,0,0);// 设置边框宽度
    //left right top bottlom

//    hBox->setSpacing(300);
    setLayout(hBox);//使用hbox来调用布局

}

Widget::~Widget()
{

}
