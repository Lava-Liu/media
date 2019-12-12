/* ==================================================================
 *       Filename:  execise1.cpp
 *    Description:  
 *        Created:  2013年10月28日 16时54分16秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c, d;
	int i=0;
	int j=0;
	int k=0;
	int e=0;
	for(i=0;i<3;i++)
	{
		a=i;
		for(j=0;j<10;j++)
		{
			b=j;
			for(k=0;k<10;k++)
			{
				c=k;
				for(e=0;e<10;e++)
				{
					d=e;
					if((a*1000+b*2*100+c*3*10+d*4)==2008  && a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
					{
						cout << a << b << c << d << endl;
					}
				
				}
			}
		}

	}
	return 0;

}


