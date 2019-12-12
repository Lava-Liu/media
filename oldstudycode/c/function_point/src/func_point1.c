#include <stdio.h>
#include <stdlib.h>

void out(char *p)
{
	printf("%s\n",p);
}

int main(void )
{
	out("abcedefg");
	void (*pf)(char *);
	pf = &out;//pf=out;
	pf("give me five!");//(*pf)("for the dream");

	typedef void (*pfun)(char*);
	pfun f1 = out;
	f1("hellow");
	return 0;
}
