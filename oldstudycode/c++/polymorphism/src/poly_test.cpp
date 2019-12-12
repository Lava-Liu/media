/* ==================================================================
 *       Filename:  poly_test.cpp
 *    Description:  
 *        Created:  2013年11月05日 10时36分49秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
using namespace std;

class Animal
{
	public:
		Animal()
		{
			cout << "Animal()" <<endl;
		}
		~Animal()
		{
			cout << "~Animal()" <<endl;
		}
		virtual void run()
		{
			cout << "Animal::run()"<<endl;
		}
	private:
		int data;
};
class Cat :public Animal
{
	public:
		Cat()
		{
			cout << "Cat()" <<endl;
		}
		~Cat()
		{
			cout << "~Cat()"<<endl;
		}
		void run()
		{
			cout << "Cat::run()" <<endl;
		}
	private:
		int data;
};

class BlackCat : public Cat
{
	public:
		BlackCat()
		{
			cout << "BlackCat()" <<endl;
		}
		~BlackCat()
		{
			cout << "~BlackCat()" <<endl;
		}
		void run()
		{
			cout << "BlackCat::run()" <<endl;
		}
	private:
		int data;
};


class Dog :public Animal
{
	public:
		Dog()
		{
			cout << "Dog()" <<endl;
		}
		~Dog()
		{
			cout << "~Dog()" <<endl;
		}
		virtual void run()
		{
			cout << "Dog::run()" <<endl;
		}
	private:
		int data;
};
void display(Animal *a)
{
	cout << *(int *)(a) << endl;
	a->run();
}
int main(void)
{
	//Animal *a = new Animal();
	Animal *a = new Cat();
	Animal *b = new Dog();
	//Cat *a = new Animal();
	a->run();
	b->run();
	


	//display(new Cat);
	//display(new Dog);


	delete a;
	delete b;

	cout << "----------------------" <<endl;
	Cat *bc = new BlackCat();
	bc->run();

	return 0;
}






























