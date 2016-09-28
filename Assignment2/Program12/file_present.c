/* 12. Write a program which accept directory name and file name from user and check whether that file is present in that directory or not.*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	DIR * dir;
	struct dirent * entry;
	struct stat * fstat;
	if(argc!=3)
	{
		printf("Usage : ExeName DirectoryName FileName\n");
		return -1;
	}	
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to open the directory \n");
		return -1;
	}
	while((entry =readdir(dir))!=NULL)
	{
		if(strcmp(argv[2],(char*) entry-> d_name)==0)
		{
			printf("File is present %s \n",argv[2])	;
			break;
		}
		
	}
	closedir(dir);


return 0;
}
