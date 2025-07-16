#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

    int SocketFD = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in address;

    //char* ip = "10.0.0.147";
    char* ip = "172.217.168.174";
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    inet_pton(AF_INET,ip, &address.sin_addr.s_addr);

    int result = connect(SocketFD, &address, sizeof address);
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