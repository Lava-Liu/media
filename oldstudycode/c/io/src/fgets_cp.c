#include <stdio.h>
int main(void)
{
	FILE *fp = fopen("/etc/passwd","r");
	FILE *out = fopen("b.txt","w");
	char buffer[256] = {'\0'};
	while(fgets(buffer,256,fp)!=NULL)
	{
		fputs(buffer,out);
	}
	fclose(fp);
	fclose(out);
	return 0;
}
