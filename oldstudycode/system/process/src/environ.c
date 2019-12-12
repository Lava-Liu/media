#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[],char *envp[])
{
	//输出环境表内容
	//1、使用main函数参数
	int i;
	for(i=0;*(envp+i)!=NULL;i++)
	{
		printf("%d --> %s\n",i,*(envp+i));
	}
	//2、使用外部链接envion
	extern char**environ;
	char **env = environ;
	while(*env != NULL)
	{
		printf("%p     %s\n",env,*env++);
	}
	return 0;
	
}
