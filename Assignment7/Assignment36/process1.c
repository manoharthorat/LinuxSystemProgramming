/*36.  Write a program which creates two processess as process2 and process3 and our parent process terminates till both the processess terminates*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t status1,status2;
	pid_t pid1,pid2;
	
	printf("This is process 1 %d \n",getpid());
	if(fork()==0)
	{
		printf("Process 2 %d \n",getpid());
		execl("./exec2",NULL,NULL);
	}
	else
	{
		printf("This is parent process 1%d\n",getpid());
		pid1=wait(&status1);
		printf("This is child process id %d and status is %d\n",pid1,status1);
	}


	 if(fork()==0)
        {
                printf("Process 3 %d \n",getpid());
                execl("./exec3",NULL,NULL);
        }
        else
        {
                printf("This is parent process 1%d\n",getpid());
                pid2=wait(&status2);
                printf("This is child process id %d and status is %d\n",pid2,status2);
        }
	
	

return 0;
}

