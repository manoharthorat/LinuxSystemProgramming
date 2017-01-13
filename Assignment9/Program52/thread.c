/*52. Write a program which creates single thread and it accept one value from user and it return some value to the caller thread.*/

#include<pthread.h>
#include<stdio.h>

void * ThreadProc1(void *p)
{
	int i=11;
	printf("Inside THread \n");
	pthread_exit((void *)i);
}
int main()
{
	pthread_t thread1;
	int ret1;
	int no=0;
	
	ret1=pthread_create(&thread1,NULL,ThreadProc1,NULL);
	
	if(ret1!=0)
	{
		printf("Problem in thread 1 creation \n");
	}

	pthread_join(thread1,(void **)&no);
	printf("Value returned by thread is %d \n",no);
	
	pthread_exit(NULL);	

return 0;
}
