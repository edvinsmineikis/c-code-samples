#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    printf("\nI am parent %d, my parent is %d\n", getpid(), getppid());
    
    int pid = fork();

    if(pid == 0)
        printf("\nI am 1st child %d, my parent is %d\n", getpid(), getppid());
    
    int pid1 = fork();

    if(pid == 0 && pid1 == 0)
        printf("\nI am 2nd child %d, my parent is %d\n", getpid(), getppid());


    return 0;
}