/* ==================================================================
 *       Filename:  execise8.cpp
 *    Description:  
 *        Created:  2013年10月28日 20时12分35秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int main(void)
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout << j << "x" << i << "=" << i*j <<'\t'; 
		}
		cout << endl;
	}
	return 0;
}
