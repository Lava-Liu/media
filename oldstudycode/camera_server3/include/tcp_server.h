/*
 * Author: liuwei
 * Date: 2013.10.11
 * tcp服务器头文件
 */
#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_

int sockfd;
int clientfd;

void *tcp_server();
//初始化服务器
extern void init();



#endif
