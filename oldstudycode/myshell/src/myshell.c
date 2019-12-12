#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <dirent.h>
int dec_oct(int mode)
{
	if(mode > 7777)
		return -1;
	int a=mode/1000;
	if(a > 7)
		return -1;
	int b=mode/100%10;
	if(b > 7)
		return -1;
	int c=mode/10%10;
	if(c > 7)
		return -1;
	int d=mode%10;
	if(d > 7)
		return -1;
	return a*8*8*8+b*8*8+c*8+d;
}
void show()
{

	struct passwd *pwd;
	char pathname[256];
	getcwd(pathname,256);
	char pathname1[256];
	strcpy(pathname1,pathname);
	char *str1;
	char *str2;
	str1=strtok(pathname,"/");
	str2=strtok(NULL,"/");
	pwd = getpwuid(getuid());
	if(!strcmp(str2,pwd->pw_name))
	{
		int len;
		len=strlen(pwd->pw_name)+6;
		printf("%s:~%s$",pwd->pw_name,pathname1+len);
	}else
	{
		printf("%s:%s$",pwd->pw_name,pathname);
	}
}
void manu()
{
	printf(">>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("                                                \n");
	printf("        WELCOME TO USE MINISHELL SYSTEM         \n");
	printf("                                                \n");
	printf("             DESING BY LIU.WEI                  \n");
	printf("   If you find the bug or have some suggest     \n");
	printf("      Send message to 384439695@qq.com          \n");
	printf("                                                \n");
	printf("                                                \n");
	printf("   Befor you use this system please input       \n");
	printf("   help  to find the instruction                \n");
	printf("                                                \n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");
}
void help()
{
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("                                                    \n");
	printf("              INSTRUCTION HELP                      \n");
	printf("                                                    \n");
	printf("   access: test the file in yur system              \n");
	printf("   unlink: delete a link file                       \n");
	printf("    chmod: change the mode permission of the file   \n");
	printf("     link: creat a link file                        \n");
	printf("       rm: remove a file or dir                     \n");
	printf("    touch: creat a normal file                      \n");
	printf("    chown: change the owner or group                \n");
	printf("    rmdir: remove a empty dir                       \n");
	printf(" truncate: trunc a len of a file                    \n");
	printf("      pwd: get the ralpath                          \n");
	printf("      cat: open a file                              \n");
	printf("       ls: list the file in the dir                 \n");
	printf("       mv: move the file                            \n");
	printf("                                                    \n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<\n");
}
int main(void)
{
	int flag = 0;
	manu();
	while(1)
	{
		show();
		/*char a;
		  if((a=getchar())=='\n')
		  {
		  continue;
		  }*/
		char buffer[256]={};
		fgets(buffer,256,stdin);
		if(!strcmp(buffer,"\n"))
		{
			continue;
		}else
		{

			int len = strlen(buffer);
			buffer[len-1]=0;
			char *argv[256];
			int i=0;
			argv[0]=strtok(buffer," ");
			i++;
			while((argv[i]=strtok(NULL," "))!=NULL)
			{
				i++;
			}
			if(!strcmp(argv[0],"umask"))
			{ 
				flag=1;
				if(argv[1]==NULL)
				{
					mode_t oldmask;
					oldmask = umask(0);
					umask(oldmask);
					printf("%04o\n",oldmask);
				}else
				{
					umask(dec_oct(atoi(argv[1])));
				}
			}
			else if(!strcmp(argv[0],"exit"))
			{
				
				printf(">>>>>>>>>>>>>    system is already exit     <<<<<<<<<<<<\n");
				exit(1);
			}
			else if(!strcmp(argv[0],"clear"))
			{
				flag=1;
				printf("\033[1H\033[2J");
				fflush(stdout);
				//system("clear");
			}
			else if(!strcmp(argv[0],"help"))
			{
				flag=1;
				help();

			}
			else if(!strcmp(argv[0],"cd"))
			{
				flag=1;
				if(argv[1] == NULL)
				{
					char pathname[256];
					getcwd(pathname,256);
					char pathname1[256]="/home/";
					char *str1;
					char *str2;
					str1=strtok(pathname,"/");
					str2=strtok(NULL,"/");
					strcat(pathname1,str2);
					chdir(pathname1);
				}else
				{
					chdir(argv[1]);
				}

			}
			char path[256]="/home/silence/oldstudycode/myshell/bin/";
			char *list[256]=
			{
				"pwd","cat","ls","mv","access","chmod","link",
				"rm","touch","unlink","chown","rmdir","truncate"
			};
			int j=13;
			while(j)
			{
				if(!strcmp(argv[0],list[j-1]))
				{
					flag=1;
					strcat(path,argv[0]);
					pid_t pid;
					if((pid = fork())< 0)
					{
						fprintf(stderr,"fork: %s\n",strerror(errno));
						exit(1);
					}else if(pid == 0)
					{

						if(execv(path,argv)<0)
						{
							fprintf(stderr,"execv: %s\n",strerror(errno));
							exit(1);
						}
						
					}else
					{
						//usleep(9000);
					}
				}
				j--;
			}
			
		    if(flag==0)
		    {
	             printf(">>>Warning: can't find this command please input hlep for more information! <<<\n");
		    }

		}
		                wait(NULL);
	}
	
	
	


	return 0;
}
