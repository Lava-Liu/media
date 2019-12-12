/* ==================================================================
 *       Filename:  test.c
 *    Description:  
 *        Created:  2013年10月23日 10时03分12秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "myled.h"

int main(int argc , char *argv[])
{
	if(argc < 0)
	{
		fprintf(stderr, "Usage:%s [filepath] : %s\n", argv[0], strerror(errno));
		exit(1);
	}
	int fd = open(argv[1], O_WRONLY);
	if(fd < 0)
	{
		fprintf(stderr, "open: %s\n", strerror(errno));
		exit(1);
	}
	int i = 0;
	while(1)
	{
		i++;
		ioctl(fd, LED_ON, 0);
		ioctl(fd, LED_ON, 1);
		ioctl(fd, LED_ON, 2);
		ioctl(fd, LED_ON, 3);
		sleep(1);
		ioctl(fd, LED_OFF, 0);
		ioctl(fd, LED_OFF, 1);
		ioctl(fd, LED_OFF, 2);
		ioctl(fd, LED_OFF, 3);
		sleep(1);
		if(i  > 50)
		{
            break;
		}
	}
	close(fd);
	return 0;
}
