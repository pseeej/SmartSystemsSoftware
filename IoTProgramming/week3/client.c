#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(){
	int s, client_s;
	struct sockaddr_in server_addr;
	int addr_len;
	char msg[1000] = "Hello World";

	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(s==-1){
		perror("socket");
		return 0;
	}

	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(54321);
	inet_aton("127.0.0.1", &server_addr.sin_addr);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	memset(&(server_addr.sin_zero), 0, 8);

	if (connect(s, (struct sockaddr *)&server_addr, sizeof(server_addr))== -1){
		perror("connect");
		return 0;
	}

	send(s, msg, strlen(msg)+1, 0); 	//여기선 socket하나밖에 없으니 그냥 s i넣으면 됨
					//strlen(msg)+1로 제일 마지막에 \0 넣어줌

	close(s);

	return 0;
}
