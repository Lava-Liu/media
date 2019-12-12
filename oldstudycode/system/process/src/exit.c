#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
void fun1()
{
	printf("in fun1\n");
}
void fun2()
{
	printf("in fun2\n");
}

void fun3()
{

	printf("in fun3\n");
}
int main(void)
{
	printf("main function begin!\n");

	printf("message without flush io");
	//register
	sleep(5);
	if(atexit(fun1)<0)
	{
		fprintf(stderr,"atexit: %s\n",strerror(errno));
		exit(1);
	}
	if(atexit(fun2)<0)
	{
		fprintf(stderr,"atexit: %s\n",strerror(errno));
		exit(1);
	}
	if(atexit(fun3)<0)
	{
		fprintf(stderr,"atexit: %s\n",strerror(errno));
		exit(1);
	}
	exit(1);
	//清空缓冲区
	//调用atexit中注册的函数
	printf("main function end!");
	_exit(1);
	return 0;
}
