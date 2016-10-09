/*13. Write a program which accept two directory names from user and move all files from source directory to destination directory.*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
	DIR *dir;
	struct dirent * entry;
	char oldpath[256]={'\0'};
	char newpath[256]={'\0'};

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
		sprintf(oldpath,"%s %s",argv[1],entry->d_name);
		sprintf(newpath,"%s %s",argv[2],entry->d_name);
		
		rename(oldpath,newpath);
		
		memset(&oldpath,0,sizeof(oldpath));
		memset(&newpath,0,sizeof(newpath));
	}
	closedir(dir);
	

return 0;
}
