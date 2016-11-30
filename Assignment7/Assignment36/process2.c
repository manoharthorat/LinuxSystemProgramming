#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("This is Process 2 %d \n",getpid());
	sleep(3);
return 0;
}
