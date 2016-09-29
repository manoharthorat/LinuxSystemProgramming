/* 19. Write a program which accept file name and position from user and read 20 bytes from that position. */

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	int fd;
	char buff[256];
	int ret=0;
	
	
	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName \n");
		return -1;
	}
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to create the File \n");
		return -1;
	}
	
	lseek(fd,atoi(argv[2]),SEEK_SET);
	
	ret=read(fd,buff,20);
	printf("%s",buff);	
	close(fd);
	
return 0;
}

		
	
	
