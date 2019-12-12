#include "string_me.h"
#include <stdio.h>
ElementType strlen_me(char *p)
{
	int i=0;
	while(1)
	{
		if(*(p+i)=='\0')
			break;
		i++;
	}
	return i;

}
void strcopy_me(char *a,char *p)
{
	 int i;
	 int j;
     j=strlen_me(p);
	 for(i=0;i<=j;i++)
	 {
		 *(a+i)=*(p+i);
		 if(*(p+i)=='\0')
		 {
			 *(a+i+1)='\0';
			 break;
		 }
	 }
}
void strcmp_me(char *a,char *P)
{
	}
