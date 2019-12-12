#include "sum.h"
#include  <stdio.h>

int main(void)
{
	printf("请输入起始数字和结束数字");

	int start;
	int end;
	scanf("%d%d",&start,&end);
	int i = start;
	int s = 0 ;
	for (i;i <= end; i++)
	{
		s = sum(start, i);
		printf("sum(%d,%d):%d\n",start,i,s);
	}
}
