/*
File: sql_database.h

Description:
	- The SQL database serves as a common interface between the RC_P2P project and SQLite3. 
Its primary purpose is to log essential information about P2P peers. 

Autor: Marcos F. Caetano - mfcaetano@unb.br

Last update: 02/09/25.
*/


#ifndef __SQL_DATABASE_H__
#define __SQL_DATABASE_H__

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>


sqlite3 * open_db(const char* file_name);

void close_db(sqlite3 * db);

void create_tables(sqlite3* db);

int database_exists(const char* file_name);








#endif