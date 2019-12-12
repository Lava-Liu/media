/* ==================================================================
 *       Filename:  humanfactory1.cpp
 *    Description:  
 *        Created:  2013年11月06日 10时10分32秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <iostream>
#include <string>
using namespace std;

enum Color{Yellow, White, Black, Green};

class Human
{
	public:
		Human(Color col = Yellow):color(col){}
		virtual ~Human(){}
	
		virtual void talk() = 0;
		Color gerColor()const{
			return this->color;
		}

	private:
		Color color;
};


class YellowHuman :public Human
{
	public:
		YellowHuman():Human(Yellow){}
		~YellowHuman(){}
		void talk()
		{
			cout << "我是黄种人！！！！！" <<endl;
		}
	private:
		
};

class BlackHuman :public Human
{
	public:
		BlackHuman():Human(Black){}
		~BlackHuman(){}
		void talk()
		{
			cout << "我是黑人~~~" <<endl;
		}
};
class WhiteHuman :public Human
{
	public:
		WhiteHuman():Human(White){}
		~WhiteHuman(){}
		void talk()
		{
			cout << "我是白人~~~" <<endl;
		}
};
class GreenHuman :public Human
{
	public:
		GreenHuman():Human(Green){}
		~GreenHuman(){}
		void talk()
		{
			cout << "我是绿巨人~~~" <<endl;
		}
};

class HumanFactory
{
	public:
		HumanFactory(){
		
		}
		~HumanFactory(){}
		//封装造人的细节
		Human *making(Human* h)
		{
			return h;
		}

	private:
		Human  *h;
};







int main(void)
{
	HumanFactory *hf = new HumanFactory;
	Human *h = hf->making(new BlackHuman);
	h->talk();
	Human *h1 = hf->making(new WhiteHuman);
	h1->talk();
	Human *h2 = hf->making(new GreenHuman);
	h2->talk();
	Human *h3 = hf->making(new YellowHuman);
	h3->talk();
	return 0;
}



