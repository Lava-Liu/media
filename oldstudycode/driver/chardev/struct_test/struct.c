/* ==================================================================
 *       Filename:  struct.c
 *    Description:  
 *        Created:  2013年10月18日 14时06分07秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/

#include <stdio.h>
#include <stdlib.h>
struct Type
{
	int a:1;
	int b:2;
	int c:3;
	int d:4;
};
int main(int argc, char *argv[])
{
		struct Type t = {1, 2, 3, 4};
		struct Type t1;
		t1.a=10;
		t1.b=20;
		t1.c=30;
		t1.d=40;


		struct Type t2 = {
			.a=10, 
			.c=35, 
		};
		struct Type t3 =
		{
               a:15, 
			   c : 25, 
		};
		printf("t:a=%d, b=%d\n", t.a, t.c);
		printf("t:a=%d, b=%d\n", t1.a, t1.c);
		printf("t:a=%d, b=%d\n", t2.a, t2.c);
		printf("t:a=%d, b=%d\n", t3.a, t3.c);
		return 0;
}/* end of function main */
