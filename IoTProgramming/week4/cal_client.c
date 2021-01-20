#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <fcntl.h>

struct data{
	int a;
	int b;
	char op;
};

int main(){
	int s, client_s;
	struct sockaddr_in server_addr;
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

	if (connect(s, (struct sockaddr *)&server_addr, sizeof(server_addr))== -1){
		perror("connect");
		return 0;
	}

	int fd;
	fd = open("output", O_WRONLY | O_CREAT, 0644);

	struct data d;
	d.a = htonl(1);	//little endian이므로 output 파일에는 0100 0000으로 기록됨
	d.b = htonl(2);
	d.op = '+';

	write(s, &d, sizeof(struct data));
	write(fd, &d, sizeof(struct data));
	close(fd);


//	int fd;
//	fd = open("output", O_RDONLY);
//	struct data d;
//	read(fd, &d, sizeof(struct data));
//	close(fd);
//
//	printf("%d %d %c\n", d.a, d.b, d.op);
//

	close(s);

	return 0;
}
