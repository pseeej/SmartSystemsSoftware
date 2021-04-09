#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(){
    int tcp_sock, udp_sock;
    int opt, optlen = 4;

    tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
    udp_sock = socket(PF_INET, SOCK_DGRAM, 0);

    opt = 100000;
    setsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void *)&opt, optlen);
    setsockopt(tcp_sock, SOL_SOCKET, SO_RCVBUF, (void *)&opt, optlen);

    getsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void *)&opt, &optlen);
    printf("send : %d\n", opt);
    getsockopt(tcp_sock, SOL_SOCKET, SO_RCVBUF, (void *)&opt, &optlen);
    printf("receive : %d\n", opt);

     

    return 0;
}
