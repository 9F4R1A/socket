#include "socketutil.h"


int main(){

    int SocketFD = createTCPIpv4Socket();

    struct sockaddr_in *address = createIPv4Address("172.217.168.174",80);

    

    int result = connect(SocketFD, address, sizeof (*address));
    if(result == 0)
        printf("Connection was successfull\n");

    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google.con\r\n\r\n";
    send(SocketFD,message,strlen(message),0);

    char* buffer[1024];
    recv(SocketFD,buffer,1024,0);

    printf("Response was %s\n",buffer);

    return 0;
}

