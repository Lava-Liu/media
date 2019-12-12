#ifndef WIDGET_H
#define WIDGET_H
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>



#include <QtGui/QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel      *nameLable;
    QLabel      *pwdLable;
    QLineEdit   *lineEdit1;
    QLineEdit   *lineEdit2;


};

#endif // WIDGET_H
