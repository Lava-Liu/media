/* ==================================================================
 *       Filename:  binary.cpp
 *    Description:  
 *        Created:  2013年11月07日 10时08分53秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;
template <typename E> class Operator;

template <typename T>
class Binary
{
	public:
		Binary(T n1=0, T n2=0, char ops='#')
		{
			this->num1=n1;
			this->num2=n2;
			this->ops=ops;
		}
		~Binary(){}
		
		void setOps(char ops){this->ops=ops;}
		void setNum1(T n){this->num1 = n;}
		void setNum2(T n){this->num2 = n;}
		char getOps()const{return this->ops;}
		T getNum1()const{return this->num1;}
		T getNum2()const{return this->num2;}
		friend class Operator<T>;
		
	private:
		char ops;
		T  num1;
		T  num2;


};

template <typename T>
class Operator 
{
	public:
		Operator(){}
		~Operator(){}
		
		void setResult(T result);
		T getResult()const;
		
		template <typename E>
		void add(Binary <E>&);
		template <typename E>
		void sub(Binary <E>&);
		template <typename E>
		void mul(Binary <E>&);
		template <typename E>
		void div(Binary <E>&);
	
	private:
		T result;

};
template <typename T>
void Operator<T>::setResult(T result)
{
	this->result =result;
}

template <typename T>
T Operator<T>::getResult()const{
	return this->result;
}

template <typename T>
template <typename E>
void Operator<T>::add(Binary<E> &b)
{
	this->result=b.num1+b.num2;
}
template <typename T>
template <typename E>
void Operator<T>::sub(Binary<E> &b)
{
	this->result=b.num1-b.num2;
}
template <typename T>
template <typename E>
void Operator<T>::mul(Binary<E> &b)
{
	this->result=b.num1*b.num2;
}
template <typename T>
template <typename E>
void Operator<T>::div(Binary<E> &b)
{
	if(0 == b.num2) throw string("除数为零");
	this->result=(b.num1)/(b.num2);
}




int main(void)
{

	try{
	Binary<double>b(10, 20);
	Operator<double>op;
	op.add(b);
	cout << op.getResult() <<endl;
	op.sub(b);
	cout << op.getResult() <<endl;
	}catch(string &s)
	{
		cout << s << endl;
	}
	return 0;
}
