#include<stdio.h>
#include<fcntl.h>


int main(int argc,char * argv[])
{
	int fd;
	int count=0;
	char buff[512];
	char ch;
	fd=open(argv[1],O_RDONLY);
	while((ch=getc(fd))!=EOF)
	{
		count++;
	}


return 0;
}
