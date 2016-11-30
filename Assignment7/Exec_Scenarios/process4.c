#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Parent Process %d \n",getpid());
	if(fork()==0)
	{
		printf("Child Process %d \n",getpid());
	}
	else
	{
		execl("./exec2","A","B",NULL);
		printf("Parent Process %d\n",getpid());
	}
	printf("Parent COed ????%d\n",getpid());


return 0;
}
