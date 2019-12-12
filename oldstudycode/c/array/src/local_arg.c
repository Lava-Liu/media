#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	printf("argc:%d\n",argc);
	printf("--------------------------------\n");
	int i;
	int n;
	for(i =0;i<argc;i++)
	{
		if(number(argv[i])==1)
		
			{
		printf("Not all number!\t");
		
			}else
			{
		printf("Yes it's all number!\t");
			}
		printf("argv[%d]=%s\n",i,argv[i]);
		
		

	}

	return 0;
}
int number(char *argv)
{
	int i;
	int n = strlen(argv);
	for(i=0;i<n;i++)
	{
		if(argv[i]<'0'||argv[i]>'9')
			return 1;
		return 0;
	}

}
