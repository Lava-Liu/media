#include "widget.h"
#include <QDebug>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QString str("my heatr is go on!");
    qDebug() << str;

        resize(500,500);//设置大小可拉伸
        //setFixedSize(500,500);//设置固定大小
        //setFixedHeight(500); //设置固定高度
        //setFixedWidth(500);    //设置固定宽Q
    button = new QPushButton(this);
    button->setText("Button");
    button->setGeometry(20,10,120,30);

    checkBox= new QCheckBox(this);
    checkBox->setText("checkBox");
    checkBox->setGeometry(20,50,120,30);

    radioButton = new QRadioButton(this);
    radioButton->setText("readiobutton");
    radioButton->setGeometry(checkBox->x(),checkBox->y()+checkBox->height()+10,checkBox->width(),checkBox->height());

    comboBox = new QComboBox(this);
    comboBox->addItem("item1");
    comboBox->addItem("item2");
    comboBox->setGeometry(20,radioButton->y()+radioButton->height()+10,120,30);

    QPalette palette;
    palette.setColor(QPalette::HighlightedText,Qt::red);
    palette.setColor(QPalette::Highlight,Qt::yellow);
    palette.setColor(QPalette::Window,Qt::yellow);
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(comboBox->x()+comboBox->width()+20,10,200,30);
    lineEdit->setPalette(palette);
    //lineEdit->setAutoFillBackground(true);
    lineEdit->setReadOnly(true);

    textEdit = new QTextEdit(this);
    textEdit->setGeometry(lineEdit->x(),50,200,200);
    textEdit->setFont(QFont("monospace",16,5));

    label = new QLabel(this);
    label->setText("label");
    label->setGeometry(20,radioButton->y()+radioButton->height()+130,200,200);
    label->setPalette(palette);
    //label->setAutoFillBackground(true);
    label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    label->setPixmap(QPixmap(":/pic/4841807.png"));


    connect(button,SIGNAL(clicked()),this,SLOT(close()));









}

Widget::~Widget()
{

}
