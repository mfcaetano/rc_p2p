/*
File: help_menu.h

Description:
	- 

Autor: Marcos F. Caetano - mfcaetano@unb.br

Last update: 02/08/25.
*/

#ifndef __HELP_MENU_H__
#define __HELP_MENU_H__


#include <netinet/in.h> 


void print_help_menu();

int processing_menu(int argc, char* argv[], struct sockaddr_in* server_addr);


#endif