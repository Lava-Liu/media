#include "widget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   setFixedSize(350,200);

   QGridLayout *gLayout = new QGridLayout;
    for(int i = 0;i<23;i++)
    {
        buttons[i] = new QPushButton(this);
        buttons[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        if(i<10)
        {
           buttons[i]->setText(QString("%1").arg(i));
        }
        if(i==9)
        {
           for(int j=9;j>=0;j--)
            {
               gLayout->addWidget(buttons[j],j/3,j%3);

            }

        }
     }
    buttons[0]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[1]->setShortcut(QKeySequence(Qt::Key_1));
    buttons[2]->setShortcut(QKeySequence(Qt::Key_2));
    buttons[3]->setShortcut(QKeySequence(Qt::Key_3));
    buttons[4]->setShortcut(QKeySequence(Qt::Key_4));
    buttons[5]->setShortcut(QKeySequence(Qt::Key_5));
    buttons[6]->setShortcut(QKeySequence(Qt::Key_6));
    buttons[7]->setShortcut(QKeySequence(Qt::Key_7));
    buttons[8]->setShortcut(QKeySequence(Qt::Key_8));
    buttons[9]->setShortcut(QKeySequence(Qt::Key_9));
   /* buttons[10]->setShortcut(QKeySequence(Qt::key_));
    buttons[11]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[12]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[13]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[14]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[15]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[16]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[17]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[18]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[19]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[20]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[21]->setShortcut(QKeySequence(Qt::Key_0));
    buttons[22]->setShortcut(QKeySequence(Qt::Key_0));*/




        buttons[10]->setText(".");
        buttons[11]->setText("%");
        gLayout->addWidget(buttons[10],3,1);
        gLayout->addWidget(buttons[11],3,2);


        QGridLayout *gLayout2 = new QGridLayout;
        buttons[12]->setText("/");
        buttons[13]->setText("undo");
        buttons[14]->setText("del");
        buttons[15]->setText("*");
        buttons[16]->setText("(");
        buttons[17]->setText(")");
        buttons[18]->setText("-");
        buttons[19]->setText("x^2");
        buttons[20]->setText("sqrt");
        buttons[21]->setText("+");
        buttons[22]->setText("=");

        for(int k = 12;k<=21;k++)
        {
            gLayout2->addWidget(buttons[k],(k-12)/3,(k-12)%3);
        }
        gLayout2->addWidget(buttons[22],3,1,1,2);

       QHBoxLayout *hLayout = new QHBoxLayout;
       hLayout->addLayout(gLayout);
       hLayout->addLayout(gLayout2);



       lineEdit =new QLineEdit(this);
       lineEdit->setFont(QFont("Monoce",20,QFont::Black));
       lineEdit->home(true);
       lineEdit->setAlignment(Qt::AlignRight);
       lineEdit->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);


       //QVBoxLayout *vLayout = new QVBoxLayout;
       //vLayout->addWidget(lineEdit);
       //vLayout->addLayout(hLayout);
       //vLayout->setContentsMargins(0,0,0,0);

       //vLayout->setSpacing(1);
       QGridLayout *gLayout3 = new QGridLayout;
       gLayout3->addWidget(lineEdit,0,0);
       gLayout3->addLayout(hLayout,1,0,2,1);
       gLayout3->setSpacing(0);
       gLayout3->setContentsMargins(1,1,1,1);

       setLayout(gLayout3);

       for(int l=0;l<23;l++)
       {
           connect(buttons[l],SIGNAL(clicked()),this,SLOT(buttonsClicked()));
       }
       connect(buttons[13],SIGNAL(clicked()),lineEdit,SLOT(redo()));
       connect(buttons[14],SIGNAL(clicked()),lineEdit,SLOT(clear()));


       //connect(buttons[0],SIGNAL(clicked()),lineEdit,SLOT(setText(QString)));








}

void Widget::buttonsClicked()
{

    QString str;
    str=lineEdit->text();
    str.append(((QPushButton *)sender())->text());
    lineEdit->setText(str);



}



Widget::~Widget()
{

}
