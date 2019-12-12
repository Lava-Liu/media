#include "widget.h"
#include <QGridLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFont(QFont("Monospace",20));
    QGridLayout *gridLayout = new QGridLayout;
    for(int i=0;i<9;i++)
    {
        buttons[i] = new QPushButton(this);
        buttons[i]->setText(QString("Button %1").arg(i+1));
        buttons[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
        gridLayout->addWidget(buttons[i],i/4,i%4);

    }
    /*gridLayout->addWidget(buttons[0],0,0);
    gridLayout->addWidget(buttons[1],0,1);
    gridLayout->addWidget(buttons[2],0,2);
    gridLayout->addWidget(buttons[3],1,0);
    gridLayout->addWidget(buttons[4],1,1);
    gridLayout->addWidget(buttons[5],1,2);
    gridLayout->addWidget(buttons[6],2,0);
    gridLayout->addWidget(buttons[7],2,1);
    gridLayout->addWidget(buttons[8],2,2,2,1);*/
//    gridLayout->setContentsMargins(0,0,0,0) //设置组建外边框间隙
//    gridLayout->setRowMinimumHeight(3,100);
//    gridLayout->setColumnMinimumWidth(3,200);
//    gridLayout->setHorizontalSpacing(0);
//    gridLayout->setVerticalSpacing(0);




    setLayout(gridLayout);
}




Widget::~Widget()
{

}
