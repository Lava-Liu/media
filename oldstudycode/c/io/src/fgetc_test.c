#include <stdio.h>

int main(void)
{
	FILE *fp=fopen("/etc/passwd","r");
	char ch;
	while((ch=fgetc(fp))!= EOF)
	{
		printf("%c",ch);
	}
	fclose(fp);
	return 0;
}
