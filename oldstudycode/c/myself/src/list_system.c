#include "double_list.h"
#include <stdio.h>


int main(void)
{
	FILE *fp = fopen("data.txt","rb");
	int num;
	list *l = creat_list();
	while(!feof(fp) && fread(&num,sizeof(int),1,fp))
	{   
	    //fread(&num,sizeof(int),1,fp);
		
		push_front(l,&num);
	}
	printf("%d\n",size(l));
	//printf("Please input a number:");
	//scanf("%d",&num);
	num = 1;
	push_front(l,&num);
	printf("%d\n",size(l));
    
	query(l);
	data(l);
	destroy_list(l);
	fclose(fp);
	return 0;
}
