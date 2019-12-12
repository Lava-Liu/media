#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char * p = (char *)malloc(10);
	if(p == NULL) return -1;
	strcpy(p,"hello");
	char *q = (char*)calloc(10,sizeof(char));
	printf("%s\n",p);
	printf("%s\n",q);
	

	return 0;

}

