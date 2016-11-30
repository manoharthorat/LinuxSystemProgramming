#include<stdio.h>
#include<unistd.h>

int main()
{

	pid_t status;
	pid_t pid;
	if(fork()==0)
	{
		printf("Before Process Creation %d \n",getpid());
		sleep(10);
		printf("Sleep Complete \n");
	}
	else
	{
		printf("Inside Parent process %d \n",getpid());
		pid=wait(&status);
		printf("Child Process having a pid %d terminaes with exit status %d \n",pid,status);
		printf("Execution of parent process completes \n");
	}
return 0;
}
