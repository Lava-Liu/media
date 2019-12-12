
#include "sum.h"

//int a;

int sum(int start, int end)
{
	int i = start;
	int result = 0;
	for(i=start;i <= end; i++)
	{
		result = result + i;
	}
	return result;
}
