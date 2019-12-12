#ifndef DIALOG_H
#define DIALOG_H


#include <QtGui/QDialog>
#include <QPushButton>
#include <QLabel>



class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    QLabel       *label;

};

#endif // DIALOG_H
