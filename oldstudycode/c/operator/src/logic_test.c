#include <stdio.h>

int main(void)
{
	int logic;
	int a;
	int b;
	int m =10;
	int n = 11;
	printf("请输入两个数字：");
	scanf("%d%d",&a,&b);
	/*if((logic =(a>0 && b >0)))
	{
		printf("a和b都大于0!\n");
	}
	printf("logic=%d\n",logic);*/
	if((m=(a>0))&&(n=(b>0)))
	{
		printf("a和b都大于0！\n");
	}
	printf("m=%d,n=%d\n",m,n);

	return 0;
}
