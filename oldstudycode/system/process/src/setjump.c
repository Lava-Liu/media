#include <stdio.h>
#include <setjmp.h>
#include <string.h>
#include <errno.h>
#include <setjmp.h>
#include <stdlib.h>
jmp_buf jp;
void fun()
{
	longjmp(jp,2);
}
int main(void)
{
	int ret;
	if((ret=setjmp(jp))!=0)
	{
		if(ret == 2)
			printf("jmp from 2 pos!\n");
		else if(ret == 3)
		{	printf("jmp from 3 pos!\n");
			exit(0);

		}
	}
	if(ret == 2)
		longjmp(jp,3);
	fun();
	return 0;
}
