#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    fd_set readfds;
    struct timeval timeout;
    int result;
    char buf[1000];

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    result = select(1, &readfds, NULL, NULL, &timeout);
    if(result == -1){
	perror("select");
	return 0;
    }
    else if(result == 0){
	printf("Timeout!\n");
    }
    else{
	if(FD_ISSET(0, &readfds)) {
	    printf("Event!\n");
	    read(0, buf, 1000);
	    printf("%s\n", buf);
	}
    }

    return 0;
}
