#include <stdio.h>
void fun(int i,int j)
{
	printf("Pi=%p\n",&i);
	printf("Pj=%p\n",&j);
}
int main(void)
{
	fun(10,11);
	return 0;
}
