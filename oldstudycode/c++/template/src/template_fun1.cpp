/* ==================================================================
 *       Filename:  template_fun1.cpp
 *    Description:  
 *        Created:  2013年11月06日 15时00分09秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

template <class T>
inline T myadd(T a, T b)
{
	return (a+b);
}




//int double 
template <typename T, typename E>
T compare(T a, E b)
{
	cout << "a:" << a << "b:" << b <<endl;
	if(a>b) return 1;
	else if(a<b) return -1;
	else return 0;
}
int compare(int a, int  b)
{
	cout << "compare()" <<endl;
	if(a>b) return 1;
	else if(a<b) return -1;
	else return 0;
}

int main(void)
{
	cout << "10, 10: " << compare<int, int>(10, 10) <<endl;
	cout << "1, 1.6:  " << compare<int, double>(1, 1.6) <<endl;
	compare(10, 10);
	compare(1, 1.5);
	compare<int, int>(1, 1.5);
	compare<int , double>(1, 1.5);
	return 0;
}
