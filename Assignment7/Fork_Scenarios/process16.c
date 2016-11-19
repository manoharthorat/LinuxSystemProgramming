#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd=0;
	fd=open("demo",O_RDWR);
	if(fork()==0)
	{
		write(fd,"child",5);
	}
	else
	{
		write(fd,"parent",6);
	}
return 0;
}
