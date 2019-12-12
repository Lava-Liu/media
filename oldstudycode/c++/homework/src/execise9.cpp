/* ==================================================================
 *       Filename:  execise9.cpp
 *    Description:  
 *        Created:  2013年11月04日 10时59分30秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Account
{
	public:
		Account(){}
		Account(int amount):balance(amount){}
		~Account(){}
		void setBalance(int amount)
		{
			balance=amount;
		}
		void out()
		{
			cout << balance << endl;
		}
	private:
		static int balance;
};

int main(void)
{
	Account a(10);
	Account b(20);
	a.out;
	b.out;
	
	return 0;
}


