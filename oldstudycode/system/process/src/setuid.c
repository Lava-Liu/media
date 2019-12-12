#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(void)
{
	printf("uid:%d,euid:%d\n",getuid(),geteuid());
	//1
	creat("1.txt",0600);
	if(setuid(1000) < 0)
	{
		fprintf(stderr,"setuid: %s\n",strerror(errno));
		exit(1);
	}

	printf("change UID\n");
	//2
	printf("uid:%d,euid:%d\n",getuid(),geteuid());



	return 0;
}
