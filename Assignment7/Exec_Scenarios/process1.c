#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Our Process \n");
	if(fork()==0)
	{
		execl("./exec",NULL,NULL);
	}

return 0;
}
