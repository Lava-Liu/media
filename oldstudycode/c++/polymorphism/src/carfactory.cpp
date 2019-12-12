/* ==================================================================
 *       Filename:  carfactory.cpp
 *    Description:  
 *        Created:  2013年11月05日 17时26分11秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include "carfactory.h"
#include <string>

CarFactory::CarFactory(int size, int counter)
	:maxsize(size), counter(counter)
{
	this->car = new Car*[this->maxsize];
	//汽车工厂存在的前提是元器件工厂已经存在
	this->wf = new WheelFactory();
	this->ef = new EngineFactory();
	cout << "汽车工厂成立~..." <<endl;
}
Car* CarFactory::making()
{
	if(counter >= maxsize)
	{
		return NULL;
	}
	this->wf->producing();
	this->wf->producing();
	this->wf->producing();
	this->wf->producing();
	this->ef->producing();
	car[counter] = new Car();
	return car[counter++];
	
	
	
	
}
Car* CarFactory::making(string name)
{
	if(counter >= maxsize)
		return NULL;
	this->wf->producing();
	this->wf->producing();
	this->wf->producing();
	this->wf->producing();
	this->ef->producing();
	car[counter] = new Car(name);
	return car[counter++];
	
}
Car* CarFactory::sale()
{
	if(counter <= 0)
		return NULL;
	return this->car[--counter];
}
CarFactory::~CarFactory()
{
	delete this->wf;
	delete this->ef;
	delete []this->car;
}
