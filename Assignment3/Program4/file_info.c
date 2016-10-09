/* 4. Write a program which accept file name from user and print all information about that file. */

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
	int fd;
	struct stat fstat;
	int ret;
	if(argc !=2)
	{
		printf("Usage : ExeName FileName\n");
		return -1;
	}
	ret=stat(argv[1],&fstat);
	if(ret==-1)
	{
		printf("Unable to retrive the information \n");
		return -1;
	}
	printf("ID of Device containing file	\t%d\n",(int)fstat.st_dev);
	printf("Inode Number of file		 \t\t%d\n ",(int)fstat.st_ino);
	

	    printf("File Permissions: 		\t");
	    printf( (S_ISDIR(fstat.st_mode)) ? "d" : "-");
	    printf( (fstat.st_mode & S_IRUSR) ? "r" : "-");
	    printf( (fstat.st_mode & S_IWUSR) ? "w" : "-");
	    printf( (fstat.st_mode & S_IXUSR) ? "x" : "-");
	    printf( (fstat.st_mode & S_IRGRP) ? "r" : "-");
	    printf( (fstat.st_mode & S_IWGRP) ? "w" : "-");
	    printf( (fstat.st_mode & S_IXGRP) ? "x" : "-");
	    printf( (fstat.st_mode & S_IROTH) ? "r" : "-");
	    printf( (fstat.st_mode & S_IWOTH) ? "w" : "-");
	    printf( (fstat.st_mode & S_IXOTH) ? "x" : "-");
	    printf("\n\n");
	
	    printf("The file %s a symbolic link\n", (S_ISLNK(fstat.st_mode)) ? "is" : "is not");

	printf("Total number of HardLinks 	\t\t%d \n ",(int)fstat.st_nlink);
	printf("User Id 			\t\t\t %d\n",(int)fstat.st_uid);
	printf("Group ID 			\t\t\t%d\n",(int)fstat.st_gid);
	printf("Total size of bytes 		\t%d\n",(int)fstat.st_size);
	printf("Blocksize of Filesystem IO 	\t%d\n",(int)fstat.st_blksize);
	printf("Number of blocks allocated 	\t%d\n",(int)fstat.st_blocks);
		
	
	
	
	

return 0;
}
