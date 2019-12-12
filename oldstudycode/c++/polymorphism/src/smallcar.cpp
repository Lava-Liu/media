/* ==================================================================
 *       Filename:  smallcar.cpp
 *    Description:  
 *        Created:  2013年11月06日 10时56分50秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include "car.h"

int main(void)
{
	Car c(3, 3);//走到原点
	c.turnLeft();
	c.forward();
	c.forward();
	c.forward();
	c.display();
	c.turnLeft();
	c.forward();
	c.forward();
	c.forward();
	c.display();
	return 0;
}



