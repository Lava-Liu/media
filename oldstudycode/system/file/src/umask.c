#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
 
int main(void)
{
	int mask = umask(0);
	printf("mask: %d\n",mask);
	creat("a.txt",0777);
	mask = umask(S_IRGRP|S_IWGRP);
	printf("mask: %d\n",mask);
	creat("b.txt",0777);
	return 0;
}
