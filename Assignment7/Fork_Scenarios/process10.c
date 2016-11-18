#include<stdio.h>
#include<unistd.h>

int main()
{

	printf("A %d\n",getpid());
	if(fork()==0)
	{
		printf("B %d\n",getpid());
	}
	else
	{
		printf("C %d\n",getpid());
	}
	
return 0;
}
