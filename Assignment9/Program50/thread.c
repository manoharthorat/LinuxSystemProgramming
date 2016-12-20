/*50. Write a program which creates two thread , first thread print numbers from 1 to 500 & other thread print the numbers from 500 to 1.
*/

#include<stdio.h>
#include<pthread.h>

void *FirstThread(void *p)
{
	int i=0;
	for(i=0;i<100;i++)
	{
		printf("First Thread %d \n",i);
	}
	pthread_exit(NULL);
}

void *SecondThread(void *p)
{
	int i=0;
	for(i=100;i>0;i--)
	{
		printf("Second Thread %d \n",i);
	}
	pthread_exit(NULL);

}
int main()
{

	pthread_t thread1,thread2;
	int ret1,ret2;
	
	ret1=pthread_create(&thread1,NULL,FirstThread,NULL);
	if(ret1!=0)
	{
		printf("Unable to create a Frist thread \n");
	}
	
	ret2=pthread_create(&thread2,NULL,SecondThread,NULL);
	if(ret2!=0)
	{
		printf("Unable to create a Second thread \n");
	}
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	pthread_exit(NULL);

return 0;
}
