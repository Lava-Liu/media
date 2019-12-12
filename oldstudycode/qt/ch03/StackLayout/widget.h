#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QSlider>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QTextEdit *textEdit1;
    QTextEdit *textEdit2;
    QTextEdit *textEdit3;

    QSlider *slider;



};

#endif // WIDGET_H
