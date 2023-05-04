//============================================================================
// Name        : Server.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_PORT 8090
#define BUFFER_SIZE 1024
#define MAX_PENDING_CONNECTIONS 5

int main() {
	// Initialize Winsock
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;
	int addr_len = sizeof(client_addr);
	char buffer[BUFFER_SIZE];

	// Create server socket
	server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server_fd == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	// Configure server address
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(SERVER_PORT);

	// Bind server socket to the address
	if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
		printf("Bind failed with error: %d\n", WSAGetLastError());
		closesocket(server_fd);
		WSACleanup();
		return 1;
	}

	// Start listening for incoming connections
	if (listen(server_fd, MAX_PENDING_CONNECTIONS) == SOCKET_ERROR) {
		printf("Listen failed with error: %d\n", WSAGetLastError());
		closesocket(server_fd);
		WSACleanup();
		return 1;
	}

	printf("Server listening on port %d\n", SERVER_PORT);
	fflush(stdout);

	// Main loop to accept incoming connections and process them
	while (1) {
		client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
		if (client_fd == INVALID_SOCKET) {
			printf("Accept failed with error: %d\n", WSAGetLastError());
			continue;
		}

		printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
		fflush(stdout);
		// Process incoming data from the client
		while (1) {
			memset(buffer, 0, BUFFER_SIZE);
			int received_bytes = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);

			if (received_bytes <= 0) {
				printf("Connection closed by client\n");
				fflush(stdout);
				break;
			}

			printf("Received data: %s\n", buffer);
			fflush(stdout);

			// Parse the received data and store it in separate variables
			char deviceID[BUFFER_SIZE];
			char timestamp[BUFFER_SIZE];
			char birdName[BUFFER_SIZE];

			sscanf(buffer, "%s %s %s", deviceID, timestamp, birdName);

//			printf("Device ID: %s\n", deviceID);
//			printf("Timestamp: %s\n", timestamp);
//			printf("Bird Name: %s\n", birdName);
//			fflush(stdout);

			FILE *file = fopen("C:\\Users\\OlleWigarthsson\\ecplipse workspace CPP"
					"\\Server\\src\\datalog", "a");
			if (file == NULL){
				printf("Error: unable to open file.\n");
				return 1;
			}

			fprintf(file, "%s %s %s\n", deviceID, timestamp, birdName);
			fclose(file);
		}

		// Close the client connection
		closesocket(client_fd);
	}

	// Cleanup
	closesocket(server_fd);
	WSACleanup();
	return 0;
}
