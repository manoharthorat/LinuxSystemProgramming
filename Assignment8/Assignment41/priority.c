/*41.Write a program which is used to increase the priority by 5.*/

#include<stdio.h>
#include<unistd.h>
int main()
{
	int ret;
	printf("Default nice value of process is 0 \n");
	ret=nice(0);
	
	printf("Current nice value is %d \n",ret);
	ret=nice(5);
	
	printf("New Nice value is %d \n",ret);
	
return 0;
}

