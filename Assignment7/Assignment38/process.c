#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("Parent Process Running ....\n");
	if(fork()==0)
	{
		execl("./FileNameWrite",NULL,NULL);

	}
return 0;
}
