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


	int fd;
	fd = open("output", O_WRONLY | O_CREAT, 0644);

	struct data d;
	d.a = 1;	//little endian이므로 output 파일에는 0100 0000으로 기록됨
	d.b = 2;
	d.op = '+';

	write(fd, &d, sizeof(struct data));
	close(fd);

	printf("%d\n", sizeof(struct data)); //12출력됨


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
