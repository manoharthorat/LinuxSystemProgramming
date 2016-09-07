/* 6.  Write a program which accept file name from user and open that file and if file is not
opened properly then display error message properly.  */

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[]) // For Commandline arguments
{
	int fd;		//File Descriptor 
	if(argc!=2)	//If passed arguments are not two 
	{
		printf("Usage : ExeName FileName \n");
		return -1;
	}

	fd=open(argv[1],O_RDONLY);	// Open system call (FileName, Mode of the File )
	
	if(fd==-1)			//Error while opening file 
	{
		printf("Unable to Open the file \n");
	}
	else
	{
		printf("File is Opened with %d File Descriptor \n",fd);
	}	
	

	return 0;
}
