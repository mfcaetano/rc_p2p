/*
File: rendezvous.c

Description:
	- Base file containing the rendezvous server. The purpose of 
this server is to register clients with dynamic IP addresses and
provide this list as the bootstrap for the network.

Autor: Marcos F. Caetano - mfcaetano@unb.br

Last update: 02/08/25.
*/

#include "help.h"
#include <stdio.h>
#include <netinet/in.h> 
#include <sys/socket.h>
#include <arpa/inet.h>


int main(int argc, char* argv[]){
	struct sockaddr_in server_addr;

	if(argc == 1){
		printf("No arguments provided. Use -h for mor information.\n");
		return 1;
	}//end argc

	if(processing_menu(argc, argv, &server_addr))
		return 1;

	printf("IP: %s, Port: %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));



	return 0;
}//end main()