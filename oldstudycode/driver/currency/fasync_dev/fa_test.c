/* ==================================================================
 *       Filename:  fa_test.c
 *    Description:  
 *        Created:  2013年10月24日 14时52分47秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

int devfd = -1;
/* ===  FUNCTION  ==================================================
 *         Name:  main
 *  Description:  
 * =================================================================*/
char buffer[100];
void sig_handler(int signo)
{
	if(signo == SIGIO)
	{
		printf("get SIGIO signal\n");
		memset(buffer, 0 , sizeof(buffer));
		read(devfd, buffer, sizeof(buffer));
		printf("read: %s\n", buffer);
	}
}
int main(int argc, char *argv[])
{
	
	if(argc<2)
	{
		fprintf(stderr, "%s [fileoperations]: %s\n", argv[0], strerror(errno));
		exit(1);
	}
	//1注册异步IO信号
	if(signal(SIGIO, sig_handler)==SIG_ERR)
	{
		fprintf(stderr, "signal: %s\n", strerror(errno));
		exit(1);
	}
	//2打开设备
	devfd=open(argv[1], O_RDWR);
	if(devfd < 0)
	{
		fprintf(stderr, "Open: %s\n", strerror(errno));
		exit(1);
	}
	//0设置当前进程为设备的拥有者
	fcntl(devfd, F_SETOWN, getpid());
	//4.添加异步支持标志FASYNC
	int oldflags=0;
	oldflags=fcntl(devfd, F_GETFL, oldflags);
	oldflags|=FASYNC;
	fcntl(devfd, F_SETFL, oldflags);
	//5使用while循环保证进程不退出
	int i = 1;
		printf("ready to accept device signal .. \n");
	while(i > 0)
	{
		printf("time %d seconds after ...\n", i++);
		sleep(1);
	}
		
		return EXIT_SUCCESS;
}/* end of function main */
