#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
int main(int argc ,char *argv[])
{
	char buffer[256];
	getcwd(buffer,256);
	printf("%s\n",buffer);
	return 0;
}
