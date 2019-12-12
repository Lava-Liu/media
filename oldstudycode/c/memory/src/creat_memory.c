#include <stdio.h>
#include <malloc.h>
void create_memory(char **q,int n)
{
	*q=(char*)malloc(100);
	assert(*q!=NULL);
	

}
int main(void)
{
	char *p = NULL;
	create_memory(&q,100);
	strcpy(p,"helloworld");
	printf
	free(p);
	return 0;

}
