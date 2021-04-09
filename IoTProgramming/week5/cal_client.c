#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int s;
    struct sockaddr_in server_addr;
    int addr_len;
    char msg[1001];
    int len;
    int read_len;
    int ops;
    int i;
    char op;
    int o[100];

    if(argc!=3){
	printf("3 args\n");
	return 0;
    }

    printf("ops : ");
    scanf("%d", &ops);
    for(i=0;i<ops;i++){
	printf("operand%d : ", i);
	scanf("%d", &o[i]);
    }

    printf("op : ");
    scanf(" %c", &op);

    printf("ops : %d\n", ops);
    for(i=0;i<ops;i++){
	printf("operand:%d : %d\n", i, o[i]);
    }
    printf("op : %c\n", op);

    s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(s==-1){
     perror("socket");
     return 0; 
    }

    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &server_addr.sin_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    if(connect(s, (struct sockaddr *)&server_addr, sizeof(server_addr))){
	perror("connect");
	return 0;
    }

    int fd;
    fd = open("output", O_WRONLY | O_CREAT, 0644);

    write(s, &ops, 1);	//file에 쓰려면 s 자리에 fd만 넣어서 바꾸면 됨
    write(fd, &ops, 1);
    for(i = 0;i<ops;i++){
	o[i] = htonl(o[i]);
       write(s, &o[i], 4);
       write(fd, &o[i], 4);
    }

    write(s, &op, 1);
    write(fd, &op, 1);
   
    read(s, &ops, 4);
    ops = ntohl(ops);
    printf("result : %d\n", ops);

    close(fd);
    close(s);

    return 0;
}    

