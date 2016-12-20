/*49. Write a program which is used to create simple thread by using pthread library*/
#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * p)
{
	printf("This is thread\n");
	pthread_exit(NULL);
}
int main()
{
	int ret;
	pthread_t thread1;
	printf("Inside main thread \n");
	ret=pthread_create(&thread1,
				NULL,
				ThreadProc,
				NULL
				);
	if(ret!=0)
	{
		printf("Unable to create thread \n");
	}
	pthread_join(thread1,NULL);
	pthread_exit(NULL);
return 0;
}
