#include <stdio.h>
#define va_list char*
#define va_start(pointer,first)\
	pointer=(char*)&first
#define va_arg(pointer,type )\
	*((type*)(pointer+=sizeof(type)))
#define va_end(pointer) pointer = 0
float average(int n,...)
{
	va_list p;
	//char *p=(char *)&n;
	va_start(p,n);
	int i = 1;
	int s = 0;
	//char *q = p+sizeof(int);
	for(i;i <= n;i++)
	{
		//s+=*((double *)(q+(i-1)*sizeof(double)));
		s+=va_arg(p,int);
	}
	//*p=0;
	va_end(p);
	return s/n;
}
int main(void)
{


	int  s= average(5,1,2,3,4,5);
	printf("s=%d\n",s);
	return 0;
}


