#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"Usage rename [filename] [newfilename]\n");
		exit(1);
	}
	struct stat st;
	lstat(argv[2],&st);
	if(S_ISDIR(st.st_mode))
	{
		char buffer[256];
		strcpy(buffer,argv[2]);
		strcat(buffer,argv[1]);
		if(rename(argv[1],buffer)<0)
		{
			fprintf(stderr,"reanme: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(rename(argv[1],argv[2])<0)
	{
		fprintf(stderr,"reanme: %s\n",strerror(errno));
		exit(1);
	}
	return 0;
}
