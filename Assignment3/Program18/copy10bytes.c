/* 18.  Write a program which accept directory name from user and copy first 10 bytes from all regular files into newly created file named as 
demo. */

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
	DIR *dir;
	struct dirent * entry;
	struct stat fstat;
	
	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName \n");
		return -1;
	}
	


return 0;
}
