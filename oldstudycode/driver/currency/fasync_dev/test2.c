/* ==================================================================
 *       Filename:  test2.c
 *    Description:  
 *        Created:  2013年10月24日 10时59分14秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

/* ===  FUNCTION  ==================================================
 *         Name:  main
 *  Description:  
 * =================================================================*/
int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "use %s\n", argv[0]);
		exit(1);
	}
	int fd = open(argv[1], O_RDWR);
	if(fd < 0)
	{
		fprintf(stderr, "open:%s\n", strerror(errno));
		exit(1);
	}
	fd_set rset, wset;
	while(1)
	{
		//清空文件描述
		FD_ZERO(&rset);
		FD_ZERO(&wset);
		//将需要测试的文件描述符号添加到文件描述符集
		FD_SET(fd, &rset);
		FD_SET(fd, &wset);
		//轮询测试
		select(fd+1, &rset, &wset, NULL, NULL);
		//判断制定文件是否可用
		if(FD_ISSET(fd, &rset)){
			printf("device can be read !\n");
		}
		if(FD_ISSET(fd, &wset)){
			printf("device can be write !\n");
		}
		sleep(1);
	}
		return EXIT_SUCCESS;
}/* end of function main */
