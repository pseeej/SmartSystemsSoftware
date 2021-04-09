#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define BUF_SIZE 100

char escape[] = "exit\n";

int num_client = 0;
pthread_mutex_t mutex;

void *thread_main(void *arg){

    int size;
    int s = *(int *)arg;
    char buf[BUF_SIZE];

    free(arg);

    while(1){
	if((size=recv(s, buf, BUF_SIZE, 0))>0){
	    buf[size]='\0';

	    printf("Recv : %s\n", buf);
	    send(s, buf, size, 0);

	}
	else{
	    break;
	}
    }

    pthread_mutex_lock(&mutex);    
    num_client--;
    pthread_mutex_unlock(&mutex);
    printf("Disconnected : %d\n", num_client);



    close(s);
    return NULL;
}

int main(int argc, char *argv[]){
    int sockfd, newfd;
    struct sockaddr_in my_addr, their_addr;
    unsigned int sin_size, len_inet;
    int pid, size;
    char buf[BUF_SIZE];
    pthread_t t_id;
    int *arg;

    pthread_mutex_init(&mutex, NULL);

    if(argc<2){
	fprintf(stderr, "Usage : %s <PORT>\n", argv[0]);
	return 0;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

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

    printf("Waiting...\n");

    while(1){
	newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
	if(newfd<0){
	    perror("accept");
	    return 0;
	}
	printf("Connected : %s %d num_client : %d\n", inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port), num_client);

	pthread_mutex_lock(&mutex);    
	num_client++;
	pthread_mutex_unlock(&mutex);

	arg = (int *)malloc(sizeof(int));
	*arg = newfd;

	pthread_create(&t_id, NULL, thread_main, arg);
	pthread_detach(&t_id);

    }

    close(sockfd);
    return 0;
}
