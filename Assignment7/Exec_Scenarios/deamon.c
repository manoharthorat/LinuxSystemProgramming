#include<stdio.h>

int main()
{
	printf("In deamon\n");
	setsid();
	sleep(5);
	printf("After Deamon complete \n");
return 0;
}
