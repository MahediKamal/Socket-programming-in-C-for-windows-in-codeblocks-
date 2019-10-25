#include<stdio.h>
#include <winsock2.h>

int main()
{
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;

    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr("192.168.1.169");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);

    connect(server, (SOCKADDR *)&addr, sizeof(addr));

    printf("Connected to server!\n");

    char buffer[1024],reply[1000];
    printf("Enter a message:");
    gets(buffer);
    send(server, buffer, sizeof(buffer), 0);
    printf("Message sent!\n" );
    Beep(1000,1000);
    recv(server,reply,sizeof(reply),0);
    printf("\n          Server reply : %s\n",reply);


    closesocket(server);
    WSACleanup();
    printf("Socket closed.");
}
