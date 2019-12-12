#include <stdio.h>
int run(int year)
{
	if(year%4==0 && year%100!=0 || year%400==0)
	{return 29;}
	else
		return 28;


}
int main(void)
{
	int year;
	int month;
	int day;
	printf("请输入一个年份和月份：");
	scanf("%d/%d",&year,&month);
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day = 31;
		break;
			
		case 4:
		case 6:
		case 9:
		case 11:
			
				day =30;
				break;
			
		case 2:
			
				day=run(year);
				break;
		default :
			printf("error!\n");
		    return -1;	
		
		
		}
	printf("%d年%d月有%d天\n",year,month,day);
		return 0;
	




}
