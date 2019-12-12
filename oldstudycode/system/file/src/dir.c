#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
int main(int argc ,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"%s [dirname]\n",argv[0]);
		exit(1);
	}
	DIR *dp = opendir(argv[1]);
	if(dp == NULL)
	{
		fprintf(stderr,"opendir: %s\n",strerror(errno));
		exit(1);
	}
	struct dirent *dtp = NULL;
	while((dtp =readdir(dp))!=NULL)
	{
		printf("%ld:%s\n",dtp->d_ino,dtp->d_name);
	}
	if(closedir(dp)<0)
	{
		fprintf(stderr,"closedir: %s\n",strerror(errno));
		exit(1);

	}
	return 0;
}
