#include "socketutil.h"


int main(){

    int SocketFD = createTCPIpv4Socket();

    struct sockaddr_in *address = createIPv4Address("127.0.0.1",2000);

    

    int result = connect(SocketFD, address, sizeof (*address));
    if(result == 0)
        printf("Connection was successfull\n");

    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(SocketFD,message,strlen(message),0);

    char* buffer[1024];
    recv(SocketFD,buffer,1024,0);

    printf("Response was %s\n",buffer);

    return 0;
}

