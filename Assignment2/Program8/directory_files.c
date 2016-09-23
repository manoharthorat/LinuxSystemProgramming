/* 8. Write a program which accept directory name from user and print all file names from that directory.*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char * argv[])
{
	DIR *dir;
	struct dirent * entry;

	/*
	struct dirent 
	{
		ino_t d_ino;
		char d_name[NAME_MAX +1 ];
			
	}
	*/

	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName\n");
		return -1;
	}
	
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to Open Specified Directory \n");
		return -1;
	}
	
	printf("Contents of Directory are \n");
	
	while((entry=readdir(dir))!=NULL)
	{
		printf("Name: %s \t InodeNumber: %d \n",entry->d_name,(int)entry->d_ino);
	
	}
	closedir(dir);


return 0;
}

