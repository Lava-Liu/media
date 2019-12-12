/* ==================================================================
 *       Filename:  execise6.cpp
 *    Description:  
 *        Created:  2013年10月28日 19时13分28秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

int main(void)
{
	int lens;
	cin >> lens;

	for(int i=1;i<=lens;i++)
	{
		if(i==lens/2+1)
		{
			 for(int l=0;l<2*i-1;l++)
		     	{
				    cout << '*';
		    	}
		}
		if(i<=lens/2)
		{
			for(int k=0;k<lens/2+1-i;k++)
			{
				cout << ' ';
			}
			for(int j=0;j<2*i-1;j++)
			{
				cout << '*';
			}
		}else if(i > lens/2+1)
		{

			for(int m=0;m<(i-lens/2-1);m++)
			{
				cout << ' ';
			}
			for(int n=0;n<(lens+1-i)*2-1;n++)
			{
				cout << '*';
			}
		}
		cout << endl;
	}

	return 0;
}
