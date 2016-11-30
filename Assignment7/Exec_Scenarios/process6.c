#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork()==0)
	{
		printf("Before process creation \n");
		execl("./exec3",NULL,NULL);
	}	
	else
	{
		printf("Inside parent proces \n");	
	}
	
return 0;
}
