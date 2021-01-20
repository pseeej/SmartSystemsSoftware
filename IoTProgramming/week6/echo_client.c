#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(){
    int s;
    struct sockaddr_in server_addr;
    struct sockaddr_in addr;
    int addr_len;
    char msg[1001];
    int len;
    int read_len;

    s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(s==-1){
	perror("socket");
	return 0;
    }

    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(54321);
    inet_aton("127.0.0.1", &server_addr.sin_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    if(connect(s, (struct sockaddr *)&server_addr, sizeof(server_addr))==-1){
	perror("connect");
	return 0;
    }

    while(1){
	printf("Input message(Q to quit) : ");
	fgets(msg, 1000, stdin);

	if(strcmp(msg, "q\n")==0 || strcmp(msg, "Q\n")==0){
	    break;
	}
	//len = sendto(s, msg, strlen(msg), 0, (struct sockaddr*)&server_addr,addr_len);
	len = send(s, msg, strlen(msg), 0); //connect 사용할 때
	if(len == 0){
	    printf("Send : Disconnected\n");
	    break;
	}
	if(len==-1){
	    perror("send");
	    return 0;
	}
	printf("len : %d\n", len);
	//read_len = recvfrom(s, msg, 1000, 0, (struct sockaddr*)&addr, &addr_len);
	len = recv(s, msg, 1000, 0);   //connect 사용할 때`
	if(len==-1){
	    perror("recv");
	    close(s);
	    return 0;
	}
	else if(len==0){
	    printf("Disconnected\n");
	    break;
	}

	msg[len] = '\0';
	printf("Echo : %s\n", msg);
    }

    shutdown(s, SHUT_WR);
    while(1){
	 len = recv(s, msg, 1000, 0);
	 if(len==-1){
	     perror("recv");
	     return 0;
	 }
	 else if(len==0){
	     printf("Disconnected\n");
	     break;
	 }
	 msg[len]='\0';
	 printf("Echo : %s\n", msg);
    }

    close(s);

    return 0;
}
