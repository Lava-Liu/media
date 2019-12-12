#include "widget.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent),sec(0),min(0),hor(0),gamer(true),myX(-1),myY(-1),tmpX(-1),tmpY(-1),curPlayer(true),chessNum(30)
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    //设置初始边框大小
    resize(800,600);

    //创建Browser组件
    textBrowser = new QTextBrowser(this);
    textBrowser->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);//设置布局策略为Ignore
    textEdit    = new MyTextEdit;//创建textEdit组件
    textEdit->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    //创建listWidget组件
    listWidget  = new QListWidget(this);
    listWidget->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    listWidget->addItem("4-Chess-rule");//添加标签
    listWidget->addItem("5-Chess-rule");
    listWidget->addItem("6-Chess-rule");
    listWidget->addItem("7-Chess-rule");


    startBtn    = new QPushButton("StartGame",this);//创建Start按钮
    startBtn->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    QHBoxLayout *hLayout  = new QHBoxLayout;//创建水平布局
    hLayout->addWidget(listWidget);
    hLayout->addWidget(startBtn);

    timeLabel = new  QLabel(this);//创建计时器组件
    timeLabel->setFont(QFont("",15,QFont::Black));
    timeLabel->setText("Timer: 00:00:00");
    timeLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    curPlayerLabel = new QLabel(this);//创建提示当前玩家组件
    curPlayerLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    curPlayerLabel->setFont(QFont("",20));
    curPlayerLabel->setText("Current Player:");

    pictureLabel   = new MyLabel;//创建显示当前玩家图片组件
    pictureLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    chessBoard = new MyPushButton(this);//创建棋盘
    chessBoard->setButtonEnable(false);
    chessBoard->getButtonClickSignal();


    QGridLayout  *gLayout = new QGridLayout(this);//创建网格布局策略
    gLayout->addWidget(textBrowser,0,0,3,1);
    gLayout->addWidget(textEdit,3,0,1,1);

    gLayout->addLayout(hLayout,4,0,1,1);
    gLayout->addWidget(timeLabel,5,0,1,1);
    gLayout->addWidget(curPlayerLabel,6,0,1,1);
    gLayout->addWidget(pictureLabel,7,0,3,1);
    gLayout->addWidget(chessBoard,0,1,10,3);

    setLayout(gLayout);//设置当前布局策略
    //连接文本输入框信号和brower处理槽
    connect(textEdit,SIGNAL(sengMessage(QString)),this,SLOT(textEditReturnPressed(QString)));

    //创建游戏计时器
    gamerTimer = new QTimer;
    //设置刷新时间为一秒
    gamerTimer->setInterval(1000);
    //接收游戏计时器发出的timeout信号，并传递给相关操函数进行处理
    connect(gamerTimer,SIGNAL(timeout()),this,SLOT(gmerTimerStart()));
    //连接startBtn按钮到star按钮处理槽函数上
    connect(startBtn,SIGNAL(clicked()),this,SLOT(startBtnClicked()));
    //开启服务器连接线程
    connetThread.start();
    //将服务器连接线程发回来的sendSockfd信号绑定到服务器连接处理槽函数上
    connect(&connetThread,SIGNAL(sendSockfd(int)),this,SLOT(clientConnectHandler(int)));
    //将棋盘发回来的sendButtonIndex信号绑定到棋盘落子信号处理函数上
    connect(chessBoard,SIGNAL(sendButtonIndex(QString)),this,SLOT(chessMessageHandler(QString)));
    //将棋盘发回来的sendErrorMessage信号绑定到棋盘错误信号处理函数上
    connect(chessBoard,SIGNAL(sendErrorMessage()),this,SLOT(chessErrorHandler()));
}

