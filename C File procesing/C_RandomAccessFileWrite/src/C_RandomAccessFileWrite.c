/*
 ============================================================================
 Name        : C_RandomAccessFileWrite.c
 Author      : Cristian Mosquera
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// clientData structure definition
struct clientData {
	unsigned int acctNum; // account number
	char lastName[ 15 ]; // account last name
	char firstName[ 10 ]; // account first name
	double balance; // account balance
}; // end structure clientData

int main(void) {

	FILE *cfPtr; // credit.dat file pointer

	setbuf(stdout, NULL);	// disable the buffer

	// create clientData with default information
	struct clientData client = { 0, "", "", 0.0 };

	// fopen opens the file; exits if file cannot be opened
	if ( ( cfPtr = fopen( "credit.dat", "rb+" ) ) == NULL ) {
		puts( "File could not be opened." );
	}
	else{
		// require user to specify account number
		printf( "%s", "Enter account number"
		 " ( 1 to 100, 0 to end input )\n? " );
		scanf( "%d", &client.acctNum );

		// user enters information, which is copied into file
		while ( client.acctNum != 0 ) {
			// user enters last name, first name and balance
			printf( "%s", "Enter lastname, firstname, balance\n? " );

			// set record lastName, firstName and balance value
			// its equal to scanf(...)
			fscanf( stdin, "%14s%9s%lf", client.lastName,
			client.firstName, &client.balance );

			// seek position in file to user-specified record
			fseek( cfPtr, ( client.acctNum - 1 ) *
			sizeof( struct clientData ), SEEK_SET );

			/*
			The symbolic constant SEEK_SET indicates that
			the file position pointer is positioned relative
			to the beginning of the file by the amount of the offset
			*/

			// write user-specified information in file
			fwrite( &client, sizeof( struct clientData ), 1, cfPtr );

			// enable user to input another account number
			printf( "%s", "Enter account number\n? " );
			scanf( "%d", &client.acctNum );
		} // end while

		fclose( cfPtr ); // fclose closes the file
	} // end else

	return EXIT_SUCCESS;
} // end main
