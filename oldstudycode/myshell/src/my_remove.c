#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <malloc.h>
void rm_dir(char *argv)
{
	DIR *dp;
	
	if((dp=opendir(argv))==NULL)
	{
		fprintf(stderr,"opendir: %s\n",strerror(errno));
		exit(1);
	}
	struct dirent *dir;
	chdir(argv);
	while((dir=readdir(dp))!=NULL)
	{
		if(!strcmp(dir->d_name,".")||!strcmp(dir->d_name,".."))
		{
			continue;
		}
	    struct stat st;
	    lstat(dir->d_name,&st);
		if(S_ISDIR(st.st_mode))
		{
			rm_dir(dir->d_name);
		}else
		{
			remove(dir->d_name);
			char buffer[256];
			realpath(dir->d_name,buffer);
			printf("%s is delete!\n",buffer);
		}

	}
	
	chdir("..");
	remove(argv);
	char buf[256];
	realpath(argv,buf);
	printf("%s is delete!\n",buf);

}
int main(int argc ,char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage rm [cmd] [filename]");
		exit(1);
	}
	if(argc == 3)
	{
		if(strcmp(argv[1],"-R"))
		{
			printf("unknow comad\n");
			exit(1);
		}else
		{
			rm_dir(argv[2]);
		}
	}else
	{
		if(remove(argv[1])<0)
		{
			fprintf(stderr,"remove: %s\n",strerror(errno));
			exit(1);
		}
	}
	
}
