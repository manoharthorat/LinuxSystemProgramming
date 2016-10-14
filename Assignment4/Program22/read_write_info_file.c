/*22. 	Write a program which accept directory name from user and 
write information of all regular file in and 
then read the contents from that file.*/

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char * argv[])
{
	int fd;
	int ret=0;
	DIR * dir;
	struct dirent * entry;
	struct stat fstat;
	char name[20]={'\0'};

	
	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName \n");
		return 0;
	}
	
	typedef struct{
		char name[20];
		int ino;
		int size;
	}FINFO;
	
	FINFO obj;
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to open the Specific Directory\n");
		return -1;
	}
	
	fd=creat("Demo",0666);
	
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
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
	close(fd);
	printf("Information of All Files \n");
	fd=open("Demo",O_RDONLY);
	
	while((read(fd,&obj,sizeof(obj)))!=0)
	{
		printf("%d\t%s\t%d\n",obj.ino,obj.name,obj.size);	
	}
return 0;
}
