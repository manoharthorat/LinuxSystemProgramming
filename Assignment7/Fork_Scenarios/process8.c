#include<stdio.h>
#include<unistd.h>

int main()
{
	int no;
	printf("parent pid %d\n",getpid());
	no=fork();
	//printf("child pid %d ",no);
return 0;
}
