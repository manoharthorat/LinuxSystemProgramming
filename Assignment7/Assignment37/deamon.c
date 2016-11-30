#include<stdio.h>
#include<unistd.h>

int main()
{
	setsid();
	printf("Thiss is deamon process %d \n",getpid());
	sleep(3);

return 0;
}
