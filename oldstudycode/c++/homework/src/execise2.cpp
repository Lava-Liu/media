/* ==================================================================
 *       Filename:  execise2.cpp
 *    Description:  
 *        Created:  2013年10月28日 18时28分56秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int main(void )
{
	for(int i=1;i<10;i++)
	{
		for(int j=0;j<(2*i)-1;j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}

