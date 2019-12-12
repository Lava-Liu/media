#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QLineEdit>
#include <QStatusBar>
#include <QLabel>



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;
    QStatusBar *statusBar;
    QLabel    *nameLabel;

signals:
    void textNumChanged(int);


public slots:
    void updateMessage();
    void inputingState(QString);

};

#endif // WIDGET_H
