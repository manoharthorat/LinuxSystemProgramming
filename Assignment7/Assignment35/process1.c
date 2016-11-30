#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork()==0)
	{
		printf("PRocess2 %d \n",getpid());
		execl("./exec2",NULL,NULL);
	}

        if(fork()==0)
        {
                printf("PRocess3 %d \n",getpid());
                execl("./exec3",NULL,NULL);
        }
        if(fork()==0)
        {
                printf("PRocess4 %d \n",getpid());
                execl("./exec4",NULL,NULL);
        }
      
return 0;
}
