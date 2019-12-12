/* ==================================================================
 *       Filename:  account_test.c
 *    Description:  
 *        Created:  2013年11月03日 19时15分51秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include "account.h"

int main(void)
{
	Account acc("liuwei", 99999);
	try{
		acc.deposit(1000);
		acc.withdraw(2000000);
	}catch(Account::ExceptionMessage& p )
	{
		cerr << p.what() <<endl;
	}
	return 0;
}
