#include <stdio.h>
#include <memory.h>
union data 
{
	int i;
	char c;
	float f;
};
int main(void)
{

	union data d;
	printf("&d.i=%p\n &d.c=%p\n&d.f=%p\n",&d.i,&d.c,&d.f);
	memset(&d,0,sizeof(d));
	d.c="A";
	printf("%d",d.i);
	//d.i = 65;
	//printf("d.c = %c\n",d.c);
	//printf("%d\n",'a');
	d.c='A';

	return 0;
}	
