/*
File: sql_database.c

Description:
	- The SQL database serves as a common interface between the RC_P2P project and SQLite3. 
Its primary purpose is to log essential information about P2P peers. 

Autor: Marcos F. Caetano - mfcaetano@unb.br

Last update: 02/09/25.
*/

#include "sql_database.h"
#include <stdio.h>
#include <sqlite3.h>


sqlite3 * open_db(const char* file_name){
	sqlite3* db;
	int rc;

	rc = sqlite3_open(file_name, &db);

	if(rc){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return NULL;
	}else{
        printf("Database opened successfully!\n");
	} //end rc


	return db;
}//end open_db()


void create_tables(sqlite3* db){
	int rc;
	char *errMsg = 0;

	// SQL statement to create a table
    const char *sql = "CREATE TABLE IF NOT EXISTS \"Log\" ("
					  "\"id\" INTEGER NOT NULL UNIQUE, "
					  "\"ip.src\" TEXT NOT NULL, "
					  "\"tcp.srcport\"	INTEGER NOT NULL, "
					  "\"ip.dst\" TEXT NOT NULL, "
					  "\"tcp.dstport\"	INTEGER NOT NULL, "
					  "\"ttl\"	TEXT NOT NULL, "
					  "PRIMARY KEY(\"id\" AUTOINCREMENT)); ";

	rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

	if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table 'Log' created successfully!\n");
    }

}//end create_tables()


void close_db(sqlite3 * db){
	sqlite3_close(db);
}//end close_db()


int database_exists(const char* file_name){
	FILE* file = fopen(file_name, "r");

	if(file){
		fclose(file);
		return 1;
	}

	return 0;
}// end database_exists()