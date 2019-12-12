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
void *g_th(void *arg)
{
	printf("picture get satrt!\n");
	//get_picture_th();
}
int main(int argc,char *argv[])
{

	if(argc <2)
	{
		fprintf(stderr,"usage: %s #dev\n",argv[0]);
		exit(1);
	}

	temp_buf=(unsigned char *)calloc(1,640*480*2);
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
	pthread_t th1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&th1,&attr,g_th,NULL);
	
	init();
	//printf("VIDEO get start!\n");
	//get_picture_th();
	
	//get_picture();
	
	//printf("send picture start!\n");
	//send_picture();

	//printf("send picture finished!\n");
	dev_off();
	printf("VIDEO get shutdown \n");


	close(camera_fd);
	return 0;
}
