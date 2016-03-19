#include<io.h>
#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s , new_socket;
    struct sockaddr_in server , client;
    int c;
    char *message;
    char client_reply[2000];
    int recv_size;
    char checkToExit[] = "exit";

    //Initialize winsock lib
    printf("Initialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    puts("Bind done");

    //Listen to incoming connections
    listen(s , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while( (new_socket = accept(s , (struct sockaddr *)&client, &c)) != INVALID_SOCKET )
    {
        puts("Connection accepted");
        //Reply to the client
        while(1)
        {
            //Get a reply
            printf(">> ");
            gets(client_reply);
            if(!strcmp(client_reply, checkToExit))
                break;
            send(new_socket, client_reply, strlen(client_reply), 0);
            //Get an answer
            if((recv_size = recv(new_socket, client_reply, sizeof(client_reply), 0)) == SOCKET_ERROR)
            {
                puts("recv failed.\n");
            }
            client_reply[recv_size] = '\0';
            printf("\nClient>>: %s\n", client_reply);
        }
        break;
    }

    if (new_socket == INVALID_SOCKET)
    {
        printf("accept failed with error code : %d" , WSAGetLastError());
        return 1;
    }

    closesocket(s);
    WSACleanup();
    puts("End of the program.");
    return 0;
}
