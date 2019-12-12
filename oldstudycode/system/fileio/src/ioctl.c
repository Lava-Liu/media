#include <stdio.h>
#include <fcntl.h>
#include <linux/cdrom.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
	int fd = open("/dev/cdrom1",O_RDONLY|O_NONBLOCK);
	if(fd < 0)
	
	{
		fprintf(stderr,"open : %s\n",strerror(errno));
		exit(1);
	}
	if(ioctl(fd,CDROMEJECT)< 0)
	{
		fprintf(stderr,"ioctl : %s\n",strerror(errno));
		exit(1);
	}
	printf("cdrom reject!\n");
	return 0;
}
