#include<stdio.h>
#include<fcntl.h>

int main(int argc,char * argv[])
{

	int fd;
	char ch;
	int count=0;	
	fd=open(argv[1],O_RDONLY);
	
	if(fd==-1)
	{	
		printf("Unable to open the file \n");
		return -1;
	}
	else
	{	
		printf("File is opened with file descriptor %d \n",fd);
	}
	while(read(fd,&ch,1))
	{
		if(ch=='\n')
		{
			count++;	
		}
	}
	printf("Line Count = %d\n",count);

	
return 0;
}
