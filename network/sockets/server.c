#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd;  // socket file descriptor
    int new_socket; // socket file descriptor
    int valread;    // read return value

    struct sockaddr_in address; // socket address: family, port, address

    int opt = 1;                   // socket option
    int addrlen = sizeof(address); // socket address length
    char buffer[1024] = {0};       // buffer for read
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed"); // print error message
        exit(EXIT_FAILURE);      // exit with failure
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | 0, &opt,
                   sizeof(opt)))
    {
        perror("setsockopt"); // print error message
        exit(EXIT_FAILURE);   // exit with failure
    }
    address.sin_family = AF_INET;         // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // localhost
    address.sin_port = htons(PORT);       // port 8080

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed"); // print error message
        exit(EXIT_FAILURE);    // exit with failure
    }

    // listen for connections on a socket
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");   // print error message
        exit(EXIT_FAILURE); // exit with failure
    }
    printf("Listening on port %d\n", PORT);
    // accept a connection on a socket
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");   // print error message
        exit(EXIT_FAILURE); // exit with failure
    }

    // read from a file descriptor
    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);                    // print buffer
    send(new_socket, hello, strlen(hello), 0); // send hello message
    printf("Hello message sent\n");            // print message

    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}