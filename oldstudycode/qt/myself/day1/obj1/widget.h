#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>//按钮
#include <QComboBox>//下拉列表
#include  <QCheckBox>// 复选
#include  <QRadioButton>//单选按钮
#include <QLabel>//标签
#include  <QLineEdit>
#include <QTextEdit>

class Widget : public QWidget
{
    Q_OBJECT  //SIGNAL,SLOT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton  *button;
    QComboBox    *comboBox;
    QCheckBox    *checkBox;
    QRadioButton *radioButton;
    QLabel       *label;
    QLineEdit    *lineEdit;
    QTextEdit    *textEdit;

};

#endif // WIDGET_H
