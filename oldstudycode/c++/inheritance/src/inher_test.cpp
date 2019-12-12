/* ==================================================================
 *       Filename:  inher_test.cpp
 *    Description:  
 *        Created:  2013年11月04日 16时26分53秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;



class Base
{
	public:
          Base(int data = 0){
			cout << "base()" <<endl;
			this->data=data;
		}
		~Base(){
			cout << "~base()" << endl;
		}
		int getData()const{
			return this->data;
		}
		void setData(int data)
		{
			this->data = data;
		}
	//private:
	    protected:
		int data;
};
class Derived : protected Base
{
	public:
		Derived(int m_data=0){
		cout << "Derived()" << endl;
		this->m_data = m_data;
		}
		~Derived(){
		cout << "~Derived()"<<endl;
		}
		int getMData()const{
			return this->m_data;
		}
		int setMData(int data)
		{
			this->m_data = data;
		}

		void show()
		{
			cout << "Base: " << data  << endl;
			cout << "Derived"<< this->m_data <<endl;
		}
	private:
		int m_data;
};


int main(void)
{
	//Base b(111);
	//b.data = 125;
	//cout << b.getData() << endl;
	//cout << "------------------------------" << endl;
	Derived d(100);
	cout << d.getMData() << endl;
	d.show();
	d.setData(555);
	d.show();
	return 0;
}
