#include "widget.h"
#include <QDebug>


  widget::widget(QWidget *parent)
    : QWidget(parent)
{

        QString str("this is a debug message!");
        qDebug()<<str;
      //改变大小
     resize(600,300);
      //setFixedSize(500,300);//固定大小
      //setFixedHeight(500);
      //setFixedWidth(500);
      button=new QPushButton(this);
      button->setText("Button");

      button->setGeometry(20,50,100,30);
      radioBtn = new QRadioButton(this);
      radioBtn->setText("RadioButton");
      radioBtn->setGeometry(20,90,120,30);

      checkBox = new QCheckBox(this);
      checkBox->setText("checkBox");
      checkBox->setGeometry(radioBtn->x(),radioBtn->y()+radioBtn->height()+10,radioBtn->width(),radioBtn->height());

       lineEdit = new QLineEdit(this);
       lineEdit->setGeometry(150,0,150,30);

        textEdit = new QTextEdit(this);
        textEdit->setGeometry(150,40,200,200);
        textEdit->setReadOnly(true);
        textEdit->append("append info");
        textEdit->setFont(QFont("Monospace",20,QFont::Bold,true));//调整字体  类型 字号 粗体 斜体


        comboBox = new QComboBox(this);
        comboBox->setGeometry(20,10,120,30);
        comboBox->addItem("item1");
        comboBox->addItem("item2");
        comboBox->addItem("item3");

        label = new QLabel(this);
        label->setText("<u>Message:</u>");
         label->setGeometry(360,50,200,200);

         QPalette palette;//调色板
         palette.setColor(QPalette::Window,Qt::green);
         palette.setColor(QPalette::WindowText,Qt::red);

          label->setPalette(palette);//设置着色器
          label->setAutoFillBackground(true);//自动填充背景色
          label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
          label->setPixmap(QPixmap(":/pic/4841807.png"));

        // : + 前缀 + 文件名





      connect(button,SIGNAL(clicked()),this,SLOT(close()));

}

widget::~widget()
{

}
