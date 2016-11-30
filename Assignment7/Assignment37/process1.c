#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("This is parent process %d\n",getpid());
	
	if(fork()==0)
	{
		printf("This is child process %d \n",getpid());
		execl("./deamon",NULL,NULL);
	}	
	

return 0;
}
