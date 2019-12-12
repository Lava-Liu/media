#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void )
{
	unsigned int val =  0x12345678;

    void *ptr = &val;
	printf("%x\n",*((unsigned char*)ptr));
	return 0;
}

