/*33.Write a program in which parent process waits till its child process terminates*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t status;
	pid_t pid;
	if(fork()==0)
	{
		printf("This is child process %d\n",getpid());
		execl("./exec",NULL,NULL);
		
	}	
	else
	{
		printf("This is parent process %d \n",getpid());
		pid=wait(&status);
		printf("Child Process having a pid %d with status %d \n",pid,status);
		printf("Execution of parent process completed \n");
	}
return 0;
}
