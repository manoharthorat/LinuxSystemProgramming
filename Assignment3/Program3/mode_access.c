/* 3. Write a program which accept file name and on mode and that program check whether our process can access that file in accepted mode or not. */

#include<stdio.h>
#include<fcntl.h>
int main(int argc, char * argv[])
{

	int fd;
	int mode;
	if(argc!=3)
	{
		printf("Enter COrrect Arguments\n");
		return -1;
	}	

	if((strcmp(argv[2]),"read")==0)
	{
		mode=R_OK;
	}
	else if((strcmp(argv[2]),"write")==0)
        {
                mode=W_OK;
        }
	else if((strcmp(argv[2]),"Execute")==0)
        {
                mode=X_OK;
        }
	if(access(argv[1],mode)<0)
	{
		printf("Our Process cant access this file %s mode\n",argv[2]);
	}
	else
	{
		printf("Our Process can Access file with %s file Permission \n",argv[2]);
	}
			

return 0;
}
