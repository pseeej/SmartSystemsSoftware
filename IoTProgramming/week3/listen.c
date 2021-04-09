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

	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
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

	if(listen(s, 5) == -1){		//listen까지 해야 port가 열림
		perror("listen ; ");
		return 0;
	}

	addr_len = sizeof(struct sockaddr_in);

	client_s = accept(s, (struct sockaddr *)&client_addr, &addr_len);	//연결 요청 없어서 block됨으로 ./week3_1해도 실행이 안 됨
	if (client_s ==-1){
		perror("accept");
		return 0;
	}

	len = recv(client_s, buf, 1000, 0);	//accept 하고 난 다음의 socket인 client_s 넣어야함)
	if (len==-1){
		perror("read");
		return 0;
	}

	buf[len] = '\0'; 	//null문자 제일 마지막에 넣어줌
	printf("len : %d\n", len);
	printf("%s\n",  buf);

	close(client_s); 

	return 0;
}
