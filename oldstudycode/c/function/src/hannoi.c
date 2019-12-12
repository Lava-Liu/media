#include <stdio.h>
//把n个盘子从first利用second移动到thrid上
void hannoi(int n,char first ,char second,char third)
{
	if(n == 1)
	{
		printf("%d 从 %c 移动到%c\n",n,first,third);
	}
	else
	{
		hannoi(n-1,first,third,second);
		printf("%d从%c移动到%c\n",n,first,third);
		hannoi(n-1,second,first,third);

	}
}

int main(void)
{
	printf("请输入盘子个数： ");
	int num;
	scanf("%d",&num);
	hannoi(num,'A','B','C');
	return 0;

}
