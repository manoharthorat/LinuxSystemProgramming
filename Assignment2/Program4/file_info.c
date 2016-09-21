/* 4. Write a program which accept file name from user and print all information about that file. */

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
	int fd;
	struct stat fstat;
	int ret;
	if(argc !=2)
	{
		printf("Usage : ExeName FileName\n");
		return -1;
	}
	
	
	

return 0;
}
