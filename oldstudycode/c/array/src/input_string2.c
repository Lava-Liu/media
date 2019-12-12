#include <stdio.h>

int main(void)
{
	char s[10]={'\0'};
	
	scanf("%s",s);
	printf("%s\n",s);
	int c;
	while((c=getchar())!='\n')
		continue;
	char buffer[256]={'\0'};
	fgets(buffer,256,stdin);
	printf("buffer:%s\n",buffer);
	char a[256]={'\0'};
	fgets(a,256,stdin);
	printf("a:%s\n",a);


	return 0;
}
