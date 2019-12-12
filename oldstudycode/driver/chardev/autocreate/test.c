/* ==================================================================
 *       Filename:  test.c
 *    Description:  
 *        Created:  2013年10月22日 13时40分00秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	
	if(argc < 2)
	{
		fprintf(stderr, "Usage : %s [filepath]\n", argv[0]);
		exit(1);
	}
	int fd=open(argv[1], O_RDWR);
	if(fd < 0)
	{
		fprintf(stderr, "open : %s\n", strerror(errno));
		exit(1);
	}
	write(fd, "Hello", 5);
	printf("write func finished!\n");
    lseek(fd, 0, SEEK_SET);
	char buffer[100];
	memset(buffer, 0, sizeof(buffer));
	read(fd, buffer, sizeof(buffer));
	printf("buffer: %s\n", buffer);
	printf("read data finished!\n");
	return EXIT_SUCCESS;
}/* end of function main */
