/* ==================================================================
 *       Filename:  humanfactory.cpp
 *    Description:  
 *        Created:  2013年11月06日 09时43分39秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string>
using namespace std;

class Human
{
	public:
		Human(string color="yellow"):color(color){
		cout << "Human()"<<endl;
		}
		virtual ~Human()
		{
			cout << "~Human()" <<endl;
		}
		virtual void talk()
		{
			cout << "Human::talk()" <<endl;
			cout << "I am " << this->color << " humanbeing" <<endl; 
		}

	private:
		string color;
};	

enum Color{Yellow, White, Black, Green};


class HumanFactory :public Human
{
		public:
			HumanFactory(Color c)
			{
				if(c == Yellow)
				{
					this->h=new Human("Yellow");
				}else if(c == White)
				{
					this->h=new Human("White");

				}else if(c == Black)
				{
					this->h=new Human("Black");

				}else if(c == Green)
				{
					this->h=new Human("Green");

				}else
				{
					return;
				}
			}
			~HumanFactory(){
				delete this->h;
			}

			Human* making(string color)
			{
				return new Human(color);
			}
			void talk()
			{
				Human::talk();
			}
		private:
			Human*    h;
};


int main(void)
{
	HumanFactory *hf= new HumanFactory(Yellow);
	hf->talk();
	return 0;
}




















