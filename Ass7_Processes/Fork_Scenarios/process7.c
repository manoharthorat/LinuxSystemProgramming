#include<stdio.h>
#include<unistd.h>

int main()
{
	int no;
	printf("A\n");
	
	no = fork();
	if(no == 0)
	{
		printf("C\n");
	}	
	printf("B\n");		
	return 0;
}

