/* ==================================================================
 *       Filename:  execise5.cpp
 *    Description:  
 *        Created:  2013年10月28日 18时59分15秒
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
	for(int i=0;i<=lens;i++)
	{
		for(int j=0;j<lens-i+1;j++)
		{
			cout << ' ';
		}
		for(int k=0;k<(2*i)-1;k++)
		{
			if(k==0 || k==(2*i-2))
			{
				cout << '*';
			}else{
				cout << ' ';
			}
		}
		if(i == lens )
		{
			cout << endl;
			for(int l=0;l<=2*lens;l++)
			{
				cout << '*';
			}
		    cout << endl;
		}else{
		
			
			cout << endl;
		}
	}
	return 0;
}
