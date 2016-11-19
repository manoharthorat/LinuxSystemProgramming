#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork()==0)
	{
		printf("Before Process Creation %d \n",getpid());
		execl("./myexe1","A","B",NULL);
	}
	else
	{
		printf("Inside Parent Process %d \n",getpid());
	}

return 0;
}
