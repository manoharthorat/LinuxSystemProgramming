/*39. Write a program which creates two processess. Process 1 count number of capital characters from demo.txt file. And process 2 count number of capital characters from hello.txt file. Both the processess writes its count in count.txt file.*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd,ret=0,CapCnt=0;
	char buff[256],data[100];
	
	fd=open("demo",O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		return -1;
	}

	while((ret=read(fd,buff,sizeof(buff)))!=0)
	{
		while(ret!=0)
		{
			if(buff[ret] >='A' && buff[ret]<='Z')	
			{
				CapCnt++; 
			}
			ret--;
		}
	}
	close(fd);
		
	fd=open("count1",O_WRONLY | O_APPEND);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
	}
	
	sprintf(data,"demo = %d ",CapCnt);
	write(fd,data,strlen(data));	
	close(fd);
return 0;
}	
