#include <stdio.h>
int binary_search(int a[],int n, int data)
{
	int low=0;
	int hight=n-1;
	int mid;
	while(low <= hight )
	{
		mid = (low + hight)/2;
		if(a[mid] == data)
		{
		printf("该元素的下标为%d\n",mid);
		return 1;
		}
		else if(a[mid] < data)
			low = mid +1;
		else 
			hight =mid -1;

	}
	printf("NO't find!");
	return 0;
}
int main(void)
{

	int a[] = {3,7,21,77,89,111,132,200};
   int n =8; 
	binary_search(a,n,111);
	return 0;
}
