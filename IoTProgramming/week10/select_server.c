#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define BUF_SIZE 100

char escape[] = "exit\n";

int main(int argc, char *argv[]){
    int sockfd, newfd;
    struct sockaddr_in my_addr, their_addr;
    unsigned int sin_size, len_inet;
    int pid, size;
    char buf[BUF_SIZE];
    fd_set readfds, readtemp;
    int max_fd = 0;
    int result;

    if(argc<2){
	fprintf(stderr, "Usage : %s <PORT>\n", argv[0]);
	return 0;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //listening socket

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(atoi(argv[1]));
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(my_addr.sin_zero), 0, 8);

    if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))==-1){
	perror("bind");
	return 0;
    }
    if(listen(sockfd, 5)<0){
	perror("listen");
	return 0;
    }

    sin_size = sizeof(struct sockaddr_in);

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    max_fd = sockfd;

    printf("Waiting...\n");

    while(1){
	readtemp = readfds;

	result = select(max_fd + 1, &readtemp, NULL, NULL, NULL);
	if(result==-1){
	    perror("select");
	    return 0;
	}
	for(int i=0;i<max_fd + 1;i++){
	    if(FD_ISSET(i, &readtemp)){
		if(i==sockfd){
		    //listening
		    newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		    if(newfd<0){
			perror("accept");
			return 0;
		    }
		    printf("Connected : %s %d\n", inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port));
		    FD_SET(newfd, &readfds);
		    if(max_fd < newfd){
			max_fd = newfd;
		    }

		}
		else{
		    //DATA
		    size = recv(i, buf, BUF_SIZE, 0);
		    if(size> 0){
			buf[size]='\0';

			printf("Recv : %s\n", buf);

			send(i, buf, size, 0);
		    }
		    else if(size==0){
			FD_CLR(i, &readfds);
			close(i);
			printf("disconnected\n");
		    }
		    else if (size==-1){
			perror("recv");
			return 0;
		    }
		}
	    }
	}

    }

    close(sockfd);
    return 0;




}

