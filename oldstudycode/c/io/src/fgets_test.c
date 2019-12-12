#include <stdio.h>
#include <string.h>
int main(void)
{
	char buff[10] = {'\0'};
	fgets(buff,sizeof(buff),stdin);
	printf("%d\n",strlen(buff));
	fputs(buff,stdout);
	buff[strlen(buff)-1]=0;//把‘\n’该为\0
	return 0;
}
