
/*54. Write a program which creates 4 number of  threads and our main thread waits till all the thread terminates.*/

#include<stdio.h>
#include<pthread.h>

void * Thread_Proc(void *p)
{
	printf("Inside thread with id %d and data %d \n",pthread_self(),(int)p);
	pthread_exit(NULL);

}
int main()
{
	pthread_t thread[4];
	int ret;
	int i;
	for(i=0;i<4;i++)
	{
		ret=pthread_create(&thread[i],NULL,Thread_Proc,(void*)i);
		if(ret!=0)		
		{
			printf("Problem in thread creation \n");
		}
	}
	
	for(i=0;i<4;i++)
	{
		 pthread_join(thread[i],NULL);
	}
	
	pthread_exit(NULL);
return 0;
}


