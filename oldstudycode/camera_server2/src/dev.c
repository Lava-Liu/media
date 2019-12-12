/*
 * Author: liuwei
 * Date: 2013.10.11
 * 摄像头驱动模块源文件
 */

#include "dev.h"
#include "tcp_server.h"
#include <linux/videodev2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>
/*int camera_fd;//摄像头文件描述符号

  typedef struct {
  unsigned char driver[16];设备名
  unsigned char card[32];显卡信息
  unsigned char bus_info[32];总线信息
  unsigned int version;版本

  unsigned int height; 默认图片高度
  unsigned int width;  默认图片宽度
  }Dev_info;
  Dev_info dev;*/

//获取摄像头的相关信息
//camerafd = open("dev/vide0",O_ERDWR,0);
void *g_th(void *arg)
{
	printf("get picture start!\n");
	get_picture_th();
}
void get_dev_info()
{	struct v4l2_capability cap;
	memset(&cap,0,sizeof(cap));
	if(ioctl(camera_fd,VIDIOC_QUERYCAP,&cap)<0)
	{
		fprintf(stderr,"ioctl:  %s\n",strerror(errno));
		exit(1);
	}
	strcpy(dev.driver,cap.driver);
	strcpy(dev.card,cap.card);
	strcpy(dev.bus_info,cap.bus_info);
	dev.version=cap.version;

	struct v4l2_format fmat;
	//无论是设置还是获取视频捕获格式，都需要设置以下两个参数
	memset(&fmat,0,sizeof(fmat));
	fmat.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmat.fmt.pix.field = V4L2_FIELD_ANY;
	if(ioctl(camera_fd,VIDIOC_G_FMT,&fmat)<0)
	{
		fprintf(stderr,"ioctl2: %s\n",strerror(errno));
		exit(1);
	}
	dev.height=fmat.fmt.pix.height;
	dev.width=fmat.fmt.pix.width;
}

//打印摄像头的相关信息
void out_dev_info()
{
	printf(">>>>>>>>>>>dev_info<<<<<<<<<<<<\n");
	printf("** driver: %s\n",dev.driver);
	printf("** card: %s\n",dev.card);
	printf("** bus_info: %s\n",dev.bus_info);
	printf("** version: %d\n",dev.version);
	printf("** width: %d\n",dev.width);
	printf("** weight: %d\n",dev.height);
	printf(">>>>>>>>>>>>>><<<<<<<<<<<<<<<<<\n");
}


//设置视频捕获格式
//设置格式注意将图片文件设置成MJPEG
//这一步主要是通过v4l2结构体对文件格式进行设置
//VIDIOC_S_FMT
void set_format()
{
	struct v4l2_format fmt;
	memset(&fmt,0,sizeof(fmt));
	fmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.width=640;
	fmt.fmt.pix.height=480;
	fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
	fmt.fmt.pix.field=V4L2_FIELD_ANY;
	if(ioctl(camera_fd,VIDIOC_S_FMT,&fmt)<0)
	{
		fprintf(stderr,"ioctl: %s\n",strerror(errno));
		exit(1);
	}



}

//设置帧率
//设置帧率这一步主要通过v4l2_streamparm 结构体
//并通过VIDIOC_SET_PARM
void set_parm()
{
	struct v4l2_streamparm parm;
	memset(&parm,0,sizeof(parm));
	parm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	parm.parm.capture.timeperframe.numerator =1;
	parm.parm.capture.timeperframe.denominator =FPS;
	if(ioctl(camera_fd,VIDIOC_S_PARM,&parm)<0)
	{
		fprintf(stderr,"set fp error:%s\n",strerror(errno));
		exit(1);
	}

}
//分配内存
//通过requestbuffers 申请缓存空间
//注意要设置缓存块的数量，并通过宏定义获得应为下面的映射操作需要用到
//VIDIOC_REQBUFS;
void req_buf()
{
	struct v4l2_requestbuffers req;
	memset(&req,0,sizeof(req));
	req.count=COUNT_NUM;
	req.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	req.memory=V4L2_MEMORY_MMAP;
	if(ioctl(camera_fd,VIDIOC_REQBUFS,&req)<0)
	{
		fprintf(stderr,"ioctl3: %s\n",strerror(errno));
		exit(1);
	}
}

