#include <stdio.h> // For user I/O
#include <sys/socket.h> // For sockets
#include <sys/types.h> // For socket types
#include <arpa/inet.h> // For sockaddr_in
#include <unistd.h> // For closing sockets

int main() {

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Define struct to hold socket information
    struct sockaddr_in server;
    server.sin_family = AF_INET;

    // Some user input for destination IP and port, they are later put into the struct
    char conn_addr[16];
    int conn_port;

    printf("Enter address: ");
    fgets(conn_addr, sizeof(conn_addr), stdin);
    if(server.sin_addr.s_addr = inet_addr(conn_addr) == INADDR_NONE) {
            printf("Faulty IP address\n");
            return 1;
        }

    printf("Enter port: ");
    if(fscanf(stdin, "%d", &conn_port) == 0) {
        printf("Wrong input\n");
        return 1;
    }
    server.sin_port = htons(conn_port);
    
    // Connecting to destination
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection fault");
        return 1;
    }
    else {
        printf("Connected! Leave blank message to quit.\n");
    }

    // Uninterrupted sending of messages
    char buff[128];
    int len;
    getchar();
    while(1) {
        printf("> ");
        fgets(buff, sizeof(buff), stdin);
        fflush(stdin);
        if(buff[0] == '\n') {
            printf("Done!\n");
            break;
        }
        for(len = 0; buff[len] != '\0'; len++);
        send(sockfd, buff, len, 0);
    }

    close(sockfd);

    return 0;
}
