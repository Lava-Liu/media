/* ==================================================================
 *       Filename:  carfactory.h
 *    Description:  
 *        Created:  2013年11月05日 16时09分51秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __CARFACTORY_H__
#define __CARFACTORY_H__
#include "compfactory.h"
class Car
{
	public:
		Car(string name = "Module", int wheelNumber =4, int engineNumber=1)
		{
			this->name = name;
			this->wheelNumber=wheelNumber;
			this->engineNumber=engineNumber;
			cout << "新车" << this->name << "诞生"<<endl;
		}
		~Car(){}
		void setName(string name)
		{
			this->name=name;
		}
		void setWheelNumber(int num)
		{
			this->wheelNumber=num;
		}
		void setEngineNumber(int num)
		{
			this->engineNumber=num;
		}
		void getWheelNumber()const{
			this->wheelNumber;
		}
	private:
		string name;
		int	   wheelNumber;
		int    engineNumber;
};



class CarFactory
{
	public:
		CarFactory(int maxsize=10, int counter=0);
		~CarFactory();


		Car* making();
		Car* making(string name);
		Car* sale();
	private:
		Car            **car;
		int maxsize;
		int counter;
		WheelFactory   *wf;
		EngineFactory  *ef;

};






#endif
