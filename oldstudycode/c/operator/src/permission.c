#include <stdio.h>
#define R 4
#define W 2
#define X 1
void out_mode(int mode)

{
	
	if((mode&R)==R)
	{
		printf("r");
	}else
	{printf("-");

	}
	if((mode&W)==W)
	{
		printf("w");
	}else
	{printf("-");

	}
	if((mode&X)==X)
	{
		printf("x\n");
	}else
	{printf("-\n");

	}

}
void out_permission(int mode)
{
	int user;
	int group;
	int other;
	
	printf("user:");
	user = mode / 100;
	out_mode(user);
	printf("group:");
	group = (mode%100)/10;
	out_mode(group);
	printf("other:");
	other = mode % 10;
	out_mode(other);

}
int main(void)
{
	int permission;
	printf("请输入一个权限的三位数表示： ");
	scanf("%d",&permission);
	out_permission(permission);
	return 0;
}
