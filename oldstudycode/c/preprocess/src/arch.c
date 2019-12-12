#include <stdio.h>

int main(void)
{
	char *p = NULL;
#if ARCH > 0//x86
p = (char*),malloc(1024*1024);
#elif ARCH < 0//ARM
p = (char*)malloc(1024);
#else
 p = (char*)malloc(100);
#endif
 printf("%p:\n",p);
	return 0;
}
