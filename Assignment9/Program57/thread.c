/*57. Write a program which creates two thread, and by using appropriate synchronization technique avoid the scheduling problem */

#include<stdio.h>
#include<pthread.h>

int counter;
pthread_mutex_t lock;

void * Thread_Proc(void *p)
{
	pthread_mutex_lock(&lock);
	unsigned long i=0;
	counter++;
	printf("Task %d started successfully  counter \n",counter);
	
	for(i=0;i<0xffffffff;i++)

	printf("Task %d Finished Successfully \n",counter);
	
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);

}

int main()
{

	pthread_t thread1,thread2;
	int ret1;
	int no=11;
	
	if(pthread_mutex_init(&lock,NULL)!=0)
	{
		printf("Problem in mutex creation \n");
	}
	
	ret1= pthread_create(&thread1,NULL,Thread_Proc,NULL);
	
	if(ret1!=0)
	{
		printf("Problem in thread1 Creation \n");
	}

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	pthread_exit(NULL);
	
	pthread_mutex_destory(&lock);

return 0;
}
