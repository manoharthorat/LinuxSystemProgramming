#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char * argv[])
{
	int fd;
	char buff[512];
	char * str="read";

	if(argc!=2)
	{
		printf("Usage : ExeName FileName\n");
		return -1;
	}
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to Open the file \n");
	}
	else
	{
		printf("File is opened with fd %d ",fd);
	}

	while(read(fd,buff,sizeof(buff))!=0)
	{
			
	}
	
	
	

return 0;
}
