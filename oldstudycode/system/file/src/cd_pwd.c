#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
int main(void)
{
	char *cwd = getcwd(NULL,0);
	if(cwd == NULL)
	{
		fprintf(stderr,"cwd %s\n",strerror(errno));
		exit(1);
	}
	printf("cwd:%s\n",cwd);
	//修改当前路径
	//.
	//..
	if(chdir("/etc/passwd")< 0)
	{
		fprintf(stderr,"chdir %s\n",strerror(errno));
		exit(1);

	}
	char cwd_buf[256] = {};
	if(getcwd(cwd_buf,256) == NULL)
	{
		fprintf(stderr,"getcwd %s\n",strerror(errno));
		exit(1);
	}
	printf("cwd_buf:%s\n",cwd_buf);



	return 0;
}
