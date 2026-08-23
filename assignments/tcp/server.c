#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void main()
{
    int listenfd, connectfd;

    listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if (listenfd == -1)
    {
        printf("error creating a socket\n");
        exit(EXIT_FAILURE);
    }

    int yes = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    struct sockaddr_in host, client;
    socklen_t sin_size;
    host.sin_family = AF_INET;
    host.sin_port = htons(8090);
    host.sin_addr.s_addr = 0;
    memset(&(host.sin_zero), '\0', sizeof(host.sin_zero));

    if (bind(listenfd, (const struct sockaddr *)&host, sizeof(host)) == -1)
    {
        printf("binding error");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, 5) == -1)
    {
        printf("listening failure");
        exit(EXIT_FAILURE);
    }
    printf("Listning on 8090 .... \n");
    char buffer[1024];
    while (1)
    {
        memset(buffer, 0x00, sizeof(buffer));
        sin_size = sizeof(struct sockaddr_in);
        connectfd = accept(listenfd, (struct sockaddr *)&client, &sin_size);
        if (connectfd == -1)
        {
            printf("accept failure");
            exit(EXIT_FAILURE);
        }

        printf("Server: got connection from %s port %d\n",
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        send(connectfd, "Hello, world!\n", 14, 0);
        int len = recv(connectfd, &buffer, sizeof(buffer), 0);
        printf("I got %d bytes: %s\n", len, buffer);
        close(connectfd);
    }

    close(listenfd);
}