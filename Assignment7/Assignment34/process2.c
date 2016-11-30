#include<stdio.h>
#include<unistd.h>

int main()
{

	pid_t status;
	pid_t pid;
	if(fork()==0)
	{
		printf("This is process 2's child process %d \n",getpid());
		execl("./exec3",NULL,NULL);
	}
	else
	{
		printf("This is process 2's Parent Process %d\n",getpid());
		pid=wait(&status);
		printf("Process 2's child process id %d and status %d \n",pid,status);
	}

return 0;
}
