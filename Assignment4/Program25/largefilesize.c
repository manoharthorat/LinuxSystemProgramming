/* 25. Write a program which accept file name which contains data of all file. We have to print  all file names whose size is greater that 10 bytes.*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{

	int fd,retread;
	char * ptr=NULL;
	int fdnew;
	typedef struct 
	{
		char name[20];
		int size;
	}INFO;
	
	INFO obj;
	
	if(argc!=2)
	{
		printf("Usage : ExeName FileName\n");
		return -1;
	}
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		return -1;
	}
	
	while((retread=read(fd,&obj,sizeof(obj)))!=NULL)
	{
		if(obj.size > 10 )
		{
			printf("%s\n",obj.name);
		}
		lseek(fd,obj.size,SEEK_CUR);
		
	/*
		//fdnew=creat(obj.name,0666);
		ptr=(char *)malloc(obj.size*(sizeof(char)));
		read(fd,ptr,obj.size);
		
		write(fdnew,ptr,obj.size);
		close(fdnew);	
		free(ptr);
	*/	
	}
	close(fd);
return 0;
}
