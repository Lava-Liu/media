#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(void )
{
	FILE *fp = popen("ls -l","r");
	int fd =fileno(fp);

	char buffer[256] = {0};
	ssize_t n_read =0;
	if((n_read=read(fd,buffer,256))<0)
	{
		fprintf(stderr,"read: %s\n",strerror(errno));
		exit(1);
	}
	printf("buffer: %s\n",buffer);
	pclose(fp);




	printf("-----------------------------------\n");

	fp = popen("wc -l","w");
	fd = fileno(fp);

	char *str = "1\n2\n3\n4\n5\n";
	int len=strlen(str);
	if(write(fd,str,len)!=len)
	{
		fprintf(stderr,"write: %s\n",strerror(errno));
		exit(1);
	}
	pclose(fp);

	return 0;
}
