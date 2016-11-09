#include<stdio.h>
#include<unistd.h>

int main()
{

	printf("A\n");
	if(fork()==0)
	{
		printf("B\n");
	}
	printf("C\n");
return 0;
}
