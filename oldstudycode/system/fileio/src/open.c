#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>//strerror 错误分析函数
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"-Usage: %s [filename]\n",argv[0]);
		exit(1);
	}

	int fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		fprintf(stderr,"open failed:%s\n",strerror(errno));
		exit(1);
	}
	printf("%d\n",fd);
	close(fd);
	return 0;
}
