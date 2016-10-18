/* 9. 	Write a program which accept file name from user and offset, remove all the data from that offset.*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	int ret;
	
	if(argc!=3)
	{
		printf("Usage : ExeName FileName\n");
		return -1;
	}
	
	ret=truncate(argv[1],atoi(argv[2]));
	if(ret==-1)
	{
		printf("Unable to truncate the file \n");
		return -1;
	}

return 0;
}


