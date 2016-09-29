/* 14. Write program which accept directory name from user and delete all empty files from that directory.  */
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
	DIR *dir;
	struct dirent * entry;
	struct stat fstat;

	char name[256]={'\0'};
	if(argc!=2)
	{
		printf("Usage : ExeName SourceDirectory DestinationDirectory\n");
		return -1;
	}
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to open the directory \n");
		return -1;
	}
	while( (entry=readdir(dir)) !=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&fstat);
		if(S_ISREG(fstat.st_mode))
		{
			if(((int)fstat.st_size)==0)
			{
				remove(name);
			}			
		}	
		memset(&fstat,0,sizeof(fstat));	
	}
	closedir(dir);

return 0;
}



