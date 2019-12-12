#include <stdio.h>
#include <assert.h>
char *mystrcpy(char*dst,char*src)
{
	if(dst == NULL && src == NULL) return 0;
	
	while((*dst++ =*src++)!='\0');
	return dst;
}
char *mystrcpy1(char*dst,char*src)
{
	assert(dst!=NULL && src!=NULL);
	int i;
	for(i=0;src[i]!='\0';i++)
	{
		dst[i]=src[i];

	}
	dst[i]=0;
	return dst;
}
int main(void)
{
	char a[5]="liu";
	char b[10]="hello";
	//mystrcpy(b,a);
	mystrcpy1(b,a);
	printf("%s\n",b);
	return 0;
}
