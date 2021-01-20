#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 100

char escape[] = "exit\n";

void *thread_send(void *arg){

    int sockfd = *(int *)arg;
    int size;
    char buf[BUF_SIZE];

    while(1){
	printf("Input : ");
	fflush(stdout);
	size = read(0, buf, BUF_SIZE);
	if(size <= 0){
	    perror("read");
	    exit(1);
	}

	buf[size]='\0';


	if(strncmp(buf, escape, 4) == 0){
	    shutdown(sockfd, SHUT_WR);
	    break;
	}

	send(sockfd, buf, size, 0);
	printf("Host : %s", buf);
    }

    return NULL;
}

int main(int argc, char *argv[]){
    int sockfd, newfd;
    struct sockaddr_in my_addr, their_addr;
    unsigned int sin_size, len_inet;
    int pid, size;
    char buf[BUF_SIZE];
    pthread_t t_id;

    if(argc<3){
	fprintf(stderr, "Usage : %s <IP> <PORT>\n", argv[0]);
	return 0;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(atoi(argv[2]));
    my_addr.sin_addr.s_addr = inet_addr(argv[1]);
    memset(&(my_addr.sin_zero), 0, 8);

    sin_size = sizeof(struct sockaddr_in);

    if(connect(sockfd, (struct sockaddr *)&my_addr, sin_size)<0){
	perror("connect");
	exit(1);
    }
    printf("Connected. (Enter \"exit\" to quit)\n");

    pthread_create(&t_id, NULL, thread_send, &sockfd);
    pthread_detach(t_id);

    while(1){
	size = recv(sockfd, buf, BUF_SIZE, 0);
	if(size<=0) break;
	buf[size]='\0';
	printf("Server : %s", buf);
    }


    close(sockfd);
    return 0;
}
