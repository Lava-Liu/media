#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int i;
	for(i = 0;i < argc;i++)
	{
		printf("argv[%d]: %s\n",i,argv[i]);
	}
	printf("EMSD=%s\n",getenv("EMSD"));

	return 0;
}
