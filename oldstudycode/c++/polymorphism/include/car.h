/* ==================================================================
 *       Filename:  car.h
 *    Description:  
 *        Created:  2013年11月06日 10时58分56秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __CAR_H__
#define __CAR_H__
#include <iostream>
#include <string>
using namespace std;
class Car
{
	public:
		Car(int x =0, int y = 0, string dir = "North", int xmax = 5, int ymax=5)
		:_x(x), _y(y), _dir(dir), x_maxlen(xmax), y_maxlen(ymax)
		{}
		~Car(){}
		inline bool isOk()
		{
			if(this->_x <= this->x_maxlen && this->_x > 0 || this->_y <= this->y_maxlen && this->_y > 0)
				return true;
			return false;
		}
		void forward()
		{
			if(this->_dir == "East")
			{
				//if(!isOk()) return ;
				if(_x >= x_maxlen) return ;
				this->_x++;

			}else if(this->_dir == "West")
			{
				//if(!isOk()) 
				if(_x <= 0)	return ;
				this->_x--;
			}else if(this->_dir == "North")
			{
				//if(!isOk()) 
				if(_y >= x_maxlen)	return ;
				this->_y++;
			}else if(this->_dir == "South")
			{
				//if(!isOk()) 
				if(_y <= 0)return ;
				this->_y--;
			}else
			{
				return ;
			}
		}
		void turnLeft()
		{
			if(this->_dir == "East")
			{
				this->_dir="North";

			}else if(this->_dir == "West")
			{
				this->_dir="South";
			}else if(this->_dir == "North")
			{
				this->_dir="West";
			}else if(this->_dir == "South")
			{
				this->_dir="East";
			}else
			{
				return ;
			}
			
		}
		void turnRight()
		{
			if(this->_dir == "East")
			{
				this->_dir="South";

			}else if(this->_dir == "West")
			{
				this->_dir="North";
			}else if(this->_dir == "North")
			{
				this->_dir="East";
			}else if(this->_dir == "South")
			{
				this->_dir="West";
			}else
			{
				return ;
			}

		}
		void display()
		{
			cout << "dirent: " << this->_dir << " " <<"pisition: " << this->_x << ":" <<this->_y << endl;
		}

	private:
		int     _x;//x轴坐标
		int     _y;//y轴坐标
		string  _dir;//方向(东，南，西，北)

		//小车的移动限定
		int x_maxlen;
		int y_maxlen;
};





#endif
