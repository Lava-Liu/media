/* ==================================================================
 *       Filename:  mul_inher.cpp
 *    Description:  
 *        Created:  2013年11月05日 13时39分07秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Adt
{
	public:
		Adt(){
		cout << "Adt()" <<endl;
		}
		virtual ~Adt(){
			cout <<"~Adt()" <<endl;
		}
		virtual void show( )=0;
		/*{
			cout << "Adt::show()" <<endl;
		}*/
	private:

};


class A :public Adt
{
	public:
		A(int data=10):a_val(data){
			cout << "A()" <<endl;
		}
		~A(){
			cout << "~A()" <<endl;
		}
		/*void show()
		{
			cout << "show:A()" <<this->a_val<<endl;
		}*/
	private:
		int a_val;
};
class B :public Adt
{
	public:
		B(int data=20):b_val(data){
		cout << "B()" <<endl;
		}
		~B(){
		cout << "~B()" <<endl;
		}
		/*void show()
		{
			cout << "show::B()" <<this->b_val<<endl;
		}*/
	private:
		int b_val;
};
class C :public A, public B
{
	public:
		C(int data = 30):c_val(data){
		cout << "C()" <<endl;
		}
		~C(){
		cout << "~C()" <<endl;
		}
		void show()
		{
			
			cout << "C::showC()" <<this->c_val<<endl;
			//A::show();
			//B::show();
		}
	private:
		int c_val;
};




int main(void)
{
	//C c;
	//c.show();
	//c.showB();
	//c.showA();
	
	A *a = new C();
	a->show();
	delete a;
	//Adt adt;




	return 0;
}
