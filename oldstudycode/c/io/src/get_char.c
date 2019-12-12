#include <stdio.h>

int main(void)
{
	char ch;
	while((ch=getchar())!= EOF)
	{
		printf("%c(%d)\n",ch,ch);
	}
	return 0;
}
