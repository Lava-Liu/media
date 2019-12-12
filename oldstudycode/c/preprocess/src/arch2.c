#include <stdio.h>

int main(void)
{
	char *p = NULL;
#if defined(x86)//x86
p = (char*),malloc(1024*1024);
#endif
#if defined(ARM)//ARM
p = (char*)malloc(1024);
#endif

 printf("%p:\n",p);
	return 0;
}
