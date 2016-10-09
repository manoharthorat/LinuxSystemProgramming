/* 17. Write a program which accept two file names from user and check whether contents of that two files are equal are not.*/

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	int fd1,fd2;
	int ret1=0,ret2=0;
	char buff1[256];
	char buff2[256];
	struct stat fstat1;
	struct stat fstat2;
	int fret1=0,fret2=0;

	int flag=0;
	if(argc!=3)
	{
		printf("Usage: ExeName FileName1 FileName2\n");
		return -1;
	}	
	fret1=stat(argv[1],&fstat1);
	if(fret1==-1)
	{
		printf("Unable to retrive the information of the file \n");
		return -1;
	}
	

	
	
	fret2=stat(argv[2],&fstat2);
	if(fret2==-1)
	{
		printf("Unable to retrive the information of the file \n");
		return -1;
	}

	if((int)fstat1.st_size !=(int)fstat2.st_size)
	{
		printf("Both file contents are different \n");
		return -1;
	}
		
	if((fd1=open(argv[1],O_RDONLY))<0)
	{
		printf("Unable to open the file %s \n",argv[1]);
		return -1;
	}

	if((fd2=open(argv[2],O_RDONLY))<0)
	{
		printf("Unbale to open the %s file \n",argv[2]);
		return -1;
	}
	while((ret1=read(fd1,buff1,sizeof(buff1)))!=0)
	{
		read(fd2,buff2,ret1);
		if(memcmp(buff1,buff2,ret1)!=0)
		{
			flag=-1;
			break;
		}
	}	
	
	if(flag==-1)
	{
		printf("Contents are not equal \n");
	}
	else
	{
		printf("Contents of both files are equal \n");
	}
	
	close(fd1);
	close(fd2);

return 0;
}
