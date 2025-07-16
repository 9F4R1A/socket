#include "socketutil.h"

struct Sockaddr_in* createIPv4Address(char *ip, int port){
    //char* ip = "10.0.0.147";
    //char* ip = "172.217.168.174";
    struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in));
    address->sin_family = AF_INET;
    address->sin_port = htons(port);
    inet_pton(AF_INET,ip, &address->sin_addr.s_addr);
    return address;
}


int createTCPIpv4Socket() {
    return socket(AF_INET,SOCK_STREAM,0);
}