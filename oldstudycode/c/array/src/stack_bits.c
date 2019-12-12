#include "stack.h"
#include <stdio.h>

void stack_out(int data)
	  {
		       int n=0;
		        while(n<32)
			         {
					         push((data&1));
					         data= (data >> 1);
					            n++;
					         }
		         while(size()!=0)
				      {
					           printf("%d",pop());
					        }
				 printf("\n");
			      
			   }
void array_bits(int data)
{
	int i;
	for(;;)
	{
		if(data == 0)
		break;
		push(data%2);
		data=data/2;

	}
	/*while(size()<31)
	{
		push(0);
	}
	while(size()!=0)
	{
		printf("%d",pop());

	}*/
	out_stack(32);
	printf("\n");
}






int main(void)
{
	int a;
	printf("Please input a number:");
	scanf("%d",&a);
	stack_out(a);
    array_bits(a);
}	

