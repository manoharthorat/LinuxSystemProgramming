/*  7. Write a program which accept file name and read first 5 characters from it.  */

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{

	int fd;
	int ret=0;
	char buff[5];
	if(argc!=2)
	{
		printf("Usage: ExeName FileName \n");
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
		printf("File is Opened with File Descriptor %d \n",fd);
	}

	ret=read(fd,buff,5);
	printf("Readed Contents are %s\n ",buff);

return 0;
}
