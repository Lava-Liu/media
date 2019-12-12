/* ==================================================================
 *       Filename:  object2.cpp
 *    Description:  
 *        Created:  2013年11月04日 18时45分25秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class CFraction
{
	public:
		CFraction(int nu=0, int de = 1){
		this->nume=nu;
		this->deno=de;
		}
		void set(int nu, int de)
		{
			this->nume=nu;
			this->deno=de;
		}
		void input()
		{
			int a, b;
			cin >> a/b;
			this->nume=nume;
			this->deno=deno;
		}
		void simplify()
		{
			int i, temp;
			temp=(nume>deno?deno:nume);
			for(i=2;i<=temp;i++)
			{
				if(i=temp)
				{
					return;
				}
				if(nume%i==0 && deno%i ==0)
				{
					nume=nume/i;
					deno=deno/i;
					simplify();
				}
			}
		}
	private:
		int nume;
		int deno;
};


int main(void)
{
	CFraction c(12, 15);
	c.input();
	return 0;
}
