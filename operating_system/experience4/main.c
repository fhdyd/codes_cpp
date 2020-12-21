#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int wait_flag;

void stop();

int main()

{

 int pid,i,j;

 pid=fork();                   /*创建子进程*/

 if(pid>0)                    /*以下是父进程代码*/

  { wait_flag=0;

    printf("This is parent!\n");

    sleep(5);                 /*父进程等待5秒*/

    kill(pid,17);              /*向子进程发出信号17*/

    printf("The kill signal has send!!\n");

    wait(0);                /*等待子进程的结束信号*/

    printf("The parent is ended!!\n");

  }

 else       /*以下是子进程代码*/

 {

   wait_flag=0;

   printf("This is child!\n");

   signal(17,stop);           /*若接收到信号17则执行stop函数*/

   while(1)                /*循环等待*/

{

/*若执行了stop函数，wait_flag会变为1，则子进程结束*/

if(wait_flag>0)

     {printf("The child is ended!!\n");

     exit(0); }

}/*end of while*/

 }/*end of child process*/

return 0;

}/*end of main*/

void stop()    /*信号执行句柄函数*/

{

 wait_flag=1;   /*若执行此函数，可让全局变量wait_flag变为1*/

}