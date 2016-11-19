#include<stdio.h>
#include<unistd.h>
int main(int argc, char * argv[])
{
	printf("Inside Executable file \n");
	printf("Commandline %s %s\n",argv[0],argv[1]);

return 0;
}
