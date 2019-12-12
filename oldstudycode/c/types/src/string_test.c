#include <stdio.h>

int main(void)
{
	char *p= "hellloworld";
	printf("%s\n",(p+1));


	printf("*p = %c\n",*(p+1));
	

	int a =10 ;
	int *pa =&a;
	*pa = 11;
	//*p = c ; error!
	



	return 0;






}
