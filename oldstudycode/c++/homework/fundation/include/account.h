/* ==================================================================
 *       Filename:  account.h
 *    Description:  a
 *        Created:  2013年11月03日 18时44分25秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <iostream>
using namespace std;
class Account
{
	public:
	    Account()
		{
			
		}
		Account(string name, int balance):name(name), balance(balance)
	{
		cout << "account()" <<endl;
	}
		~Account(){}
		int getbalance()
		{
			return balance;
		}
		void deposit(int );
		void withdraw(int );
		class ExceptionMessage
		{
			public:
				ExceptionMessage():Message("unknow exception!")
				{
				}
				ExceptionMessage(string Message):Message(Message){}
				~ExceptionMessage(){}
				string what();
				
				
			private:
				string Message;
		};

	private:
		string name;
		int balance;



};






#endif
