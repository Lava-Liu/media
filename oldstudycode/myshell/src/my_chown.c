#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
int main(int argc,char *argv[])
{
	if(argc < 3)
	{	
		fprintf(stderr,"Usage [username:groupname] [filename]\n");
		exit(1);
	}
	char *str1;
	char *str2;
	str1=strtok(argv[1],":");
	str2=strtok(NULL,":");
	struct passwd *pwd;
	pwd = getpwnam(str1); 
	struct group *grp;
	grp =getgrnam(str2);
	if(chown(argv[2],pwd->pw_uid,grp->gr_gid)<0)
	{
		fprintf(stderr,"chown: %s\n",strerror(errno));
		exit(1);
	}
}

