/* 5. Write a program which accept file name from user and open that file. */

#include<stdio.h>
#include<fcntl.h>

int main(int argc,char * argv[])
{

	int fd;
	if(argc!=2)
	{
		printf("Usage : ExeName FileName\n");
		return -1;
	}

	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to Open the file \n");
		return -1;
	}
	else
	{
		printf("file is opened with file Descriptor %d\n ",fd);
	}
	
return 0;
}
