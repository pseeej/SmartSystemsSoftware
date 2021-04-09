#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int pid = fork();
    int status;

    char *argv[] = {"ls", 0};

    if (pid>0){
        printf("parent : child = %d\n", pid);
        pid = wait(&status);
        printf("child %d is done\n", pid);
    }
    else if (pid==0){
        printf("child is existing\n");
        execv("/bin/ls", argv);

    }
    else{
        printf("fork error\n");
    }

    return 0;

}
