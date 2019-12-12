/* ==================================================================
 *       Filename:  execise3.cpp
 *    Description:  
 *        Created:  2013年10月28日 18时39分39秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int main(void)
{
	int lens ;
	cin >> lens;
	for(int i=1;i<=lens;i++)
	{
		for(int k=0;k<(lens-i);k++)
		{
				cout << ' ';
		}
		for(int j=0;j<(2*i-1);j++)
		{
			cout << '*';
		}
		cout << endl;

	}
	return 0;
}

