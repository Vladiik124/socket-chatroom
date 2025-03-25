#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    
    char Server_ip[] = "127.0.0.1"; 
    int PORT = 8080;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket was not created\n");
        exit(1);
    } else {
        printf("Socket created successfully\n");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);  

    if (inet_pton(AF_INET, Server_ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton failed\n");
        exit(1);
    }

    int Bind = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (Bind == -1) {
        perror("couldn't bind socket lol\n");
        exit(1);
    }
    printf("Socket successfully bounded to %s and port %d \n", Server_ip, PORT);


    close(sockfd);
    return 0;
}
