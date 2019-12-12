#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main(void)
{
	FILE *fp;
	fp = popen("cat /etc/passwd","r");
	char buffer[40];
	memset(buffer,0,sizeof(buffer));
	while(fgets(buffer,40,fp)!=NULL)
	{
		printf("%s\n",buffer);
	}
	pclose(fp);
	printf("-------------------------\n");
	fp = popen("wc -l","w");
	fprintf(fp,"1\n2\n\3\n");
	pclose(fp);
	return 0;
}
