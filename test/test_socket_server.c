// Socket test

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int server_fd, new_sock, valread;
	struct sockaddr_in address;
	char buffer[1024] = {0};
	int opt = 1;
	char *hello = "Hello from server";

	// create socket
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{

		perror("socket failed");
		exit(EXIT_FAILURE);
	}else{
		printf("server created fd OK");
	}
   
	// set socket option
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
	    perror("setsockopt error");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = 8000;

	// bind
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind fail");
		exit(EXIT_FAILURE);
	}

    // listen
	if(listen(server_fd, 3) < 0)
	{
		perror("listen error");
		exit(EXIT_FAILURE);
	}

	int addrlen = sizeof(address);
	new_sock =  accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if(new_sock < 0)
	{
		perror("accept error");
		exit(EXIT_FAILURE);
	}

	valread = read(new_sock, buffer, 1024);
	printf("%s\n", buffer);
	send(new_sock, hello, strlen(hello), 0);
	printf("hello message send");

    return 0;
}



