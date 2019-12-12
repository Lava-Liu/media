#include "widget.h"
#include <QStackedLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFont(QFont("Monospace",20));

    textEdit1 = new QTextEdit(this);
    textEdit1->append("this is the first page!");
    textEdit2 = new QTextEdit(this);
    textEdit2->append("this is the second page!");
    textEdit3 = new QTextEdit(this);
    textEdit3->append("this is the third page!");

    QStackedLayout *sLayout = new QStackedLayout;
    sLayout->addWidget(textEdit1);
    sLayout->addWidget(textEdit2);
    sLayout->addWidget(textEdit3);


    slider = new QSlider(this);
    slider->setRange(0,2);//设置范围
    slider->setOrientation(Qt::Horizontal);//朝向
//    slider->setGeometry(0,0,30,100);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(sLayout);
    vLayout->addWidget(slider);


    setLayout(vLayout);
    resize(400,400);

//    sLayout->setCurrentIndex(2);

   connect(slider,SIGNAL(valueChanged(int)),sLayout,SLOT(setCurrentIndex(int)));


}

Widget::~Widget()
{

}
