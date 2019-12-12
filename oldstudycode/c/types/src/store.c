#include <stdio.h>


int a;
int b = 10;
static int c = 11;

void fun()
{
	int j =13;
	int k;

	printf("j=0x%x\n",&j);
	printf("k=0x%x\n",&k);

}


int main(void)
{
	int i =12;
	fun();
	static s = 15;
	register r = 16;
	printf("a=0x%x\n",&a);
	printf("b=0x%x\n",&b);
	printf("c=0x%x\n",&c);
	printf("i=0x%x\n",&i);
	printf("s=0x%x\n",&s);
	//printf("0x%x\n",&a);
	//printf("0x%x\n",&a);












return 0;
}
