/* 21. Write a program which accept file name from user which contains information of emloyee , we have to read all contents of that file.*/

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
	int fd;
	int ret=0;

	if(argc!=2)
	{
		printf("Usage : ExeName FileName \n");
		return 0;
	}

	typedef struct
	{		
		char name[20];
		int no;
	}INFO;
	
	INFO obj1;

	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		return -1;
	}
	while((ret=read(fd,&obj1,sizeof(obj1)))!=0)
	{
		printf("%d %s\n",obj1.no,obj1.name);
	}
	close(fd);

	
return 0;
}
