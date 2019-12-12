#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget *parent = 0);


protected:
    void keyPressEvent(QKeyEvent *);


signals:
    void sengMessage(QString);
public slots:

};

#endif // MYTEXTEDIT_H
