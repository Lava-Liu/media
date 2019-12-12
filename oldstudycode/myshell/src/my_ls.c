#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
ls_mode(mode_t mode)
{
	if(S_ISREG(mode))
	{
		printf("-");
	}
	if(S_ISDIR(mode))
	{
		printf("d");
	}
	if(S_ISBLK(mode))
	{
		printf("b");
	}
	if(S_ISLNK(mode))
	{
		printf("l");
	}
	if(S_ISFIFO(mode))
	{
		printf("p");
	}
	if(S_ISCHR(mode))
	{
		printf("c");
	}
	if(S_ISSOCK(mode))
	{
		printf("s");
	}
	if(S_IRUSR&mode)
	{
		printf("r");
	}else
	{
		printf("-");
	}
	if(S_IWUSR&mode)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	if(S_IXUSR&mode)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}
	if(S_IRGRP&mode)
	{
		printf("r");
	}
	else
	{
		printf("-");
	}
	if(S_IWGRP&mode)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	if(S_IXGRP&mode)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}
	if(S_IROTH&mode)
	{
		printf("r");
	}
	else
	{
		printf("-");
	}
	if(S_IWOTH&mode)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	if(S_IXOTH&mode)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}
	printf(" ");
	
}
void ls_nlink(nlink_t nlink)
{
	printf("%d ",nlink);
}
void ls_uid(uid_t uid)
{
	struct passwd *pwd;
	pwd = getpwuid(uid);
	printf("%6s ",pwd->pw_name);
}
void ls_gid(gid_t gid)
{
	struct group *grp;
	grp = getgrgid(gid);
	printf("%6s ",grp->gr_name);
}
void ls_size(size_t size)
{
	printf("%6d ",size);
}
void ls_time(time_t time)
{
	struct tm *tm; 
	tm=localtime(&time);
	printf("%2d %d ",tm->tm_mon+1,tm->tm_mday);
}
void ls_all(char *filename)
{
	struct stat st;
	lstat(filename,&st);
	ls_mode(st.st_mode);
	ls_nlink(st.st_nlink);
	ls_uid(st.st_uid);
	ls_gid(st.st_gid);
	ls_size(st.st_size);
	ls_time(st.st_ctime);
}
void my_ls(char *pathname,char *cmd)
{
	DIR *dp;
	struct dirent *dir;
	if((dp=opendir(pathname))==NULL)
	{
		fprintf(stderr,"opendir: %s\n",strerror(errno));
		exit(1);
	}
	chdir(pathname);
	while((dir=readdir(dp))!=NULL)
	{
		if(!strcmp(dir->d_name,".")||!strcmp(dir->d_name,".."))
		{
            continue;
		}
		if(!strcmp(pathname,".")&&!strcmp(cmd,"nothing"))
		{
		  printf("%s \n",dir->d_name);
		}else if(!strcmp(cmd,"-l"))
		{
		  ls_all(dir->d_name);
		  printf("%s ",dir->d_name);
		  printf("\n");
		}
		if(!strcmp(cmd,"-R"))
		{
			struct stat st;
			lstat(dir->d_name,&st);
			if(S_ISDIR(st.st_mode))
			{
				ls_all(dir->d_name);
		        printf("%s \n",dir->d_name);
				
				my_ls(dir->d_name,"-R");
				
			}else
			{
				ls_all(dir->d_name);
		        printf("%s \n",dir->d_name);
				
			}
		}
		

	}
	chdir("..");
	printf("\n");

}
int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		my_ls(".","nothing");
		
			
	}
	if(argc == 2)
	{
		if(!strcmp(argv[1],"-l"))
		{
			my_ls(".","-l");
		}
		if(!strcmp(argv[1],"-R"))
		{
			my_ls(".","-R");
		}
	}
	if(argc == 3)
	{
		if(!strcmp(argv[1],"-l"))
		{
			struct stat st;
			lstat(argv[2],&st);
			if(S_ISDIR(st.st_mode))
			{
			my_ls(argv[2],"-l");
			}else
			{
				ls_all(argv[2]);
		        printf("%s \n",argv[2]);

			}

		}
		if(!strcmp(argv[1],"-R"))
		{
			my_ls(argv[2],"-R");
		}

	}
	return 0;
}
