/* ==================================================================
 *       Filename:  test.c
 *    Description:  
 *        Created:  2013年10月25日 15时19分54秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
int main(void )
{
	int fd = open("/dev/myblockdev", O_RDWR);
	if(fd < 0)
	{
		printf(stderr, "open: %d\n")
	}
}