bool Widget::isWiner(int x,int y,bool chess,int counter)
{
    int i=x;
    int j=y;
    int cout =0;
    //竖直方向向上遍历，判断水平方向上的棋子的颜色，以及是否已经落子
    while(i>-1&&j>-1&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
    {
        i--;
        cout++;
        //qDebug() << "mingzhong!" << cout;
    }
    i=x+1;
    //竖直方向向下遍历
    while(i<30&&j<30&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
    {
        i++;
        cout++;
        //qDebug() << "mingzhong!" << cout;
    }
    //判断是否和规定的连子数目相同
    if(cout >= counter)
    {
        return true;
    }


    i=x;
    j=y;
    cout =0;
    //水平方向上的棋子遍历，左方向
    while(j>-1&&i>-1&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
    {
        j--;
        cout++;
        //qDebug() << "mingzhong!" << cout;
    }
    j=y+1;
    //水平方向上的棋子遍历，右方向
    while(j<30&&i<30&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
    {
        j++;
        cout++;
        //qDebug() << "mingzhong!" << cout;
    }

    if(cout>=counter)
    {
        return true;
    }



    i=x;
    j=y;
    cout =0;
    //左上方棋子遍历
    while(j>-1&&i>-1&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
    {
        j--;
        i--;
        cout++;
        qDebug() << "mingzhong!" << cout ;
    }

    j=y+1;
    i=x+1;
    //右下方棋子遍历
    while(j<30&&i<<30&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
    {
        j++;
        i++;
        cout++;
        qDebug() << "mingzhong!" << cout;
    }

    if(cout >= counter)
    {
        return true;
    }

//    i=x;
//    j=y;
//    cout =0;
//    while(1)
//    {
//        if(j<30&&j>-1&&i>-1&&i<30&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
//        {
//            i--;
//            j--;
//        }else
//        {
//            i+=1;
//            j+=1;
//            if(j<30&&j>-1&&i>-1&&i<30&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
//            {
//                i++;
//                j++;
//                cout++;
//                qDebug() <<  "mingzhong !" << cout;
//                if(cout>=counter)
//                {
//                    return true;
//                }

//            }else
//            {
//                break;

//            }

//        }



    i=x;
    j=y;
    cout =0;
    //左下方棋子遍历
    while(j>-1&&i<30&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
    {
        j--;
        i++;
        cout++;
       //qDebug() << "mingzhong!" << cout;
    }

    j=y+1;
    i=x-1;
    //右上方
    while(j<30&&i>-1&&chessBoard->buttons[i][j]->gamer==chess&&chessBoard->buttons[i][j]->live==true)
    {
        j++;
        i--;
        cout++;
        //qDebug() << "mingzhong!" << cout;
    }

    if(cout>=counter)
    {
        return true;
    }else
      return false;//如果没有满足条件则这次没有胜利，返回false






}



//错误操作处理槽函数
void Widget::chessErrorHandler()
{
    //当把棋子落在已经落下的棋子上时发出提醒
    QMessageBox::warning(this,"Warning","Here is already had a chess!",QMessageBox::Ok);
}



//游戏命令消息处理槽函数
void Widget::chessMessageHandler(QString str)
{
    //这里判断curPlayer 是否为真的目的是因为
    //如果不是当前玩家则没有权利操作棋盘
    if(curPlayer == true)
    {
       //这里将自己发送来的棋子坐标字符串转换成int类型
       int x=0;
       int y=0;
       QString ys=",";
       QString string=str;
       //通过indexOf获得','的位置，left不是从0开始而是从1开始
       x=string.left(string.indexOf(ys)).toInt();
       //indexOf找到的下标是从0开始的
       //remove是从0开始的，这一步表示将字符串包括‘，’以外的左边部分删除
       y=string.remove(0,string.indexOf(ys)+1).toInt();
       qDebug() << "x,y handler:"  << x << "," << y;

       myX=x;//保存自己传出的x，y坐标
       myY=y;
       //将棋盘内对应位置按钮的闪烁计时器打开
       chessBoard->buttons[x][y]->setTimer(true);
       if(gamer==false)
       {
         //如果自己作为非主机玩家，则将对应棋子位置的玩家归属设置为和自己一样
         //如果自己作为主机玩家，则不用设置，采用默认值即可
         chessBoard->buttons[x][y]->gamer=false;
       }


    //将要发出的棋子坐标命令加上<Command:>前缀
    int len=QString("<Command:>"+str).size();
    //qDebug() << str;
    //将坐标命令发送出去
    if(write(sockfd,QString("<Command:>"+str).toUtf8().data(),len)!=len)
    {
        qDebug() << "Send ChessIndex Wrong!";
    }
    //一但将坐标发送出去即认为我方操作完毕，将当前玩家状态设置为false
    curPlayer=false;

    //qDebug() << "Send Index:" << str;

      //如果当前玩家为非主机玩家则将图片标签中的玩家显示设置为主机玩家头像
     //并刷新一下确保图片能够显示
      if(gamer==false)
      {


          pictureLabel->curPlayer=true;
          pictureLabel->update();
      }
      //如果当前玩家为主机玩家则将图片标签中的玩家显示设置为非主机玩家的头像
      //刷新
      if(gamer==true)
      {
          pictureLabel->curPlayer=false;
          pictureLabel->update();
      }
      //如果上一次曾经接受过对方玩家发来的坐标信息，则将上一次的按钮闪烁计时器停止
      if(tmpX!=-1)
      {
        chessBoard->buttons[tmpX][tmpY]->setTimer(false);
     }
      //判断本次落子是否能够满足获胜条件，如果满足则弹出获胜提醒窗口
      if(isWiner(x,y,this->gamer,chessNum)==true)
      {
          if(QMessageBox::QMessageBox::information(this,"Gamer Over",
                                   "You win !",QMessageBox::Ok))
          {
              this->gamer=true;//重置原始玩家角色
              this->curPlayer=true;//重置当前玩家状态信息
              pictureLabel->curPlayer=true;//重置当前玩家标签状态
              pictureLabel->update();//刷新玩家状态标签
              gamerTimer->stop();//关闭游戏计时器
              sec=0;//将计时器因子重置
              min=0;
              hor=0;
              timeLabel->setText("Timer: 00:00:00");//重设计时器标签栏信息
              chessBoard->restoreButton();//恢复棋盘状态
              startBtn->setEnabled(true);//恢复开始按钮可用
              listWidget->setEnabled(true);//恢复规则选择框可用
          }
      }

    }else
    {
        //如果没有操作权限，则弹出提示框
        QMessageBox::information(this,"Gamer Help",
                                 "Now is not your turn Plese wait ",QMessageBox::Ok);
    }
}


//连接处理函数
void Widget::clientConnectHandler(int fd)
{
    qDebug() << "connetThread connect success!";
    sockfd=fd;//将获得的套结字描述符记录
    chatThread.sockfd=fd;//将套结字描述符传给信息接收线程
    chatThread.start();//开启信息接收线程
    //将聊天信息和命令信息分开绑定到相关的信息处理槽函数上
    connect(&chatThread,SIGNAL(sendChatMessage(QString)),this,SLOT(chatMessageHandler(QString)));
    connect(&chatThread,SIGNAL(sendCommandMessage(QString)),this,SLOT(commandMessageHandler(QString)));

}
//聊天信息处理函数
void Widget::chatMessageHandler(QString str)
{
    //如果是聊天信息则自动显示到聊天栏
    textBrowser->append("Others:"+str);

}
//命令处理函数
void Widget::commandMessageHandler(QString str)
{
    //判断是否为游戏请求命令
    if(str.contains("start"))
    {
      if(QMessageBox::Ok==QMessageBox::information(this,"Wow!","somebody ask you to play together!",QMessageBox::Ok,
                             QMessageBox::Cancel))
       {
          //如果选则接受游戏，即发送begin命令提示对方开始游戏
           char *buffer="<Command:>begin";
           char commd[20]={};
           strcpy(commd,buffer);
           int len=strlen(commd);
           if(write(sockfd,commd,len)!=len)
           {
               qDebug() << "Send begin command error!";
           }
           //开启本端游戏计时器，
           gamerTimer->start();
           chessBoard->setButtonEnable(true);//开放按钮区域
           listWidget->setEnabled(false);//禁用选择列表
           startBtn->setEnabled(false);//禁用开始按钮
           gamer=false;//将游戏身份设置为非客户端（接受方）
           curPlayer=false;//将先手权利让给对方

       }
   }
   if(str.contains("begin"))//游戏开启命令处理
    {
       //主机游戏计时器开启
        gamerTimer->start();
        chessBoard->setButtonEnable(true);//主机棋盘开启
        listWidget->setEnabled(false);//主机选择列表禁用
        startBtn->setEnabled(false);//主机开始按钮禁用
    }
   if(str.contains(","))//落子命令处理
   {
       //qDebug() << "receive str"<<str;
       if(myX != -1)
       {
           //如果本次不为首次落子操作则关闭上次我我方所下按钮闪烁效果
            chessBoard->buttons[myX][myY]->setTimer(false);
            //chessBoard->buttons[myX][myY]->counter=4;
       }
       if(tmpX!=-1)
       {
           //如果不为首次接收对方落子命令，则关闭上次对方落子按钮闪烁效果
         chessBoard->buttons[tmpX][tmpY]->setTimer(false);
      }
       //既然对方已经落子，则我方获得操作权利
       curPlayer = true;

       //将对方传来的棋子坐标进行处理
       int x=0;
       int y=0;
       QString ys=",";
       QString string=str;
       x=string.left(string.indexOf(ys)).toInt();
       y=string.remove(0,string.indexOf(ys)+1).toInt();
       //将对方所下的棋子位置保存起来，供下一次使用
       qDebug() << "receive Index:" << x << "," << y;
       tmpX=x;
       tmpY=y;
       chessBoard->buttons[x][y]->setTimer(true);//开启对方落子位置的闪烁效果
       //如果为非主机玩家则将棋子的拥有者设定为主机玩家并更新当前玩家图片显示标签为自己
       if(gamer==false)
       {
           chessBoard->buttons[x][y]->gamer=true;
           pictureLabel->curPlayer=false;
           pictureLabel->update();
       }
       //如果为主机玩家，则将棋子的拥有者设置为非主机玩家，并更新当前玩家图片显示为自己
       if(gamer==true)
       {
           chessBoard->buttons[x][y]->gamer=false;
           pictureLabel->curPlayer=true;
           pictureLabel->update();
       }
       if(isWiner(x,y,!this->gamer,chessNum)==true)//如果对方该次落子获得胜利，弹出失败提醒
       {
           //点击OK以后全部重置
           if(QMessageBox::Ok==QMessageBox::information(this,"Gamer Over",
                                    "game over!",QMessageBox::Ok))
           {
               this->gamer=true;
               this->curPlayer=true;
               pictureLabel->update();
               gamerTimer->stop();
               sec=0;
               min=0;
               hor=0;
               timeLabel->setText("Timer: 00:00:00");
               chessBoard->restoreButton();
               startBtn->setEnabled(true);
               listWidget->setEnabled(true);
           }
       }


   }
   if(str.contains("Num"))//游戏规则数字处理
   {
       str.remove(0,3);
       qDebug() << str;
       chessNum = str.toInt();//将获得的规则记录
       qDebug() << "!!!!!!!!!!!"<< chessNum;
   }

}


//sendMessage处理槽函数
void Widget::textEditReturnPressed(QString str)
{
    textBrowser->append("Me:"+str);
    //char *buffer=str.toUtf8().data();
    int len=strlen(str.toStdString().c_str());
    write(sockfd,str.toStdString().c_str(),len);

    textEdit->clear();//清空聊天栏
}

void Widget::startBtnClicked()
{
    //首先确定已经选择了对应的游戏规则标签
    if(listWidget->currentRow() != -1)
    {

    //qDebug() << listWidget->currentRow();
    char *buffer = "<Command:>start";
    char command[20]={};
    strcpy(command,buffer);
    int len=strlen(command);
    if(write(sockfd,command,len)!=len)
    {
        qDebug() << "Send game start ask error!";
    }
    //chessBoard->setButtonEnable(true);
    QString str;
    str.sprintf("<Command:>Num%d",listWidget->currentRow()+4);
    write(sockfd,str.toAscii().data(),str.size());

    chessNum=listWidget->currentRow()+4;
    qDebug() << chessNum;
    //qDebug() << str.toAscii().data();
    }else
    {
        QMessageBox::information(this,"Game Help","Please chose the rule first!",QMessageBox::Ok);
    }

}
//游戏计时器
void Widget::gmerTimerStart()
{
    sec++;
    if(sec==60)
    {
        sec=0;
        min++;
        if(min == 60)
        {
            min=0;
            hor++;
        }
    }
    QString str;
    str.sprintf("Timer: %02d:%02d:%02d",hor,min,sec);
    timeLabel->setText(str);

}


Widget::~Widget()
{

}
