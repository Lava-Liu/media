/* ==================================================================
 *       Filename:  execise7.cpp
 *    Description:  
 *        Created:  2013年10月28日 19时49分06秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int main(void)
{
	int i, a, b, c, d;
	for(i=100;i<10000;i++)
	{
		if(i<=999)
		{
			a=i%10;
			c=i/100;
			if(a==c)
				cout <<  i << endl;
		}else
		{
			a=i%10;
			b=i/10;
			b=b%10;
			c=i/100;
			c=c%10;
			d=i/1000;
			if(a==d && b==c)
			{
				cout << i << endl;
			}
		}
	}
	
	

	return 0;
}

