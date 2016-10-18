/* 28. Write a program which accept directory name from user and delete all such files whose size is greater than 100 bytes.*/
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
	DIR * dir;
	struct dirent * entry;
	struct stat fstat;
	char name[20]={'\0'};
	
	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName \n");
		return -1;
	}
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to open the directory\n");
		return -1;	
	}
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&fstat);
		
		if(S_ISREG(fstat.st_mode))
		{
			if((int)fstat.st_size > 100)
			{
				remove(name);	
			}
		}	
		memset(&fstat,0,sizeof(fstat));
	
	}
	closedir(dir);
	
return 0;
}
