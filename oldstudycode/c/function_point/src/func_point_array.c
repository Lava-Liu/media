#include <stdio.h>
void out(char* p)
{
	printf("%s\n",p);
}

int main(void)
{
	void (*pfun)(char*);
	pfun=&out;
	void (*pfun_array[3])(char*);
	pfun_array[0]=pfun;
	pfun_array[0]("Hello");
	return 0;
	
}
