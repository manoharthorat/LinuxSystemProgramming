/*58. Write a program which creates two threads by using pthread API, where one thread count number of capital characters from demo.txt file and other threads count number of small characters from same file */

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

void * ThreadProc2(void* p)
{
	int fd,ret;
	int small=0;
	char buff[256];
	fd=open("demo.txt",O_RDONLY);
	printf("File descriptor of this thread is %d \n",fd);
	if(fd==-1)
	{
		printf("Unable to open the file \n");
		pthread_exit(NULL);
	}

	while((ret=read(fd,buff,256))!=0)
	{
		while(ret!=0)
		{
			if(buff[ret]>='a' && buff[ret]<='z')
			{
				small++;
			}
			ret--;
		}
	}
	close(fd);
	printf("Small characters by thread2 is %d \n",small);
	pthread_exit(NULL);
}

void * ThreadProc1(void* p)
{
	int fd,ret;
         int cap=0;
	char buff[256];
         fd=open("demo.txt",O_RDONLY);
         printf("File descriptor of this thread is %d \n",fd);
         if(fd==-1)
         {       
                 printf("Unable to open the file \n");
                 pthread_exit(NULL);
         }
                 
         while((ret=read(fd,buff,256))!=0)
         {
                 while(ret!=0)
                 {
                         if(buff[ret]>='A' && buff[ret]<='Z')
                         {
                                 cap++;
                         }
                         ret--;
                 }
         }
         close(fd);
         printf("capital characters by thread1 is %d \n",cap);
         pthread_exit(NULL);

}


int main()
{
	pthread_t thread1,thread2;
	int ret1,ret2;
	
	ret1=pthread_create(&thread1,NULL,ThreadProc1,NULL);
	if(ret1!=0)
	{
		printf("Unable to create the thread \n");
	}
	
	ret2=pthread_create(&thread2,NULL,ThreadProc2,NULL);
	if(ret2!=0)
	{
		printf("Unable to create thread \n");
	}

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	pthread_exit(NULL);
return 0;
}
