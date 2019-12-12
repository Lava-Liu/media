#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#define BUF_LEN 1024
char *toupstr_r(char *str,char *buffer);
char *toupstr(char *str)
{
	int len;
	len = strlen(str);
	int i;
	static char buffer[BUF_LEN];
	strcpy(buffer,str);
	for(i=0;i<len;i++)
	{
		buffer[i]=toupper(buffer[i]);
		sleep(1);

	}
	buffer[i]='\0';
	return buffer;
}
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("sigint is receive !\n");
		char *str ="signal";
		char buffer[BUF_LEN]={};
		printf("str3: %s\n",toupstr_r(str,buffer));
	}
	
}
char *toupstr_r(char *str,char *buffer)
{
	int len;
	len =strlen(str);
	int i;
	for(i = 0;i < len;i++)
	{
		buffer[i]=toupper(str[i]);
		sleep(1);
	}
	buffer[i] = '\0';
	return buffer;
}
int main(void)
{
	char buffer[BUF_LEN]={};
	if(signal(SIGINT,sig_handler)==SIG_ERR)
	{
		fprintf(stderr,"signal: %s\n",strerror(errno));
		exit(1);
	}
	char *str = "helloworld";

	printf("Str: %s\n",toupstr_r(str,buffer));

	char *str2 ="function";

	printf("Str2: %s\n",toupstr_r(str2,buffer));


	return 0;
}
