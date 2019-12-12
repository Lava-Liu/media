/* ==================================================================
 *       Filename:  test.cpp
 *    Description:  
 *        Created:  2013年11月08日 15时02分00秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include "myvector.h"


int main(void)
{
	Myvector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout <<v.front() << endl;
	cout <<v.back() << endl;

	return 0;
}
