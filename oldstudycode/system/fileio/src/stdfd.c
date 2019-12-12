#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//文件描述符
//file descriptor

int main(void)
{
	//std fd
    printf("%d\n",STDIN_FILENO);
    printf("%d\n",STDOUT_FILENO);
    printf("%d\n",STDERR_FILENO);

	fprintf(stdout,"stdout message!");
	
	fflush(stdout);
	char buffer[]= "FILENO message!";
	write(STDOUT_FILENO,buffer,strlen(buffer));
	pause();//暂停当前进程
	return 0;
}
