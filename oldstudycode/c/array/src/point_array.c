#include <stdio.h>
#include <string.h>
int main(void)
{
	char *str1 = "Jame";
	char *str2 = "Joy";
	char *str3 = "Jane";
	char *str[] = {str1,str2,str3};
	int i;
	for(i=0;i <3;i++)
	{
		printf("%s\n",str[i]);
	}
	out(str,3);
	return 0;
}
void out(char**s,int n)
{
	int i;
	for(i =0;i<n;i++)
	{
		printf("%s\n",*(s+i));
	}
}
