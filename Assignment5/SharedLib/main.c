#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
	void * ptr=NULL;
	void (*fptr)()=NULL;
	
	ptr=dlopen("/home/manohar/LinuxSystemProgramming/Assignment5/SharedLib/library.so",RTLD_LAZY);
	
	if(ptr==NULL)
	{
		printf("Unable to load library  \n");
		return 0;
	}
	
	fptr=dlsym(ptr,"Demo");
	if(fptr==NULL)
	{
		printf("Unable to get the address of function \n");
		 	
	}
	fptr();
	dlclose(ptr);

return 0;
}
