/*34. Write a program which create three level process hierarchy whwre process 1 creates process 2 and it internally creates process 3*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid_t status;
	if(fork()==0)
	{
		printf("This is process 1's child process %d \n",getpid());
		execl("./exec2",NULL,NULL);
	}
	else
	{
		printf("This is process 1's parent process %d \n ",getpid());
		pid=wait(&status);
		printf("This is process1's child process id %d and status is %d ",pid,status);
		
	}

return 0;
}
