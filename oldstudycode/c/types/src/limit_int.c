#include <stdio.h>

//计算本机 int 型数据有多少位
int limit_int()
{
	int data = 1;
	int counter = 1;
	while((data = data << 1) != 0)
	{

	counter++;
	
	}
	return counter;




}
int uint_max()
{
	int bits = limit_int();
	int data =1 ;
	int i=0;
	for(i;i <bits-1;i++)
	{
		data = (data << 1 ) |1;
	}
	return data;
}
int int_max()
{
	int bits = limit_int();
	int data =1 ;
	int i=0;
	for(i;i <bits-2;i++)
	{
	data = (data << 1) | 1;
	}
	return data;
}
int int_min()
{
	return 1 << limit_int()-1;
}

int main (void)
{
	int bits = limit_int();
    printf("int bits =%d\n",bits);
    printf("uint_max = %u\n",uint_max());
    printf("int_max = %d\n",int_max());
    printf("int_min = %d\n",int_min());

return 0;


}
