#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t pid = fork();
    if(pid == 0)printf("son\n");
    else printf("father\n");
}