/* ==================================================================
 *       Filename:  test.c
 *    Description:  
 *        Created:  2013年10月18日 14时51分31秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if(argc <2)
	{
		fprintf(stderr, "Usage %s [filepath] : %s\n", argv[0], strerror(errno));
		exit(1);
	}
	int fd = open(argv[1], O_RDWR|O_NONBLOCK);
	if(fd < 0)
	{
		fprintf(stderr, "open: %s\n", strerror(errno));
		exit(1);
	}
	printf("Open device %s successful!\n", argv[1]);
	printf("waiting for close!\n");
	int i;
	for(i=10;i>0;i--)
	{
		printf("%d seconds left ..\n", i);
		sleep(1);
	}
	char buffer[4]={0};
	read(fd, buffer, sizeof(buffer));
	printf("read:%s\n", buffer);
	read(fd, buffer, sizeof(buffer));
	printf("read:%s\n", buffer);
	
	close(fd);
	printf("close %s successful!\n", argv[1]);
	return 0;
}
