#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(){
    int s, client_s;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addr_len;
    char buf[1000]="";
    int len;
    int i;
    char *ip;
    int port;

    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(s==-1){
	perror("socket : ");
    }

    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(54321);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(server_addr.sin_zero), 0, 8);

    if (bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
	perror("bind : ");
	return 0;
    }

    addr_len = sizeof(client_addr);

    while(1){
	len = recvfrom(s, buf, 1000, 0, (struct sockaddr*)&client_addr, &addr_len);

	if(len==-1){
	    perror("recvfrom");
	    return 0;
	}
	else if(len==0){
	    printf("Disconnected\n");
	    break;
	}

	buf[len]='\0';
	ip = inet_ntoa(client_addr.sin_addr);
	port = ntohs(client_addr.sin_port);
	printf("%s:%d : %s\n",ip, port, buf);

	len = sendto(s, buf, len, 0, (struct sockaddr*) &client_addr, addr_len);
	if(len==-1){
	    perror("sendto");
	    return 0;
	}
    }



    close(s);

    return 0;
}
