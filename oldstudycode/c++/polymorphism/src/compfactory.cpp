/* ==================================================================
 *       Filename:  compfactory.cpp
 *    Description:  
 *        Created:  2013年11月05日 16时38分52秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include "compfactory.h"
#include <string>
using namespace std;

EngineFactory::EngineFactory(int max, int counter)
	:maxsize(max), counter(counter)
{
	//工厂最多可生产maxsize个发动机
	this->e =new Engine*[this->maxsize];
	cout << "发动机工厂建立..." <<endl;
}

Engine* EngineFactory::producing(int verson)
{
	if(counter>=maxsize)
		return NULL;
	e[counter] = new Engine(verson);
	return e[counter++];
}
Engine* EngineFactory::producing()
{
	if(counter>=maxsize)
		return NULL;
	e[counter] = new Engine();
	return e[counter++];
}
Engine* EngineFactory::sale()
{	if(counter <=0)
	return NULL;
	return e[--counter];
}
EngineFactory::~EngineFactory()
{
	delete []this->e;
}

//////////////////////

WheelFactory::WheelFactory(int maxsize, int counter)
	:maxsize(maxsize), counter(counter)
{
	cout <<"轮胎厂建立..." <<endl;
	this->w = new Wheel*[this->maxsize];

}
Wheel* WheelFactory::producing(int size)
{
	if(counter>=maxsize)
		return NULL;
	cout << "Wheel producing(int )" <<endl;
	w[counter] = new Wheel(size);
	return w[counter++];
}

Wheel* WheelFactory::producing()
{
	if(counter>=maxsize)
		return NULL;
	cout <<"Wheel producing()" <<endl;
	w[counter] = new Wheel();
	return w[counter++];
}
//出售一个轮胎
Wheel* WheelFactory::sale()
{
	if(counter<=0)
		return NULL;
	cout << "Wheel sale()" <<endl;
	return w[--counter];
}
WheelFactory::~WheelFactory()
{
	delete []this->w;
}


