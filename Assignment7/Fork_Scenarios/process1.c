#include<stdio.h>
#include<unistd.h>

int main()
{
	fork();
	printf("A");
	return 0;
}

/*
	output A A
*/
