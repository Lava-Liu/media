#include <stdio.h>


int main(void)
{
	char c;
	printf("请输入一个number:");
	scanf("%c",&c);
	switch(c)
	{
		case '0':
			printf("输入0\n");
			break;
		case '1':
			printf("输入1\n");
			break;
		case '2':
			printf("输入2\n");
			break;
		case '3':
			printf("输入3\n");
			break;
		default:
		    printf("others..\n");
		    break;	
	}
	return 0;
}
