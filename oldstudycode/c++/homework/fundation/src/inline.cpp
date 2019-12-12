/* ==================================================================
 *       Filename:  inline.cpp
 *    Description:  
 *        Created:  2013年10月31日 10时16分33秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>

using namespace std;

#define MAX(a, b)  \
	((a)>(b)?(a):(b))

//内联函数
inline int max_in(int a, int b)
{

	return a>b?a:b;
}

int max(int a, int b)
{
	return a>b?a:b;
}

int main(void)
{

	cout << "define " << MAX(1+2, 3+4) << endl;
	cout << "max_in"  << max_in(1+2, 3+4) << endl;
	cout << "max"    << max(1+2, 3+4) <<endl;
	return 0;
}
