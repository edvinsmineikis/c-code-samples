#include <stdio.h> // For user I/O
#include <sys/socket.h> // For sockets
#include <sys/types.h> // For socket types
#include <netinet/in.h>  // For sockaddr_in
#include <unistd.h> // For closing socket
#include <stdlib.h> // For strtol()

// This program will fork into sub-programs. The amount of programs created in total will be (2 ^ FORKLAYERS)
#define FORKLAYERS 4 

int main(int argc, char *argv[]) {
    
    // Checking input for errors
    if(argc != 2) {
        printf("Incorrect usage, do:\n./server [port]\n");
        return 1;
    }

    char *portbuf;
    int listen_port = strtol(argv[1], &portbuf, 10);
    if(listen_port == 0) {
        printf("Wrong port input\n");
        return 1;
    }
    
    // Create main socket for server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Struct for client info
    struct sockaddr_in client;
    int client_len = sizeof(client);
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = htons(listen_port);

    // Have to bind to port first
    if(bind(sockfd, (struct sockaddr *)&client, sizeof(client)) < 0) {
        perror("Binding failed");
        return 1;
    }

    // Calculating amount of sub-processes that will be created
    int total_forks = 1;
    for(int i = 0; i < FORKLAYERS; i++) {
        total_forks *= 2;
    }

    // Beginning to listen
    if(listen(sockfd, total_forks) < 0) {
        perror("Listening failed");
        return 1;
    }
    
    printf("Listening on port %d\n", listen_port);
    printf("Forking into %d processes\n", total_forks);
    
    int client_sock;
    int bytes_read;
    char msg_buffer[32];

    // Forking happens here
    for(int i = 0; i < FORKLAYERS; i++) {
        fork();
    }

    // Every process tries to catch an incoming client and output their message
    while(1) {
        if((client_sock = accept(sockfd, (struct sockaddr *)&client, (socklen_t*)&client_len)) < 0) {
            perror("Accept failure");
            return 1;
        }

        while((bytes_read = read(client_sock, msg_buffer, 256)) > 0) {
            msg_buffer[bytes_read] = '\0';
            printf("> %s", msg_buffer);
        }
    }
    
    // Never really gets to here, but just in case
    close(sockfd);
    close(client_sock);

    return 0;
}