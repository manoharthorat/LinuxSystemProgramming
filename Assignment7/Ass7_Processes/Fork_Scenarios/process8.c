#include<stdio.h>
#include<unistd.h>

int main()
{
	int no;
	printf("Parent %d \n",getpid());
	no=fork();
	if(no!=0)
	{
		printf("Parent PID  %d \n",no);
	}
return 0;
}
