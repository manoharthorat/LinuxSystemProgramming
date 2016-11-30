#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handler(int);

int main(int argc, char * argv[])
{
	signal(SIGKILL,handler);
	printf("Inside Executable file \n");
	for(;;)
		pause();

return 0;
}

void handler(int no)
{
	printf("Signal is arrived \n");
}
