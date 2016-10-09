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
	
	INFO obj2,obj3;
	INFO * ptr1;
	ptr1=&obj2;

	fd=open(argv[1],O_WRONLY);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		return -1;
	}

	strcpy(obj2.name,"Manohar");
	strcpy(obj3.name,"Thorat");
	obj2.no=20;
	obj3.no=40;
	
	if((ret=write(fd,(char*)&obj2,sizeof(obj2))) < 0)
	{
		printf("Unable to write the contents obj2 \n");
		return 0;
	}
	if((ret=write(fd,(char*)&obj3,sizeof(obj3))) < 0)
	{
		printf("Unable to write the contents obj3 \n");
		return 0;
	}
	
	close(fd);

return 0;
}


//DIR * dir;



