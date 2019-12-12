#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <dirent.h>
//./bin/st_mode filename
//打印此文件的类型和权限位信息
//如：
struct stat get_mode(char *name)
{
	struct stat st_n;
	memset(&st_n,0,sizeof(stat));
	if(lstat(name,&st_n)<0)
	{
		fprintf(stderr,"stat :%s\n",strerror(errno));
		exit(1);

	}
	return st_n;

}

char * out_mode(char *name ,mode_t mode)
{
	if(S_ISREG(mode))
	    name[0]='-';
	if(S_ISDIR(mode))
	    name[0]='d';
	if(S_ISBLK(mode))
	    name[0]='b';
	if(S_ISCHR(mode))
	    name[0]='c';
	if(S_ISFIFO(mode))
	    name[0]='p';
	if(S_ISSOCK(mode))
	    name[0]='s';
	if(S_ISLNK(mode))
	    name[0]='l';
	if((mode & S_IRUSR))
	{
	    name[1]='r';
	}else
	{
	    name[1]='-';
	}
	if((mode & S_IWUSR))
	{
	    name[2]='w';
	}else
	{
	    name[2]='-';
	}
	if((mode & S_IXUSR))
	{
	    name[3]='x';
	}else
	{
	    name[3]='-';
	}
	if((mode & S_IRGRP))
	{
	    name[4]='r';
	}else
	{
	    name[4]='-';
	}
	if((mode & S_IWGRP))
	{
	    name[5]='w';
	}else
	{
	    name[5]='-';
	}
	if((mode & S_IXGRP))
	{
	    name[6]='x';
	}else
	{
	    name[6]='-';
	}
	if((mode & S_IROTH))
	{
	    name[7]='r';
	}else
	{
	    name[7]='-';
	}
	if((mode & S_IWOTH))
	{
	    name[8]='w';
	}else
	{
	    name[8]='-';
	}
	if((mode & S_IXOTH))
	{
	    name[9]='x';
	}else
	{
	    name[9]='-';
	}
	return name;
}
void out_uid(uid_t uid)
{
	struct passwd *uid_name;
	uid_name = getpwuid(uid);
	printf("%8s",uid_name->pw_name);
}
void out_gid(gid_t gid)
{
	struct group  *gidname; 
	gidname = getgrgid(gid);
	printf("%8s",gidname->gr_name);



}
void out_time(time_t timer,char *path)
{
	char str[1024]={};
	struct tm *tim;
	tim = localtime(&timer);
	printf("%2d月 %02d %02d:%02d %s\n",tim->tm_mon+1,tim->tm_mday,tim->tm_min,tim->tm_sec,path);
	/*strcpy(str,asctime(localtime(&timer)));
	int len=strlen(asctime(localtime(&timer)));
	
	str[24]='\0';
	printf("%s %s\n",str,path);*/
}
void out_inf(char *pathname)
{
	char buffer[1024]={};
	struct stat st=get_mode(pathname);
	out_mode(buffer,st.st_mode);
	printf("%s",buffer);
	printf(" ");
	printf("%d",st.st_nlink);
	printf(" ");
    out_uid(st.st_uid);
	printf(" ");
    out_gid(st.st_gid);
	printf(" ");
	printf("%8ld",st.st_size);
	printf(" ");
	out_time(st.st_mtime,pathname);

}
out_dir(char *path)
{
	struct stat st;
	stat(path,&st);
	if(S_ISDIR(st.st_mode))
	{
		DIR *dir;
		printf("%s  \n\n\n",path);
		if((dir = opendir(path))<0)
		{
			fprintf(stderr,"opendir: %s\n",strerror(errno));
			exit(1);
		}
		
		chdir(path);
		struct dirent *dire;
		while((dire=readdir(dir))!=NULL)
		{
			if(!strcmp(dire->d_name,"..")||!strcmp(dire->d_name,"."))
				continue;
			out_dir(dire->d_name);
		}
		chdir("..");
	}else
	{
		out_inf(path);

	}
}
int main(int argc,char* argv[])
{
	/*if(argc < 2)

	{
		fprintf(stderr,"%s [filename]\n",strerror(errno));
		exit(1);
	}*/
	if(argc == 1)
	{

		DIR *dir=opendir(".");
		struct dirent *dire;
		while((dire=readdir(dir))!=NULL)
		{
			if(!(strcmp(dire->d_name,"."))||!strcmp(dire->d_name,".."))
			{
				continue;
			}

			out_dir(dire->d_name);
		}

	}
	if(argc > 1)
	{
		int i;
		for(i=1;i<argc;i++)
		{
			out_dir(argv[i]);
		}

	}
	


	
	return 0;
}
