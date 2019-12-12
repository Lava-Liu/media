#include <stdio.h>
typedef struct date
{
	int year;
	int month;
	int day;
}date;
int main(void)
{
	date d={2012,12,20};
	char buffer[100] = {'\0'};
	sprintf(buffer,"%d年-%d月-%d日",d.year,d.month,d.day);
	printf("%s\n",buffer);
	return 0;
}
