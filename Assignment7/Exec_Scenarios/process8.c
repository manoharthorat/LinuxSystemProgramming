#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		execl("./exec4",NULL,NULL);
	}
	else
	{
		printf("Inside Parent Process %d\n",pid);
		kill(pid,SIGKILL);

	}
return 0;
}
	
