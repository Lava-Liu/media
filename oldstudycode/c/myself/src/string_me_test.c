#include "string_me.h"
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[]="helloworld";
	char str1[]="java";
    printf("%d\n",strlen_me(str));
	strcopy_me(str,str1);
	printf("%s\n",str);


	return 0;
}
