/* ==================================================================
 *       Filename:  friend_class.cpp
 *    Description:  
 *        Created:  2013年11月07日 09时43分18秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

//将模版类申明为友员类
//需要讲模版类进行前置申明
template <typename T> class Girl;

template <typename T>
class Boy
{
	public:
		Boy(T bat = 0)
		:balance(bat)
		{}
		~Boy(){}
		//将girl申明为友
		
		friend class Girl<T>;
	private:
		T balance;
};

template <typename T>
class Girl
{
	public:
		Girl(T bat = 0)
		:balance(bat)
		{}
		~Girl(){}
		T gerBalance()
		{
			return this->balance;
		}
		//template <typename T>
		T getBoyBalance(Boy<T>&b)
		{
			 cout << "Boy: " << b.balance << endl;
		}
		template <typename U>
			void setBalance(U balance);
	private:
		T balance;
};

template<typename T>
template<typename U>
void Girl<T>::setBalance(U balance)
{
	this->balance = balance;
}


int main(void)
{
	Boy<double>b(1000.1);
	Girl<double>g(10);
	g.getBoyBalance(b);
	return 0;
}
