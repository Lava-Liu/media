#ifndef PICUTREGET_H
#define PICUTREGET_H

#include <QThread>
#include <QImage>
#include <QtNetwork/QTcpSocket>


class PicutreGet : public QThread
{
    Q_OBJECT
public:
    PicutreGet();

protected:
    void run();

private:
    QImage  framImg;
    QTcpSocket *clientSocket;
signals:
    void sendPicture(QImage);

};

#endif // PICUTREGET_H
