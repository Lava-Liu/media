/* ==================================================================
 *       Filename:  template_fun2.cpp
 *    Description:  
 *        Created:  2013年11月06日 16时18分13秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

template <typename T, typename E>
T myadd(T a, E b)
{
	cout << "T myadd(t, E)" <<endl;
	return (a+b);
}

template <typename T>
T myadd(T a, T b)
{
	cout << "T myadd()" <<endl;
	return (a+b);
}

int main(void)
{

	myadd(1, 2.1);
	return 0;
}
