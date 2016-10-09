/*5. Write a program which accept file name and number of bytes from user and read that number of bytes from file.*/

#include<stdio.h>
#include<fcntl.h>

int main(int argc , char * argv[])
{
	int fd;
	char* buff=NULL;
	int ret=0;
	if(argc!=3)
	{
		printf("Usage : ExaName FileName Number_Of_Bytes_Read\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file \n");
		return -1;
	}
	buff=(char*)malloc(sizeof(char)*atoi(argv[2]));
	if(buff==NULL)
	{
		printf("Memory allocation failed \n");
		return -1;
	}
	ret=read(fd,buff,atoi(argv[2]));
	if(ret!=atoi(argv[2]))
	{
		printf("unable to read expected bytes \n");
	}
	printf("Number of bytes read %d Contents shown below \n\n",ret);
	printf("File Name %s\n\n Contenst: \n %s \n",argv[1],buff);

	


return 0;
}
