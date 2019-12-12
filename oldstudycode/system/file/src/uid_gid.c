#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("%d\t%d\n",getuid(),getgid());
	printf("%d\t%d\n",geteuid(),getegid());
	return 0;
}
