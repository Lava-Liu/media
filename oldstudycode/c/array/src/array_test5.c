#include <stdio.h>
void out(int *p,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("p[%d][%d]%d\t",i,j,*(p+(i*col+j)));
		}
		printf("\n");
	}
}
void out1(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(p+i));
	}
	printf("\n");
}
void out2(int (*p)[4],int row) 
//void out2(int p[][4],int row)
{
	int i;
	int j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<4;j++)
			//printf("a[%d][%d]=%d\t",i,j,p[i][j]);
			printf("a[%d][%d]=%d\t",i,j,*((int*)(p+i)+j));
	}
	printf("\n");
}
int main(void)
{
	int a[3][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int b[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int c[][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    out((int*)a,3,4);
	out1((int*)a,12);
	out2(a,3);
	
	return 0;
}
