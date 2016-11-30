#include<stdio.h>
#include<unistd.h>
int main(int argc, char * argv[])
{
	printf("Inside Executable File \n");
	sleep(5);
	printf("Sleep of child process completes \n");
		
return 0;
}
