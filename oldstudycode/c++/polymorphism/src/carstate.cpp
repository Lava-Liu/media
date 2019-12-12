/* ==================================================================
 *       Filename:  carstate.cpp
 *    Description:  
 *        Created:  2013年11月06日 14时16分02秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include "carstate.h"

int main(void)
{
	Car *c = new Car;
	c->display();
 try{
	c->turnLeft();
	c->forward();
	c->forward();
	c->forward();
	c->forward();
	c->display();

	c->turnLeft();
	c->forward();
	c->forward();
	c->forward();
	c->forward();
	c->display();
	c->forward();
	c->forward();
 }catch(Car::RunException & e)
 {
	 cout << e.what() <<endl;
 }
	return 0;
	
}
