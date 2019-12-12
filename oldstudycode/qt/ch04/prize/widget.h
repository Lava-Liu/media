#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <QTimer>
#include <QPalette>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QString getRand();
private:
    QSpinBox *spinBox1;
    QSpinBox *spinBox2;
    QSpinBox *spinBox3;

    QLabel   *label1;
    QLabel   *label2;
    QLabel   *label3;

    QPushButton *startBtn;
    QPushButton *stopBtn;
    QStackedLayout *sLayout;

    QTimer *timer;
    //QPalette *palette;

public slots:
    void startBtnClicked();
    void stopBtnClicked();
    void flushNum();







};

#endif // WIDGET_H
