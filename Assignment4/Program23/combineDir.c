/* 23. 	Write a program which accept directory name from user and 
combine all contents of file from that directory into one file named as AllCombine. */

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char * argv[])
{
	DIR * dir;
	struct dirent * entry;
	char name[20];
	struct stat fstat;
	int fdread,fdwrite,retread;
	char buff[256];
	int fd;
	
	typedef struct
		{
			char name[20];
			int size;
		}INFO;

	INFO obj;	

	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName \n\n");	
		return -1;
	}
	if((dir=opendir(argv[1]))==NULL)	
	{
		printf("Unable to open the directory \n");
		return -1;
	}
	fd=creat("Allcombine",0666);
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&fstat);
		if(S_ISREG(fstat.st_mode))
		{	
			fdread=open(name,O_RDONLY);
			strcpy(obj.name,entry->d_name);
			obj.size=fstat.st_size;
			write(fd,&obj,sizeof(obj));
			
			while((retread=read(fdread,buff,sizeof(buff)))!=NULL)
			{
				write(fd,buff,retread);
				
			}			
			close(fdread);

		}
	}

	closedir(dir);

return 0;
}
