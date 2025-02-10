/*
File: rendezvous.c

Description:
	- Base file containing the rendezvous server. The purpose of 
this server is to register clients with dynamic IP addresses and
provide this list as the bootstrap for the network.

Autor: Marcos F. Caetano - mfcaetano@unb.br

Last update: 02/08/25.
*/

#include <stdio.h>
#include <netinet/in.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include "help_menu.h"
#include "sql_database.h"

int main(int argc, char* argv[]){
	struct sockaddr_in server_addr;
	char* db_name = "/home/mfcaetano/Documents/src/rc_p2p/rendevouz/util/rendezvous.db";
	sqlite3 * db; 

	if(argc == 1){
		printf("No arguments provided. Use -h for mor information.\n");
		return 1;
	}//end argc

	if(processing_menu(argc, argv, &server_addr))
		return 1;

	printf("IP: %s, Port: %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

	if(database_exists(db_name)){
		printf("Opening database.");
		
		db = open_db(db_name);

	}else{
		printf("Creating database.");

		db = open_db(db_name);
		create_tables(db);
		
	}

	close_db(db);


	return 0;
}//end main()