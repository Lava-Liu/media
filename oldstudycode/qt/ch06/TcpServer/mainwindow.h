#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QStackedLayout>
#include <QtNetwork/QTcpServer>
#include <QTcpSocket>
#include <QTextCodec>
#include <QTimer>



class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *listenBtn;
    QPushButton *stopBtn;
    QTextEdit   *infoPad;
    QStackedLayout *sLayout;

    QTimer     *serverTimer;

    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;

public slots:
    void listenBtnclicked();
    void stioBtnclicked();
    void newConnectionComing();

    void clientSocketDisconnect();

    void dataReceive();

};

#endif // MAINWINDOW_H
