/* ==================================================================
 *       Filename:  test.cpp
 *    Description:  
 *        Created:  2013年11月08日 10时35分44秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;


int main(void)
{

	int array[10] = {};
	for(int i=0;i<10;i++)
	{
		array[i]=i;
	}

	int *p1=array;
	for(p1;p1<array+10;p1++)
	{
		cout << *p1 << " ";
	}
	int *p2 = &array[0];
	for(;p2< array+10;p2++)
	{
		cout << *p2 << " ";
	}
	cout << *(&array[0] +1) << endl;
	cout << *(array +1) << endl;
	return 0;
}
