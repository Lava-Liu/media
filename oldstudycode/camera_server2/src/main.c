#include "dev.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
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
	
	printf("VIDEO get start!\n");
	
	init();
	//get_picture();
	
	printf("send picture start!\n");
	//send_picture_th();
	//send_picture();

	printf("send picture finished!\n");
	dev_off();
	printf("VIDEO get shutdown \n");


	close(camera_fd);
	return 0;
}
