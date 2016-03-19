#include <stdlib.h>
#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char message [2000], server_reply[2000];
    int recv_size;
    char checkToExit[] = "exit";

    //Initialize winsocket lib
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

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    //Connect to remote server
    if (connect(s, (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
    puts("Connected");

    while(1)
    {
        //Get an answer
        if((recv_size = recv(s , server_reply , sizeof(server_reply) , 0)) == SOCKET_ERROR)
        {
            puts("recv failed");
        }
        server_reply[recv_size] = '\0';
        printf("\nServer >> %s\n", server_reply);
        //Get a reply
        printf(">> ");
        gets(message);
        if(!strcmp(message, checkToExit))
            break;
        send(s, message, strlen(message), 0);
    }

    closesocket(s);
    WSACleanup();
    puts("End of the program.");
    return 0;
}
