/* 27. Write a aprogram which accept directory name and file name from user and create file in that directory. */
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	int fd;
	char name[20]={'\0'};

	if(argc !=3)
	{
		printf("Usage : ExeName DirectoryName FileName\n");
		return 0;
	}

	sprintf(name,"%s/%s",argv[1],argv[2]);

	fd=creat(name,0666);		


return 0;
}
