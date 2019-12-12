#include <stdio.h>

int main(void)
{
	char c;
	int digit = 0;
	int letter = 0;
	int space = 0;
	int other = 0;
	while((c=getchar())!='\n')
	{
		if(c>='0' && c<='9')
		{
			digit++;
		}else if((c>='a' && c <= 'z') ||( c>='A' && c<= 'Z'))
		{
			letter++;
		}else if(c == ' ')
		{
			space++;
		}else
		{
			other++;
		}

		

	
	
	}
	printf("digit=%d, letter=%d, space=%d, other=%d",digit,letter,space,other);









return 0;
}
