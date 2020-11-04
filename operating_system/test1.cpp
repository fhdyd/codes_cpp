#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1 == 0){
        printf("a\n");
        return 0;
    }
    pid2 = fork();
    if(pid2 == 0){
        printf("b\n");
        return 0;
    }
    if(pid1 > 0 && pid2 > 0){
        printf("c\n");
    }
    return 0;
}