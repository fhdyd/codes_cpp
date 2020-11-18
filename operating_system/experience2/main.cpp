#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

using namespace std;

int main(){
    pid_t pid1, pid2;
    pid1 = fork();//子进程1创建
    if(pid1 == 0){
        //在子进程1中
        cout << "This is child1!" << endl;
        return 0;
    }
    else{
        //在父进程中
        cout << "This is father!" << endl;
        pid2 = fork();//子进程2创建
        if(pid2 == 0){
            cout << "This is child2!" << endl;
            return 0;
        }
    }
}