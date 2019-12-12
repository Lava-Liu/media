#include <stdio.h>

int fab(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	return fab(n-1)+fab(n-2);
}
int main(void)
{
	int a;
	printf("请输入一个天数：");
	scanf("%d",&a);
	while(a < 0)
	{
		printf("非法的输入 请重新输入：");
		scanf("%d",&a);
	}
	printf("兔子的数量为：%d\n",fab(a));
}
