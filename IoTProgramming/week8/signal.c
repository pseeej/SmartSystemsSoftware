#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void timeout(int sig){
    printf("Time out\n");
    alarm(2);
}

void keycontrol(int sig){
    printf("Interrupt\n");
}

int main(){

    int i;

    signal(SIGALRM, timeout);
    signal(SIGINT, keycontrol);
    alarm(2);

    for(i=0;i<3;i++){
	printf("wait...\n");
	sleep(10);
    }



    return 0;
}
