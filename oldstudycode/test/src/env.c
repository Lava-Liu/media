#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
int main(int argc ,char *argv[])
{
	int i = 0;
	char *ptr = environ[i];
	while(ptr != NULL)
	{
		printf("%s\n",ptr);
		ptr = environ[++i];
	}
	return 0;
	
}
