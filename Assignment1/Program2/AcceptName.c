/*   2. Write a program which accept name from command line argument and display it on
screen. */

#include<stdio.h>

int main(int argc, char * argv[])
{
	char name[20];
	
	if(argc=2)
	{
		printf("Usage : ExeName \"Enter Name\" \n");
	}
	printf("Entered Name is %s \n",argv[1]);
	return 0;
}
