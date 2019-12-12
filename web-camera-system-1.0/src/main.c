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
//通过获取外部参数选择要打开的设备文件
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
	//获取图像采集设备的信息
	get_dev_info();
	//打印图像采集设备的信息
	out_dev_info();
	//设置采集的格式
	set_format();
	//设置帧率
	set_parm();
	//请求队列
	req_buf();
	//进行内存映射
	query_buf_mmap();
	printf(">>>>>>>>>>>>>>>System init is finished!<<<<<<<<<<<<\n");
	//开始录像采集
	dev_on();
	//启动服务器
	init();
	return 0;
}
