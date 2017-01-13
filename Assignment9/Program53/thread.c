/*53. Write a program which is used to get thread id inside its thread function.*/

#include<pthread.h>
#include<stdio.h>

void * ThreadProc(void * p)
{
	pthread_t tid;	
	tid =pthread_self();
//	printf("Thread Id %d \n",tid);
	pthread_exit((void*)tid);
}

int main()
{
	pthread_t thread1;
	int ret;
	int no=0;
	ret=pthread_create(&thread1,NULL,ThreadProc,NULL);
	if(ret!=0)
	{
		printf("Unable to cereate a thread\n");
	}
	
	pthread_join(thread1,(void**)&no);
	printf("THread %d \n",no);
	pthread_exit(NULL);
	
	
return 0;
}
