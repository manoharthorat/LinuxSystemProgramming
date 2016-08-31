#include<stdio.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{

	int fd=0;
	if(argc!=2)
	{
		printf("Usage : Myexe filename\n");
		return 0;
	}	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		return -1;
	}
	else
	{
		printf("File is opened with file Descriptor %d \n",fd);
	}
	

return 0;
}
