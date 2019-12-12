/* ==================================================================
 *       Filename:  day9_obj1.cpp
 *    Description:  
 *        Created:  2013年11月07日 19时19分51秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

template <typename T>
void MaxMin(T **a, int m, int n)
{
	T temp1;
	temp1=a[0][0];
	T temp2;
	temp2=a[0][0];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{

			if(temp1<a[i][j])
			{
				temp1=a[i][j];
			}
			if(temp2>a[i][j])
			{
				temp2=a[i][j];
			}
		}
	}
	cout << temp1 << endl;
	cout << temp2 << endl;
}

int main(void )
{

	int a[2][3]={1, 2, 3, 4, 5, 6};
	double b[2][3]={1, 2, 3, 4, 5, 6};
	MaxMin((int **)a, 2, 3);
	return 0;
}
