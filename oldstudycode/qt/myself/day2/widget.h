#ifndef WIDGET_H
#define WIDGET_H
#include <QPushButton>
#include <QLineEdit>




#include <QtGui/QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton *buttons[23];
    QLineEdit   *lineEdit;

public slots:
    void buttonsClicked();




};

#endif // WIDGET_H
