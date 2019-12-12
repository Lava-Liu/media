/* ==================================================================
 *       Filename:  carstate.h
 *    Description:  
 *        Created:  2013年11月06日 11时38分27秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __CARSTATE_H__
#define __CARSTATE_H__
#include <iostream>
#include <string.h>
using namespace std;
class Car;
class State
{
	public:
		virtual void forward(Car*)=0;
		virtual void turnLeft(Car*)=0;
		virtual void turnRight(Car*)=0;
		virtual void display()=0;
};

class Car
{
	 public:
		 Car(int x=5,int y=5,string dir = "North")
			 :_x(x),_y(y), _dir(dir)
		 {
			 this->cur_state = new North;
		 }
		 ~Car(){}

		class East :public State
	{
		public:
			East(){}
			~East(){}
		virtual void forward(Car* car)
		{
			if(car->getX() >= 5)
				throw RunException("x > 5");
			car->setX(car->getX()+1);
		}
		virtual void turnLeft(Car* car)
		{
			State* t = car->cur_state;
			car->setState(new North);
			delete t;
		}
		virtual void turnRight(Car* car)
		{
			State* t = car->cur_state;
			car->setState(new South);
			delete t;

		}
		virtual void display()
		{
			cout << "East: " << endl;
		}
	};
		class West :public State
	{
		public:
			West(){}
			~West(){}
		virtual void forward(Car* car)
		{
			if(car->getX() <= 0)
				throw RunException("x <= 0");
			car->setX(car->getX()-1);
		}
		virtual void turnLeft(Car* car)
		{
			State* t = car->cur_state;
			car->setState(new South);
			delete t;
		}
		virtual void turnRight(Car* car)
		{
			State* t = car->cur_state;
			car->setState(new North);
			delete t;

		}
		virtual void display()
		{
			cout << "West: " << endl;
		}


	};
		class North:public State
	{
		public:
			North(){}
			~North(){}
		virtual void forward(Car* car)
		{
			if(car->getY() >= 5)
				throw RunException("y > 5");
			car->setY(car->getY()+1);
		}
		virtual void turnLeft(Car* car)
		{
			State* t = car->cur_state;
			car->setState(new West);
			delete t;
		}
		virtual void turnRight(Car* car)
		{
			State* t = car->cur_state;
			car->setState(new East);
			delete t;

		}
		virtual void display()
		{
			cout << "North: " << endl;
		}


	};
		class South:public State
	{
		public:
			South(){}
			~South(){}
		virtual void forward(Car* car)
		{
			if(car->getY() <= 0)
				throw RunException("y > 5");
			car->setY(car->getY()-1);
		}
		virtual void turnLeft(Car* car)
		{
			State* t = car->cur_state;
			car->setState(new East);
			delete t;
		}
		virtual void turnRight(Car* car)
		{
			State* t = car->cur_state;
			car->setState(new West);
			delete t;

		}
		virtual void display()
		{
			cout << "North: " << endl;
		}


	};
		//异常类
		class RunException
		{
			public:
				RunException(string msg = "Unkonw Type"){
					
					this->_msg=msg;
					cout<<"Exception Happend: " <<endl;
				}
				~RunException(){}
				virtual string  what()
				{
					return this->_msg;
				}
			private:
				string _msg;
		};

	void setX(int x){this->_x=x;}
	void setY(int y){this->_y=y;}
	void setDir(string dir){this->_dir=dir;}
	void setState(State *s){this->cur_state = s;};
	

	int getX()const{return this->_x;}
	int getY()const{return this-> _y;}
	string  getDir()const{return this->_dir;}
	State*  gerState()const{return this->cur_state;}
	void forward()
	{
		this->cur_state->forward(this);
	}
	void turnLeft()
	{
		this->cur_state->turnLeft(this);
	}
	void turnRight()
	{
		this->cur_state->turnRight(this);
	}


	void display()
	{
		cur_state->display();
		cout <<  "\t" << "Position:< " << this->_x << ":" << this->_y << ">" << endl;
	}
	 private:
		 int    _x;
		 int    _y;
		 string _dir;
		 State *cur_state;
};




#endif 
