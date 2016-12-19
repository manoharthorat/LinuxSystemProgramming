#include<stdio.h>
#include<sys/resource.h>

int main()
{
	int ret;
	int pid=0;
	pid=getpid();
	ret=getpriority(PRIO_PROCESS,pid);
	printf("Process Priority is %d \n",ret);
	return 0;
}
