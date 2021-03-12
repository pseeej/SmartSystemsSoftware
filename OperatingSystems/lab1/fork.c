#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int pid = fork();
	int status;

	if (pid>0){
		printf("parent : child = %d\n", pid);
		pid = wait(&status);
		printf("child %d is done\n", pid);
	}
	else if (pid==0){
		printf("child is existing\n");
	}
	else{
		printf("fork error\n");
	}

	return 0;
}
