/* 11. Write a program which accept two file names from user and copy the contents of an existing file into newly created file.*/

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	int fd,fd1;
	char buff[512];
	int ret=0;
	if(argc!=3)
	{
		printf("Usage : ExeName SourceFile DestinatioFile\n");
		return -1;
	}	
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to Open the file \n");
		return -1;
	}
	fd1=open(argv[2],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open the destination file \n");
		return -1;
	}
	
	while((ret=read(fd,buff,sizeof(buff)))!=0)
	{
		write(fd1,buff,ret);
	}


return 0;
}

