/*44. Write a program which is used to pring home directory and login user name.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char * env=NULL;
	env=getenv("HOME");
	printf("Home directory of our process is %s \n",env);
	
	env=getenv("USER");
	printf("User Name is %s \n",env);
return 0;
}


