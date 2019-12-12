#include "dialog.h"
#include <QGridLayout>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setFixedSize(350,200);

    QLabel *label = new QLabel(this);
    label->setText("Warning:  System find  a dangerous problem !");
    label->setFont(QFont("Monospae",10,QFont::Bold));
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::red);
    label->setPalette(palette);


    okBtn = new QPushButton(this);
    okBtn->setText("OK");

    cancelBtn = new QPushButton(this);
    cancelBtn->setText("Cancel");

    QHBoxLayout *hLayout =new QHBoxLayout;
    hLayout->addStretch();
    hLayout->addWidget(okBtn);
    hLayout->addSpacing(50);
    hLayout->addWidget(cancelBtn);
    hLayout->addStretch();

    QGridLayout *gLayout = new QGridLayout;
    gLayout->addWidget(label,0,0,2,1);
    gLayout->addLayout(hLayout,2,0,1,1);

    setLayout(gLayout);


    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(close()));



}

Dialog::~Dialog()
{

}
