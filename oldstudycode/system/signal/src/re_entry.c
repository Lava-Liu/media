#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#define BUFFER_LEN  256
//设计一个函数把字符串从小写转换大写
char *toUpperStr(char *); 
char *toUpperStr_r(char *,char *); 
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		char *str = "signal";
		char buffer[BUFFER_LEN];
	    printf("Upper_r: %s\n",toUpperStr_r(str,buffer));
		//printf("Upper: %s\n",toUpperStr(str));
	}
}
char *toUpperStr(char *str)
{
	int len;
	len=strlen(str);
	char *buffer = (char *)malloc(BUFFER_LEN);
	int i;
	for(i=0;i<len;i++)
	{
		buffer[i]=toupper(str[i]);
		sleep(1);
	}
	buffer[len]='\0';
	return buffer;
}
char *toUpperStr_r(char *str,char *newStr)
{
	int len=strlen(str);
	int i;
	for(i =0;i<len;i++)
	{
		newStr[i]=str[i];
		sleep(1);
	}
	newStr[len]='\0';
	return newStr;
}
int main(void)
{
	if(signal(SIGINT,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	char *str = "function";
    char buffer[BUFFER_LEN];
	printf("Upper_r: %s\n",toUpperStr_r(str,buffer));
	//printf("Upper: %s\n",toUpperStr(str));
	



	return 0;
}
