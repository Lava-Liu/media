/* ==================================================================
 *       Filename:  compfactory.h
 *    Description:  
 *        Created:  2013年11月05日 16时23分06秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __COMPFACTORY_H__
#define __COMPFACTORY_H__
#include <iostream>
using namespace std;
class Engine
{
	public:
		Engine(int v=101)
		{
			this->version = v;
			cout << "Engine()" <<endl;
		}
		~Engine(){}
	private:
		int version;
};
class EngineFactory
{
	public:
		EngineFactory(int max=100, int counter =0);
		~EngineFactory();
		Engine* producing(int version);
		Engine* producing();
		Engine* sale();
		
	private:
		Engine**  e;
		int      maxsize;
		int		 counter;
};

/////////////////////////////////////////////

class Wheel 
{
	public:
		Wheel(int size=100)
		{
			this->size=size;
		}
		~Wheel(){}
		
	private:
		int size;
};

class WheelFactory
{
	public:
		WheelFactory(int maxsize=1000, int counter=0);
		~WheelFactory();
		
		Wheel* producing(int size);
		Wheel* producing();
		Wheel* sale();
	private:
		Wheel**	w;
		int maxsize;
		int counter;

};




#endif
