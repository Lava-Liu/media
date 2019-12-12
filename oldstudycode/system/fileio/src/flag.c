#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define MAX_SIZE 4096
int main(void)
{
   printf("O_RDONLY: %d\n",O_RDONLY);
   printf("O_WRONLY: %d\n",O_WRONLY);
   printf("O_RDWR: %d\n",O_RDWR);
   printf("O_APPEND: %d\n",O_APPEND);
   printf("O_CREAT: %d\n",O_CREAT);
   printf("O_NONBLOCK: %d\n",O_NONBLOCK);
   printf("O_TRUNC: %d\n",O_TRUNC);
	return 0;
}
