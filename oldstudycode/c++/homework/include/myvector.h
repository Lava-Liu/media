/* ==================================================================
 *       Filename:  myvector.h
 *    Description:  
 *        Created:  2013年11月08日 14时34分52秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司 (http://www.briup.com)
 * ==================================================================*/
#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__
#include <iostream>
using namespace std;

template <typename T>
class Myvector
{

	public:
		Myvector(int counter=0):counter(counter){}
		~Myvector(){}

		void push_back(T a);
		T front()
		{
			return array[0];
		}
		T back()
		{
			return array[counter-1];
		}


	private:
		T *array;
		int counter;

};



template <typename T>
void Myvector<T>::push_back(T a)
{
	T *old = this->array;
	this->array=new T[counter+1];
	if(counter >= 1)
	{
		for(int i=0;i<counter;i++)
		{
			array[i] = old[i];
		}
	}
	array[counter]=a;
	if(counter >= 1)
	{
		delete [] old;
	}
	counter++;
}


#endif
