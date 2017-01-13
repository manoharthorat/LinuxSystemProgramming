/*55. Write a program which creates multiple threads and sets its thread attributes accordingly */

#include<pthread.h>
#include<stdio.h>

void * Thread_Proc(void * p)
{
	long tid;
	tid=(long)p;
	sleep(1);
	printf("Sleeping in thread \n");
	printf("Thread with id %d existing \n ",tid);
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread[4];
	int ret, status;
	int i=0;
	pthread_attr_t attr;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	
	for(i=0;i<4;i++)
	{
		ret=pthread_create(&thread[i],NULL,Thread_Proc,(void*)i);
		if(ret!=0)
		{
			printf("Unable to create thread \n");
		}
	}
	
	pthread_attr_destroy(&attr);
	
	for(i=0;i<4;i++)
	{
		pthread_join(thread[i],(void**)&status);
		printf("Main : Completed thread id %d Existing status %d \n",i,status);
	}
	printf("Main Thread terminates \n");
	pthread_exit(NULL);
	
	return 0;
}
