#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>




class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);






};

#endif // WIDGET_H
