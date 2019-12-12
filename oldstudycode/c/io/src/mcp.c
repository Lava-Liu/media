#include <stdio.h>

int main(void)
{
	FILE *out=fopen("a.txt","w");
	FILE *fp=fopen("/etc/passwd","r");
	char ch;
	while((ch=fgetc(fp))!= EOF)
	{
		//printf("%c",ch);
		fputc(ch,out);
	}
	fclose(fp);
	fclose(out);
	return 0;
}
