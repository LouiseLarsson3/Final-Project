//============================================================================
// Name        : AAServerBirdRec.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SERVER_PORT 8090    //Port number
#define BUFFER_SIZE 1024
#define MAX_PENDING_CONNECTIONS 5

int main() {
	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_len = sizeof(client_addr);
	char buffer[BUFFER_SIZE];

	// Create a socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Configure the server address
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(SERVER_PORT);

	// Bind the socket to server address
	if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("Bind failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	// Listen for connections
	if (listen(server_fd, MAX_PENDING_CONNECTIONS) < 0) {
		perror("Listen failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	printf("Server listening on port %d\n", SERVER_PORT);

	// Accept incoming connections
	while (1) {
		// Accept new connection
		client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
		if (client_fd < 0) {
			perror("Accept failed");
			continue;
		}

		printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		// Receive data
		while (1) {
			memset(buffer, 0, BUFFER_SIZE);
			ssize_t received_bytes = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);

			if (received_bytes <= 0) {
				printf("Connection closed by client\n");
				break;
			}

			printf("Received data: %s\n", buffer);
			// Parse the received data and store it in separate variables
			char deviceID[BUFFER_SIZE];
			char timestamp[BUFFER_SIZE];
			char birdName[BUFFER_SIZE];

			sscanf(buffer, "%s %s %s", deviceID, timestamp, birdName);

			printf("Device ID: %s\n", deviceID);
			printf("Timestamp: %s\n", timestamp);
			printf("Bird Name: %s\n", birdName);

			FILE *file = fopen("//home//olle//eclipse-workspace CPP//Server 1.0//"
					"src//datalog", "a");
			if (file == NULL){
				printf("Error: unable to open file.\n");
				return 1;
			}

			fprintf(file, "%s %s %s\n", deviceID, timestamp, birdName);
			fclose(file);
		}

		// Close the connection
		close(client_fd);
	}

	// Close server socket
	close(server_fd);
	return 0;
}
