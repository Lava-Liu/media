/* ==================================================================
 *       Filename:  test1.c
 *    Description:  
 *        Created:  2013年10月27日 17时23分28秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/

#include <stdio.h>
#include <stdlib.h>

/* ===  FUNCTION  ==================================================
 *         Name:  main
 *  Description:  
 * =================================================================*/
int main(int argc, char *argv[])
{
	short int n = 0x1122;
	if((*(char *)&n)==0x11)
	{
		printf("it's low_size !\n");
	}else{
		printf("it's low_size !\n");

	}
		return EXIT_SUCCESS;
}/* end of function main */
