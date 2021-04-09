#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int s, client_s;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addr_len;
    char buf[1000];
    int len;
    int i;
    int ops;
    char op;
    int o[100];

    s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(s==-1) {
	perror("socket");
    }

    server_addr.sin_family=PF_INET;
    server_addr.sin_port = htons(54321);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(server_addr.sin_zero), 0, 8);

    if (bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr))){
	perror("bind");
	return 0;
    }

    if(listen(s, 5)==-1){
	perror("listen");
	return 0;
    }

    addr_len = sizeof(struct sockaddr_in);

    client_s = accept(s, (struct sockaddr *)&client_addr, &addr_len);
    if(client_s == -1){
	perror("accept");
	return 0;
    }

    ops = 0;

    len = read(client_s, &ops, 1);
    for(i = 0;i<ops;i++){
	read(client_s, &o[i], 4);
	o[i] = ntohl(o[i]);
    }
    read(client_s, &op,1);

    printf("%d\n", ops);
    for(i=0;i<ops;i++){
	printf("%d\n", o[i]);
    }
    printf("%c\n", op);

    int result = 0;
    
    switch(op){
	case '+':
	    for(i=0;i<ops;i++){
		result += o[i];
	    }
	    break;
	case '-':
	    result = o[0];
	    for(i=1;i<ops;i++){
		result -= o[i];
	    }
	    break;
	case '*':
	    result = 1;
	    for(i=0;i<ops;i++){
		result *= o[i];
	    }
	    break;
    }
    
    result = htonl(result);
    write(client_s, &result, 4);


    close(client_s);
    close(s);

    return 0;

}
