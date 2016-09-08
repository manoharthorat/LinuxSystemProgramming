/*    9. Write a program which accept filename and string from user and write that string into file.  */


#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char * argv[])
{
	int fd;
	char buff[512];
	if(argc!=2)
	{
		printf("Usage : ExeName FileName\n");
		return -1;
	}
	fd=open(argv[1],O_WRONLY | O_TRUNC);
	if(fd==-1)
	{
		printf("Unable to Open the file \n");
		return -1;
	}
	else
	{
		printf("File is opened with file descriptor %d\n ",fd);
	}
	printf("Please Enter the String \n");
	scanf("%[^\n]",buff);
	write(fd,buff,strlen(buff));
	close(fd);
return 0;
}
