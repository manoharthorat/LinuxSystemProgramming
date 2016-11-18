#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Process ID %d \n",getpid());
	printf("Parent Process id %d\n",getppid());
	if(fork()==0)
	{
		printf("Child Process id %d \n",getpid());
		printf("Parent process id %d\n",getppid());
	}	
	else
	{
		printf("Parent Process id %d\n",getpid());
		printf("Parent Process id %d \n",getppid());
	}

	
return 0;
}
