#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork()==0)
	{
		printf("Before Process creation %d \n",getpid());
		execl("./myexe",NULL,NULL);
		printf("After Process Creation %d \n",getpid());
	}
	else
	{
		printf("Inside Parent Process%d \n",getpid());
	}
return 0;
}
