/* ==================================================================
 *       Filename:  execise4.cpp
 *    Description:  
 *        Created:  2013年10月28日 18时52分23秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int main(void )
{
	int lens;
	cin >> lens;
	for(int i=1;i<=lens;i++)
	{
		for(int j=0;j<lens-i+1;j++)
		{
			cout << '*';
		}
		cout << ' ' << ' ' << ' ' << ' ' << ' ';
		for(int k=0;k<i;k++)
		{
			cout << '*';
		}
		cout << endl;


	}
	return 0;
}
