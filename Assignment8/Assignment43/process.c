/* 43. Write a program which is used to display Environment of our running process. */
#include<stdio.h>

extern char ** environ;
int main()
{
	char **env=environ;
	printf("Environment of our process is \n");
	for(;*env!=NULL;++env)
	{
		printf("%s\n",*env);
	}
return 0;
}

