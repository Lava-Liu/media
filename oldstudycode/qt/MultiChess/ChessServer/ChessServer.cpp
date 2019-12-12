//#include "ChessServer.h"
#include "command.h"
#include "fd_vector.h"
#include <QDebug>
int sockfd;
Fd_Vector *clinetBox;

void *clientHandler(void *arg)
{
    //Fd_Vector *v = (Fd_Vector *)arg;

    int cfd = (int )arg;
    char buffer[1024];
    int i=0;
    int flag;

    while(1)
    {
        memset(buffer,0,sizeof(buffer));
        if(read(cfd,buffer,sizeof(buffer))<=0)
        {
            qDebug() << "fd  delete success!";
            delete_fd_v(clinetBox,cfd);
            pthread_exit(NULL);
        }
        flag=get_fd_index(clinetBox,cfd);

        for(i=0;i<clinetBox->count;i++)
        {
           if(i==flag)
           {
               continue;
           }
           write(clinetBox->fds[i],buffer,strlen(buffer));
        }
    }


}

int main(int argc,char*argv[])
{

    clinetBox = create_fd_v();



    //获得一个套结字，AF_INET 采用IPV4，sock_stream表示使用TCP方式
   sockfd = socket(AF_INET,SOCK_STREAM,0);
   if(sockfd<0)
   {
       fprintf(stderr,"sockfd:%s\n",strerror(errno));
       exit(0);
   }
   //填写地址结构结构体（IF_INET类型）
   struct sockaddr_in sock_addr;
   memset(&sock_addr,0,sizeof(sock_addr));
   sock_addr.sin_family = AF_INET;
   sock_addr.sin_port = htons(10000);//将端口字节序进程转换
   sock_addr.sin_addr.s_addr = INADDR_ANY;//表示接受任何地址

  //设置端口可重用
   int on=1;
   setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

   //绑定
   bind(sockfd,(sockaddr *)&sock_addr,sizeof(sock_addr));

  //监听
   listen(sockfd,50);

   //clientCounter=0;
   pthread_t th;
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);


   struct sockaddr_in client_addr;
   unsigned int len=sizeof(client_addr);
   int clientfd;
   //接收
   while(1)
   {

      qDebug() << "accept Start!";
      qDebug() <<  clinetBox->count;
      clientfd=accept(sockfd,(sockaddr *)&sock_addr,&len);
      add_fd_v(clinetBox,clientfd);
      pthread_create(&th,&attr,clientHandler,(void *)clientfd);

  }

    return 0;
}



