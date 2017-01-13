/*51.  Write a program which creates single thread and we have to pass parameter to that thread from main thread.
*/

#include<stdio.h>
#include<pthread.h>

void Thread_proc1(void * p)
{
	int i=(int)p;
	printf("Inside thread1 and its value is %d \n",i);
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1;
	int ret1;
	int no=11;
	
	ret1 = pthread_create(&thread1,NULL,Thread_proc1,(void*)no);
	if(ret1!=0)
	{
		printf("Problem in thread Creation \n");
	}
	pthread_join(thread1,NULL);
	pthread_exit(NULL);
return 0;
}

