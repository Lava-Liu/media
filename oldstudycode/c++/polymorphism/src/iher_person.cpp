/* ==================================================================
 *       Filename:  iher_person.cpp
 *    Description:  
 *        Created:  2013年11月05日 14时24分25秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Person  //抽象类 ---->  提供函数接口/数据类型
{
	public:
		Person(int age=0, bool gender=true):age(age), gender(gender)
	{
		cout << "Person()" <<endl;
	}
		~Person(){
			cout << "~Person()" <<endl;
		}
		//纯虚函数 == >封装接口，不提供实现细节
		virtual void talk() =0;
		
	protected: //封装保护继承的接口
		int age;
		bool gender;

};

class Father : public Person
{

	public:
		Father():Person(30, true)
	{
		cout << "Father()" <<endl;
	}
		~Father()
		{
			cout << "~Father()"<<endl;
		}
		void talk()
		{
			cout << "father:" << this->age << (this->gender==true?"male":"fmale") <<endl;
		}
		void driver()
		{
			cout << "Father:: driver()" << endl;
		}
	private:
};

class Mother : public Person
{
	public:
		Mother():Person(30, false)
	{
		cout << "Mother()" << endl;
	}
		~Mother()
		{
			cout << "~Mother()" <<endl;
		}
		void talk()
		{
			cout << "mother:" << this->age << (this->gender==true?"male":"fmale") <<endl;

		}
		void cook()
		{
			cout << "Mother::cook()" << endl;
		}
	private:

};

class Son :public Father, public Mother
{
	public:
		Son()
		{
			cout << "Son()" <<endl;
		}
		~Son()
		{
			cout << "~Son()" <<endl;
		}
		void talk()
		{
			Father::talk();
			Mother::talk();
		}
	protected:
		//两个接口重写，屏蔽掉father和mother中从person继承过来的接口原型，否则会产生二意性
	private:



};


int main(void)
{
	Father f;
	f.driver();
	f.talk();
	Mother m;
	m.cook();
	m.talk();
	Son s;
	s.talk();
	s.cook();
	s.driver();
	return 0;
}
