/* 26. Write a program which create hole of size 1kb at the end of file.*/
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	int fd;
	char buff[50]={' '};
	if(argc!=2)
	{
		printf("Usage : ExeName FileName\n");	
		return 0;
	}
	fd=open(argv[1],O_WRONLY);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		return -1;
	}
	lseek(fd,1024,SEEK_END);
	
	write(fd,buff,1);
	
	close(fd);


	return 0;
}
