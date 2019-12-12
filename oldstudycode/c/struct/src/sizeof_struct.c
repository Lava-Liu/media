#include <stdio.h>
typedef struct
{
	char a;
	int b;
	char c;
}s1;
typedef struct
{
	int  a;
	char b;
	char c;
}s2;

int main(void)
{
	printf("sizeof(s1)=%d\n",sizeof(s1));
	printf("sizeof(s2)=%d\n",sizeof(s2));
	return 0;
}
