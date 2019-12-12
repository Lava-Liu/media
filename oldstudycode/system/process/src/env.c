#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main(void)
{
	//获取环境变量
	if(getenv("EMSD") == NULL)
	{
		fprintf(stderr,"EMSD not found!\n");
	}

	//设置环境变量
	if(putenv("EMSD")!=0)
	{
		fprintf(stderr,"putenv: %s\n",strerror(errno));
		exit(1);
	}
	//赋值环境变量
	if(setenv("EMSD","1303",1)!=0)
	{
		fprintf(stderr,"setenv: %s\n",strerror(errno));
		exit(1);
	}
	printf("ret: %s\n",getenv("EMSD"));
	//销毁环境变量
	/*if(unsetenv("EMSD")!=0)
	{
		fprintf(stderr,"unsetenv: %s\n",strerror(errno));
		exit(1);
	}
	if(getenv("EMSD")==NULL)
	{
		fprintf(stderr,"EMSD not found!\n");
	}*/

	return 0;
}
