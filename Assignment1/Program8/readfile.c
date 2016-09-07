/* 8. Write a program which accept file name from user and read whole file.  */

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	int fd;
	char buff[512];
	int ret=0;
	if(argc!=2)
	{
		printf("Usage : ExeName FileName \n");
		return -1;
	}

	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		return -1;
	}	
	else
	{
		printf("File is opened with file descriptor %d \n",fd);
	}
	while(read(fd,buff,sizeof(buff))!=0)
	{
		printf("%s ",buff);
	}
	
return 0;
}
