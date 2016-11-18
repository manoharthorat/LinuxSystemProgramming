#include<stdio.h>
#include<unistd.h>

int main()
{
	int no;
	printf("A %d\n",getpid());
	
	no=fork();
	if(no!=0)
	{
		printf("B %d\n",getpid());
	}
	else
	{
		printf("C %d\n",getpid());
	}
	printf("D %d\n",getpid());

return 0;
}
