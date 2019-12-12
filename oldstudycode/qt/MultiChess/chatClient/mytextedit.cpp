#include "mytextedit.h"
#include <QKeyEvent>


MyTextEdit::MyTextEdit(QWidget *parent)

{
}

void MyTextEdit::keyPressEvent(QKeyEvent *event)
{

    if((event->key() == Qt::Key_Return))
    {
        emit sengMessage(this->toPlainText());
    }else
        QTextEdit::keyPressEvent(event);


}
