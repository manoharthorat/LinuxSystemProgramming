/*42. Write a program which is used to yield our processor by using appropriate system call.*/

#include<stdio.h>
#include<sched.h>

int main()
{
	int ret=0;
	ret=sched_yeild();
	if(ret==0)
	{
		printf("Yeiled the processor \n");
	}
return 0;
}

