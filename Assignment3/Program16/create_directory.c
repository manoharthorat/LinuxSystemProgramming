/* 16. Write a aprogram which accept directory name from user and create new directory of that name.*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char * argv [])
{
	int ret=0;

	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName \n");
		return -1;
	}
	
	ret=mkdir(argv[1],S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if(ret==-1)
	{
		printf("Unable to create the Directory\n ");
		return -1;
	}	


return 0;
}
