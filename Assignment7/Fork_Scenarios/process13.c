#include<stdio.h>
#include<unistd.h>

int main()
{
	int i=10;
	printf("Parent i= %d pid %d\n ",i,getpid());
	if(fork()==0)
	{
		i++;
		printf("Child i=%d  pid %d \n",i,getpid());
	}
	else
	{
		i++;
		printf("Parent i=%d pid %d\n",i,getpid());
	}
return 0;
}
