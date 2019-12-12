#include <stdio.h>


int main(void)
{
	char *p = "hellowworld\n";
	char *c = &p;
	void *v;
	printf("sizeof(p)=%d\n",sizeof(p));
	printf("sizeof(c)=%d\n",sizeof(c));
	printf("sizeof(v)=%d\n",sizeof(v));

	//char *p = "hellowworld\n";
	//printf("%s\n",p);
	//printf("%s\n",(char*)*p);
	printf("%s\n",p);
	printf("%p\n",&p);
	printf("%s\n",&p);
	printf("%c\n",*(p+1));
	//printf("%s\n",*c);
	printf("%s\n",c);
	printf("%c\n",c);
	
	char *pc= NULL;
	//printf("*pc = %c\n", *pc)  duancuowu
	return 0;



}
