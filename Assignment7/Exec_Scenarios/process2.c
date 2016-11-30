#include<stdio.h>
#include<unistd.h>

int main()
{	
	printf("Before Process creation This is parent process %d \n",getpid());
	
	if(fork()==0)
	{
		printf("This is child process %d\n",getpid());
		execl("./exec",NULL,NULL);
		printf("After Execute Exec Exe %d\n",getpid());	
	}
	else
	{	
		printf("This is Parent Process %d \n",getpid());
	}
	printf("\nGet Pid%d\n ",getpid());
	
return 0;

}
