#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
int dec_oct(int mode)
{
	if(mode > 7777)
	{
		return -1;
	}
	int a;
	a=mode/1000;
	if(a > 7)
		return -1;
	int b = mode/100%10;
	if(b > 7)
		return -1;
	int c = mode/10%10;
	if(c > 7)
		return -1;
	int d = mode%10;
	if(d > 7)
		return -1;
	return a*8*8*8+b*8*8+c*8+d;
}
void my_chmod(char *argv[],mode_t mode)
{
	if(!strcmp(argv[1],"u+r"))
	{
		if(chmod(argv[2],S_IRUSR|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"u+w"))
	{
		if(chmod(argv[2],S_IWUSR|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"u+x"))
	{
		if(chmod(argv[2],S_IXUSR|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"u-r"))
	{
		if(chmod(argv[2],mode&~S_IRUSR)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"u-w"))
	{
		if(chmod(argv[2],mode&~S_IWUSR)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"u-x"))
	{
		if(chmod(argv[2],mode&~S_IXUSR)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"g+r"))
	{
		if(chmod(argv[2],S_IRGRP|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"g+w"))
	{
		if(chmod(argv[2],S_IWGRP|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"g+x"))
	{
		if(chmod(argv[2],S_IXGRP|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"g-r"))
	{
		if(chmod(argv[2],mode&~S_IRGRP)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"g-w"))
	{
		if(chmod(argv[2],mode&~S_IWGRP)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"g-x"))
	{
		if(chmod(argv[2],mode&~S_IXGRP)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"o+r"))
	{
		if(chmod(argv[2],S_IROTH|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"o+w"))
	{
		if(chmod(argv[2],S_IWOTH|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"o+x"))
	{
		if(chmod(argv[2],S_IXOTH|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"o-r"))
	{
		if(chmod(argv[2],mode&~S_IROTH)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"o-w"))
	{
		if(chmod(argv[2],mode&~S_IWOTH)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"o-x"))
	{
		if(chmod(argv[2],mode&~S_IXOTH)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"a+r"))
	{
		if(chmod(argv[2],S_IRUSR|S_IRGRP|S_IROTH|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"a+w"))
	{
		if(chmod(argv[2],S_IWUSR|S_IWGRP|S_IWOTH|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"a+x"))
	{
		if(chmod(argv[2],S_IXUSR|S_IXGRP|S_IXOTH|mode)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"a-r"))
	{
		if(chmod(argv[2],mode&~S_IRUSR&~S_IRGRP&~S_IROTH)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"a-w"))
	{
		if(chmod(argv[2],mode&~S_IWUSR&~S_IWGRP&~S_IWOTH)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
	else if(!strcmp(argv[1],"a-x"))
	{
		if(chmod(argv[2],mode&~S_IXUSR&~S_IXGRP&~S_IXOTH)<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}else
	{
		if(dec_oct(atoi(argv[1]))<0)
		{
			fprintf(stderr,"unknow mode\n");
			exit(1);
		}
		if(chmod(argv[2],dec_oct(atoi(argv[1])))<0)
		{
			fprintf(stderr,"chmod: %s\n",strerror(errno));
			exit(1);
		}
	}
}
int main(int argc ,char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"Usage [mode] [filename]\n");
		exit(1);
	}
	struct stat st;
	lstat(argv[2],&st);
	my_chmod(argv,st.st_mode);
	return 0;
}
