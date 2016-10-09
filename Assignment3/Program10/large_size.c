/* 
10. Write a program which accept directory name from user and print name of such a file having largest size.*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char * argv[])
{
	DIR * dir;
	struct dirent * entry;
	struct stat fstat;
	char name[50]={'\0'};
	int max=0;
	char FileName[256]={'\0'};
	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName \n");
		return -1;
	}
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Failed to open the directory \n");
		return -1;
	}
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&fstat);
		if(S_ISREG(fstat.st_mode))
		{
			if(max < (int)fstat.st_size)	
			{
				memset(FileName,0,sizeof(FileName));
				strcpy(FileName, entry->d_name);
				max=(int)fstat.st_size;			
			}
		}	
		memset(&fstat,0,sizeof(fstat));
		
	}
	printf("File name:  %s Size : %d \n",FileName,max);
	closedir(dir);

return 0;
}
