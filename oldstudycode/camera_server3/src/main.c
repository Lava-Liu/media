/*
 * Author: liuwei
 * Date: 2013.10.11
 * 采集系统源文件
 */
#include "dev.h"
#include "tcp_server.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>
int main(int argc,char *argv[])
{
	if(argc <2)
	{
		fprintf(stderr,"usage: %s #dev\n",argv[0]);
		exit(1);
	}
	camera_fd = open(argv[1],O_RDWR);
	if(camera_fd<0)
	{
		fprintf(stderr,"open: %s\n",strerror(errno));
		exit(1);
	}
	get_dev_info();
	out_dev_info();
	set_format();
	set_parm();
	req_buf();
	query_buf_mmap();
	printf("System init is finished!\n");
	dev_on();
	init();
	dev_off();
	printf("VIDEO get shutdown \n");
	close(camera_fd);
	return 0;
}
