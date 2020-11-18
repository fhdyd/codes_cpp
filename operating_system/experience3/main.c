#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>

int wait_flag;

void stop(){wait_flag=0;}
 
int main()
{
	pid_t pid1,pid2;
	signal(2,stop);
	pause();
	while((pid1 = fork())== -1);
	if(pid1 > 0)
	{
	  while((pid2 = fork()) == -1 );
	  if(pid2 > 0)
	  {
	    wait_flag=1;
	    sleep(5);  
	    kill(pid1, 16);
	    kill(pid2,17);
	    wait(0);
	    wait(0);
	    printf("\nparent process is killed!!\n");
	    exit(0);
	  }
      else
   	  {
	    wait_flag= 1;
		signal(17,stop);
	    printf("\nchild process 2 is killed by parent!!\n");
	    exit(0);
	  }
	}
	else 
	{
	  wait_flag=1;
	  signal(16,stop);
	  printf("\nchild process 1 is killed by parent!!\n");
	}
	
}
 