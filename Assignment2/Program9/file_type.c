/* 9. Write a program which accept directory name from user and print all file names and its types from that directory. */


#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
	DIR *dir;
	struct dirent * entry;
	struct stat fstat;
	char name[100];
	if(argc!=2)	
	{
		printf("Usage : ExeName DirectoryName \n\n");
		return -1;
	}	
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to open the directory \n\n");
		return -1;
	}
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&fstat);
		printf("%s ",entry->d_name);
		if(S_ISREG(fstat.st_mode))
		{
			printf("Regular File \n");
		}
		else if(S_ISDIR(fstat.st_mode))
		{
			printf("Directory \n");
		}
		else if(S_ISLNK(fstat.st_mode))
		{
			printf("Link \n");
		}
	}
	closedir(dir);
		

return 0;
}
