#include <stdio.h>
#include <string.h>
int main(void)
{   char str[10];
	char buffer[15] = {'\0'};
	gets(buffer);
	puts(buffer);
	strcpy(str,buffer);
	printf("str=%s\n",str);

	return 0;
}
