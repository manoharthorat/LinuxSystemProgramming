/* 20. Write a program which writes structure in file.*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	int fd;
	int ret=0;	
	typedef struct 
	{
		char name[20];
		int no;
	}INFO;
	if(argc!=2)
	{
		printf("Usage : ExeName FileName\n");	
		return -1;
	}
	INFO obj1,obj2;
	
	strcpy(obj1.name,"Manohar");
	strcpy(obj2.name,"Thorat");

	obj1.no=10;
	obj2.no=30;
	
	fd=open(argv[1],O_WRONLY);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		return -1;
	}

	ret=write(fd,(char*)&obj1,sizeof(obj1));
	if(ret==-1)
	{
		printf("Unable to write the contents obj2 \n");
		return -1;
	}
	
	
	ret=write(fd,(char*)&obj2,sizeof(obj2));
	if(ret==-1)
	{
		printf("Unable to write the contents obj2 \n");
		return -1;
	}
	
	close(fd);

return 0;
}


//DIR * dir;



