#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
void fun()
{
	printf("in fun\n");
}
int main(void)
{
	auto int autovar = 1;
	static int static_var =2;
	int *heap_var = (int * )malloc(sizeof(int));
	*heap_var=3;
	pid_t pid = fork();
	if(pid < 0)
	{
		fprintf(stderr,"pdf: %s \n",strerror(errno));
		exit(1);
	}else if(pid > 0)
	{
		autovar = 4;
		*heap_var = 5;
		static_var = 6;
		printf("parent,auto:%p------%d,heap:%p-----%d,static:%p--- %d\n",&autovar,autovar,heap_var,*heap_var,&static_var,static_var);
		fun();
	}else
	{
		sleep(5);
		printf("child,auto:%p------%d,heap:%p-----%d,static:%p--- %d\n",&autovar,autovar,heap_var,*heap_var,&static_var,static_var);
		fun();

	}
	pause();
	return 0;
}
