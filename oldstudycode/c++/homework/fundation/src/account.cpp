/* ==================================================================
 *       Filename:  account.h
 *    Description:  a
 *        Created:  2013年11月03日 18时44分25秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#include "account.h"
void Account::deposit(int amount)
{
	if(amount < 0)
    throw ExceptionMessage("deposit amount < 0");
	balance += amount;
}
void Account::withdraw(int amount)
{
	if(amount < 0)
		throw ExceptionMessage("withdraw amount < 0");
	if(balance < amount)
        throw ExceptionMessage("withdraw amount < balance");
	balance -= amount;


}
string Account::ExceptionMessage::what()
{
	cout << "Exception ....." << endl;
	return Message;
}
