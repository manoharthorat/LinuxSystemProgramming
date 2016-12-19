/*38. Write a program which creates new process which is responsible to write all file names which are present on desktop in demo file which should be created newly.*/

#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	DIR * dir;
	struct dirent * entry;
	struct stat filestat;
	char name[100]={'\0'};
	int fd;
	
	typedef struct
	{
		char name[50];
		int ino;
		int size;	
	}FILEINFO;
	FILEINFO obj;
	
	if((dir=opendir("/home/manohar/Desktop/"))==NULL)
	{
		printf("Unable to open specified directory");
		return -1;
	}
	
	fd=creat("demo1",0666);
	if(fd==-1)
	{
		printf("Unable to create file \n");
		return -1;
	}
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"/home/manohar/Desktop/%s",entry->d_name);
		stat(name,&filestat);
		//check file type

		if(S_ISREG(filestat.st_mode))			
		{
			strcpy(obj.name,entry->d_name);
			obj.ino=filestat.st_ino;
			obj.size=filestat.st_size;
			write(fd,&obj,sizeof(obj));
		}

		
	}
	
	closedir(dir);

return 0;
}
