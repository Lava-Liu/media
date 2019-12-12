/* ==================================================================
 *       Filename:  fasync.c
 *    Description:  
 *        Created:  2013年10月24日 13时46分45秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
char buffer[1024];
void sig_handler(int signo)
{
	if(signo == SIGIO)
	{
		printf("get SIGIO signal!\n");
		memset(buffer, 0, sizeof(buffer));
		read(STDIN_FILENO, buffer, sizeof(buffer));
		printf("ready data : %s\n", buffer);
	}
}
int main(int argc , char *argv[])
{
	//3\注册信号
	if(signal(SIGIO, sig_handler)==SIG_ERR)
	{
		fprintf(stderr, "signal: %s\n", strerror(errno));
		exit(1);
	}
	//1.制定当前进程为标准输入设备的拥有者
	fcntl(STDIN_FILENO, F_SETOWN, getpid());
	//2.让标准输入支持异步io
	int oldflags = 0;
	fcntl(STDIN_FILENO, F_GETFL, oldflags);
	int newflags=oldflags|FASYNC;
	fcntl(STDIN_FILENO, F_SETFL, newflags);
	
	//使用循环让进程保持并不退出状态
	printf("ready to accept fasync signal .....\n");
	while(1)
		sleep(1);
	return 0;
}
