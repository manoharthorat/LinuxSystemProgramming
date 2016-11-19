#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = 0;
	fd = open("demo.txt",O_RDWR);
	if(fork() == 0)
	{
		write(fd,"Child",5);
		close(fd);
	}
	else
	{
		write(fd,"Parent",6);
		close(fd);
	}

	return 0;
}

