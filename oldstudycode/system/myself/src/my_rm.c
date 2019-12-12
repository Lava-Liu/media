#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>


void my_rm(char *pathname,char *path)
{
	char path_name[1024];
	realpath(pathname,path_name);
	chdir(path_name);
	realpath(path,path_name);
	printf("%s\n",path_name);
	struct stat st;
	lstat(path_name,&st);
	if(S_ISDIR(st.st_mode))
	{
	    chdir(path_name);
		DIR *dir;
		struct dirent *dire;
		dir = opendir(path_name);
		while((dire = readdir(dir))!=NULL)
		{
			if(!strcmp(dire->d_name,".")||!strcmp(dire->d_name,".."))
				continue;
			struct stat sta;
			stat(dire->d_name,&sta);
			if(S_ISDIR(sta.st_mode))
			{
				realpath(dire->d_name,path_name);
				my_rm(path,path_name);
			}else
			{
				remove(dire->d_name);
				printf("%sdelete!\n",dire->d_name);
			}
		}


		remove(path_name);
		printf("%sdelete!\n",path_name);
		closedir(dir);
	}
	else
	{
		remove(path);
	}

}
int main(int argc,char *argv[])
{
	if(argc <2)
	  {
	  fprintf(stderr,"usage %s [filenames]\n",argv[0]);
	  exit(1);
	  }
	int i;
	for(i=1;i<argc;i++)
	{
		char pathn[1024];
		realpath(argv[i],pathn);
		my_rm(".",pathn);
	}

	return 0;
}
