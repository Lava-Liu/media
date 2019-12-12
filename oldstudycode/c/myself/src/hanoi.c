#include <stdio.h>

void hanoi(int n,char first,char second,char third)
{
	if(n==1) 
	{
		printf("把%d从%c移动到%c上\n",n,first,third);
	}else
	{
		hanoi(n-1,first,third,second);
		printf("把%d从%c移动到%c上\n",n,first,third);
		hanoi(n-1,second,first,third);
	}

}

int main(void)
{
	int n;
	printf("请输入塔的层数：");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}
