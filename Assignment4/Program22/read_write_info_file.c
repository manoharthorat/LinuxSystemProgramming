/*22. 	Write a program which accept directory name from user and write information of all regular file in and then read the contents from that file.*/

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
	char name[256]={'\0'};
	int fd;
	int ret;	
	typedef struct 
	{
		char name[256];
		int ino;
		int size;
	}FILEINFO;
	
	FILEINFO obj;
	
	
	if(argc !=2)
	{
		printf("Usage : ExeName DirectoryName\n");	
		return -1;
	}	
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to open the directory \n");
		return -1;
	}

	fd=creat("demo",0666);
	if(fd==-1)
	{
		printf("Unable to create the file \n");
		return -1;		
	}
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"%s/%S",argv[1],entry->d_name);
		stat(name,&fstat);
		if(S_ISREG(fstat.st_mode))
		{
			strcpy(obj.name,entry->d_name);
			obj.ino=fstat.st_ino;
			obj.size=fstat.st_size;
			write(fd,&obj,sizeof(obj));
			
		}
	}
	closedir(dir);
		
	printf("Informtion of All Files \n");
	close(fd);
	fd=open("demo",O_RDONLY);
	while((ret=read(fd,&obj,sizeof(obj)))!=0)
	{
		printf("%d\t%s\t%d",obj.ino,obj.name,obj.size);
	}


return 0;
}
