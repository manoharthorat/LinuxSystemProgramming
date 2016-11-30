#include<stdio.h>
#include<unistd.h>
int main()
{
	if(fork()==0)	
	{
		printf("Before Process Creation \n");
		execl("./deamon",NULL,NULL);
	}
	else
	{
		printf("Inside Parent Process \n");	
		exit(0);
	}
return 0;
}
