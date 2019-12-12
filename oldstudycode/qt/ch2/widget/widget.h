#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton> //按钮
#include <QCheckBox>    //复选按钮
#include <QRadioButton>//单选按钮
#include  <QComboBox> // 下拉列表
#include <QLineEdit>//单行文本框
#include <QLabel>//标签
#include <QTextEdit>//多行文本框


class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = 0);
    ~widget();

private:
   QPushButton *button;
   QRadioButton *radioBtn;
   QCheckBox    *checkBox;
   QLineEdit       *lineEdit;
   QTextEdit       *textEdit;
   QLabel              *label;
   QComboBox  *comboBox;
};

#endif // WIDGET_H
