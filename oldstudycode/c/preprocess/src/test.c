#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define SQUARE(x) x*x
#define PRINT(format , value) \
	printf("the value of "#value" is "formate"",value)
int main(void )
{
	int x=10;
	PRINT("%d",x+1);
	printf("%d\n",SQUARE(2+1));
	printf("%s\n",__FILE__);
	printf("%d\n",__LINE__);
	printf("%s\n",__DATE__);
	printf("%s\n",__TIME__);
	printf("%d\n",__STDC__);
	return 0;
}

