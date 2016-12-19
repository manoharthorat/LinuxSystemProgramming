#include<stdio.h>
#include<unistd.h>

int main()
{

	printf("Parent : Process running...\n");
	if(fork()==0)
	{
		execl("./myexe",NULL,NULL);
	}
return 0;
}
