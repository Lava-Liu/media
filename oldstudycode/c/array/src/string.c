#include <stdio.h>
#include <string.h>
int main(void)
{
	int a= 2345;
	char str1[]={'h','e','l','l','o'};
	char *str2="hello";
	char str3[]={'h','e','l','l','o','\0'};
	char str4[]="hello";
	printf("%s\n",str1);
	printf("%s\n",str2);
	printf("%s\n",str3);
	printf("%s\n",str4);
	printf("%d\n",sizeof(str1));
	printf("%d\n",strlen(str1));
	printf("%d\n",sizeof(str2));
	
	printf("%d\n",strlen(str2));
	printf("%d\n",sizeof(str3));
	printf("%d\n",strlen(str3));
	
}
