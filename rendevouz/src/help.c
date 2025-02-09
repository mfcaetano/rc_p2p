/*
File: help.c

Description:
	- 

Autor: Marcos F. Caetano - mfcaetano@unb.br

Last update: 02/08/25.
*/

#include <stdio.h>
#include <string.h>
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


void processing_menu(int argc, char* argv[]){

}//end processing_menu()
