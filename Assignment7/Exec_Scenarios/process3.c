#include<stdio.h>
#include<unistd.h>

int main()
{
	printf(" PP %d \n",getpid());
	if(fork()==0)
	{
		printf("Before Process Creation %d\n",getpid());
		execl("./exec2","aString","bString",NULL);
	}
	else
	{
		printf("Inside Parent Process\n");
	}
return 0;
}
