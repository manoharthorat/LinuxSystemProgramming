#include<stdio.h>
#include<fcntl.h>

int main()
{

	int fd;
	char buff;
	int count=0;
	fd=open("test",O_RDONLY);
	if(fd==-1)	
	{
		return -1;
	}		
	while(read(fd,&buff,1))
	{
		if(buff==' ')
		{
			count++;
		}	
	}

	printf("Words = %d \n",count);
	
return 0;
}
