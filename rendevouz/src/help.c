/*
File: help.c

Description:
	- 

Autor: Marcos F. Caetano - mfcaetano@unb.br

Last update: 02/08/25.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include "help.h"


void print_help_menu(){
    printf("Use: rendevouz [options]\n");
    printf("Available Options:\n");
    printf("  -h              Show this helping menu.\n");
    printf("  -ip             Define listening IP.\n");
    printf("  -port           Define listening port number.\n");
    printf("\nExample:\n");
    printf("  ./rendevouz -ip 127.0.0.1 -p 3000\n");
}//end print_help_menu();


int processing_menu(int argc, char* argv[], struct sockaddr_in* server_addr){
    char* ip = NULL;
    char* port = NULL;
    server_addr->sin_family = AF_INET; // IPv4

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-h") == 0){
            print_help_menu();
            return 0;
        }else if(strcmp(argv[i], "-ip") == 0){
            if (i + 1 < argc) {
                ip = argv[i + 1];
                i++;
            } else {
                printf("Error: option %s requires an argument.\n", argv[i]);
                return 1;
            }
        }else if(strcmp(argv[i], "-port") == 0){
            if (i + 1 < argc) {
                port = argv[i + 1];
                i++;
            } else {
                printf("Error: option %s requires an argument.\n", argv[i]);
                return 1;
            }
        }else{
            printf("Unknown option: %s. Use -h for assistance.\n", argv[i]);
            return 1;
        }//end if strcmp()
    }//end for i


    if(ip)
        server_addr->sin_addr.s_addr = inet_addr(ip ); // Convert string IP to network byte order
    
    if(port)
        server_addr->sin_port = htons(atoi(port)); // Convert port to network byte order

    return 0;
}//end processing_menu()
