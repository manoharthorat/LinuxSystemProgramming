/* 18.  Write a program which accept directory name from user and copy first 10 bytes from all regular files into newly created file named as 
demo. */

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
	DIR *dir;
	struct dirent * entry;
	struct stat fstat;
	int fd,fdwrite;
	int ret=0,ret1=0;
	char name[256]={'\0'};
	char buff[256]={'\0'};
 
	if(argc!=2)
	{
		printf("Usage : ExeName DirectoryName \n");
		return -1;
	}
	fdwrite=creat("demo",0666);
	if(fd==-1)
	{
		printf("Unable to create the File \n");
		return -1;
	}
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("Unable to open the directory \n");
		return -1;
	}	
	while((entry=readdir(dir))!=0)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&fstat);	
		if(S_ISREG(fstat.st_mode))
		{	
			fd=open(name,O_RDONLY);
			ret1=read(fd,buff,100);
			write(fdwrite,buff,ret1);
			close(fd);
		}
		memset(&fstat,0,sizeof(fstat));
	}
	close(fdwrite);
	
	closedir(dir);



return 0;
}