//获取物理地址并映射到用户空间
//这一步最重要的是利用videobuffer 结构体保存申请到的地址的首地址和长度
//VIDIOC_QUERYBUF
//获取完地址之后要将获取的地址放入队列中
//VIDIOC_QBUF
void query_buf_mmap()
{

	buffers = (videobuffer *)calloc(COUNT_NUM,sizeof(*buffers));
	struct v4l2_buffer buf;
	int numbufs;
	for(numbufs=0;numbufs<COUNT_NUM;numbufs++)
	{
		memset(&buf,0,sizeof(buf));
		buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index=numbufs;
		if(ioctl(camera_fd,VIDIOC_QUERYBUF,&buf)<0)
		{
			fprintf(stderr,"ioctl4: %s\n",strerror(errno));
			exit(1);
		}
		buffers[numbufs].length = buf.length;
		buffers[numbufs].start = mmap(NULL,buf.length,PROT_READ|PROT_WRITE,MAP_SHARED,camera_fd,buf.m.offset);
		if(buffers[numbufs].start == MAP_FAILED)
		{
			fprintf(stderr,"mmap: %s\n",strerror(errno));
			exit(1);
		}
		if(ioctl(camera_fd,VIDIOC_QBUF,&buf)<0)
		{
			fprintf(stderr,"ioctlL %s\n",strerror(errno));
			exit(1);
		}

	}

}
//开始视频采集
void dev_on()
{
	enum v4l2_buf_type type;
	type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if(ioctl(camera_fd,VIDIOC_STREAMON,&type)<0)
	{
		fprintf(stderr,"ioctl: %s\n",strerror(errno));
		exit(1);
	}
	pthrad_t get_th;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	if(pthread_create(&get_th,&attr,g_th,NULL)!=0)
	{
		fprintf(stderr,"th_create: %s\n",strerror(errno));
		exit(1);
	}
}
void get_picture()
{

	struct v4l2_buffer buf;
	memset(&buf,0,sizeof(buf));
	buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory=V4L2_MEMORY_MMAP;
	buf.index=0;
	int i;
	for(i=0;i<3;i++)
	{
		if(ioctl(camera_fd,VIDIOC_DQBUF,&buf)<0)
		{
			fprintf(stderr,"ioctl: %s\n",strerror(errno));
			exit(1);
		}

		if(i == 0)
		{
			int fd=open("c.jpg",O_CREAT|O_RDWR|O_TRUNC,0777);
			if(fd < 0)
			{
				fprintf(stderr,"opem: %s\n",strerror(errno));
				exit(1);
			}
			print_picture(fd,buffers->start,buffers->length);
			close(fd);
		}

		if(i == 1)
		{
			int fd2=open("f.jpg",O_CREAT|O_RDWR|O_TRUNC,0777);
			if(fd2 < 0)
			{
				fprintf(stderr,"opem: %s\n",strerror(errno));
				exit(1);
			}
			print_picture(fd2,buffers->start,buffers->length);
			close(fd2);
		}


		if(i == 2)
		{
			int fd3=open("e.jpg",O_CREAT|O_RDWR|O_TRUNC,0777);
			if(fd3 < 0)
			{
				fprintf(stderr,"opem: %s\n",strerror(errno));
				exit(1);
			}
			print_picture(fd3,buffers->start,buffers->length);
			close(fd3);
		}

		/*ssize_t nread;
		  char buffer[4096]={0};
		  while((nread=read(fd,buffer,sizeof(buffer)))!=0)
		  {
		  write(clientfd,buffer,nread);
		  }*/
		if(ioctl(camera_fd,VIDIOC_QBUF,&buf)<0)
		{
			fprintf(stderr,"ioctl: %s\n",strerror(errno));
			exit(1);
		}
	}





	/*close(fd);
	  close(fd2);
	  close(fd3);*/





}
void get_picture_th()
{
	struct v4l2_buffer buf;
	int i;
	temp_buf=(unsigned char *)calloc(1,640*480*2);
	memset(&buf,0,sizeof(buf));
	buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory=V4L2_MEMORY_MMAP;
	while(1)
	{
	
		if(ioctl(camera_fd,VIDIOC_DQBUF,&buf)<0)
		{
			fprintf(stderr,"ioctl1: %s\n",strerror(errno));
			pthread_exit(NULL);
		}
	    i=buf.index;

		memcpy(temp_buf,buffers[i].start,buffers[i].length);
		temp_len=buffers[i].length;
		if(ioctl(camera_fd,VIDIOC_QBUF,&buf)<0)
		{
			fprintf(stderr,"ioctl2: %s\n",strerror(errno));
			pthread_exit(1);
		}
	}

}
void send_picture_th()
{
	char *http = "HTTP/1.0 200 OK\r\nConnection: close\r\nServer: Net-camera-1-0\r\nCache-Control: no-store, no-cache, must-revalidate, pre-check=0, post-check=0, max-age=0\r\nPragma: no-cache\r\nContent-type: multipart/x-mixed-replace;boundary=www.briup.com\r\n\r\n";
	int len=strlen(http);	
	if(write(clientfd,http,len)!=len)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		pthread_exit(1);
	}
	while(1)
	{

		char frame[4096]={0};
		sprintf(frame,"--www.briup.com\nContent-type: image/jpeg\nContent-Length: %d\n\n",temp_len+432);
		int len=strlen(frame);	
		if(write(clientfd,frame,len)!=len)
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			pthread_exit(1);
		}
		if(print_picture(clientfd,temp_buf,temp_len)<0)
		{
			fprintf(stderr,"eeror!\n");
			pthread_exit(1);
		}


	}

}
void send_picture()
{
	char *http = "HTTP/1.0 200 OK\r\nConnection: close\r\nServer: Net-camera-1-0\r\nCache-Control: no-store, no-cache, must-revalidate, pre-check=0, post-check=0, max-age=0\r\nPragma: no-cache\r\nContent-type: multipart/x-mixed-replace;boundary=www.briup.com\r\n\r\n";
	int len=strlen(http);	
	if(write(clientfd,http,len)!=len)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		pthread_exit(1);
	}

	struct v4l2_buffer buf;
	memset(&buf,0,sizeof(buf));
	buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory=V4L2_MEMORY_MMAP;
	buf.index=0;
	while(1)
	{
		if(ioctl(camera_fd,VIDIOC_DQBUF,&buf)<0)
		{
			fprintf(stderr,"ioctl: %s\n",strerror(errno));
			pthread_exit(1);
		}

		char frame[4096]={0};
		sprintf(frame,"--www.briup.com\nContent-type: image/jpeg\nContent-Length: %d\n\n",buffers->length+432);
		int len=strlen(frame);	
		if(write(clientfd,frame,len)!=len)
		{
			fprintf(stderr,"write: %s\n",strerror(errno));
			pthread_exit(1);
		}
		print_picture(clientfd,buffers->start,buffers->length);


		if(ioctl(camera_fd,VIDIOC_QBUF,&buf)<0)
		{
			fprintf(stderr,"ioctl: %s\n",strerror(errno));
			pthread_exit(1);
		}
	}
	close(clientfd);

}
void dev_off()
{
	enum v4l2_buf_type type;
	type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if(ioctl(camera_fd,VIDIOC_STREAMOFF,&type)<0)
	{
		fprintf(stderr,"ioctl: %s\n",strerror(errno));
		exit(1);
	}

}



