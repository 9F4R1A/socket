#include "socketutil.h"


int main(){

    int SocketFD = createTCPIpv4Socket();

    struct sockaddr_in *address = createIPv4Address("127.0.0.1",2000);

    

    int result = connect(SocketFD, address, sizeof (*address));
    if(result == 0)
        printf("Connection was successfull\n");

    char *line = NULL;
    size_t lineSize=0;
    printf("Type and we will send(to exit type quit)...\n");

    while(true){
        ssize_t charCount = getline(&line,&lineSize,stdin);
        if(charCount > 0){
            if(strcmp(line,"quit\n"))
                break;
            ssize_t amountWasSent = send(SocketFD,line,charCount,0);
        }
    }


    return 0;
}

