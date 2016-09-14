/* 10. Accept the file name from use and read the whole file. */
 

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{

	int fd;
	char buff[1024];
	int read_bytes=0;
	if(argc!=2)
	{
		printf("Usage : ExeName FileName\n");
		return -1;
	}
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to Open the file \n");
		return -1;
	}
	while(read_bytes=read(fd,buff,sizeof(buff)))
	{
		printf("%s",buff);
	}

return 0;
}
