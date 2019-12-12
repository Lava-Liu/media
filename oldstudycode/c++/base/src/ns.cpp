/* ==================================================================
 *       Filename:  ns.cpp
 *    Description:  
 *        Created:  2013年10月28日 14时36分27秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;
#include "ns.h"
namespace
{
	int number = 100;
};
static int counter = 200;

void out(int n)
{
	cout << "ns:" << n << endl;
	cout << "number:" << number << endl;
}

