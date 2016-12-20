/* This function is used to retrive the value of perticular environment variable 
	for that we ahve to pass name of that environmet variable and its return value of that variable*/

//syntax char * getenv(const char * name )

//we can use setenv() function to set the specific value 

#include<stdio.h>
#include<stdlib.h>

int main()
{	
	char * p;
	p=getenv("PWD");
	if(p==NULL)
	{
		printf("Unable to get the value\n");
	}
	
	printf("Your present working directory is %s \n",p);
	
	

return 0;
}
