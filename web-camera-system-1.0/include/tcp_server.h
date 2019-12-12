/*
 * Author: liuwei
 * Date: 2013.10.11
 * tcp服务器头文件
 */
#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_
#define CONNECT_NUM 1024
#define PORT_NUM 10000
int sockfd;
int clientfd[CONNECT_NUM];
int clientid;
int c_id;

void *tcp_server();
//初始化服务器
extern void init();



#endif
