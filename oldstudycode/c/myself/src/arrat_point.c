#include <stdio.h>

void out_array(char *(*out_array)[4])
{	
	int i;
	int j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%s, ",*(*(out_array+i)+j));
		}
		printf("\n");
	}

}



int main(void)

{
	char *array[3][4]= {
		{"1","zhangsan","22","sdf"},
		{"2","lisi","24","sd"},
		{"3","wanger","26","gasdf"}
	};
	out_array(array);
}
