/* 14. Write program which accept directory name from user and delete all empty files from that directory.  */


#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
	DIR *dir;
	struct dirent * entry;
		
	if(argc!=3)
	{
		printf("Usage : ExeName SourceDirectory DestinationDirectory\n");
		return -1;
	}
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to open the directory \n");
		return -1;
	}
	while((entry=readdir(dir))!=NULL)
	{
			


