#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	if(system("cat /etc/passwd | grep root")< 0)
	{
		fprintf(stderr,"system: %s\n",strerror(errno));
		exit(1);
	}
	printf("system success!\n");
	char *envp[]=
	{
		"EMSD=1303",
		"VAR=100",
		NULL
	};
	char *argv[]=
	{
		"aaa",
		"bbb",
		"ccc",
		NULL
	};
	//if(execl("./a1.out","aaa","bbb","ccc",NULL)<0)
	//if(execle("./a1.out","aaa","bbb","ccc",NULL,envp)<0)
	if(execv("./a1.out",argv)<0)
	{
		fprintf(stderr,"exec: %s\n",strerror(errno));
		exit(1);

	}
	printf("exec success!\n");
	return 0;
}
