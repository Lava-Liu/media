#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main(void)
{
	static a=11;
	char *p= "hellowrld!";
	printf("%p\n%p\n",&a,p);
	//realloc(p,100); error!
	return 0;
}
