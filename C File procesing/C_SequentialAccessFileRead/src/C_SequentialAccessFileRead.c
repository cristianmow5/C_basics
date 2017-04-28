/*
 ============================================================================
 Name        : C_SequentialAccessFileRead.c
 Author      : Cristian Mosquera
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	unsigned int account; // account number
	char name[ 30 ]; // account name
	double balance; // account balance

	FILE *cfPtr; // cfPtr = clients.dat file pointer

	//setbuf(stdout, NULL); //disable the buffer

	// fopen opens file. Exit program if unable to create file
	if ( ( cfPtr = fopen( "clients.dat", "r" ) ) == NULL ) {
		puts( "File could not be opened" );
	} // end if
	else {
		printf( "%-10s%-13s%s\n", "Account", "Name", "Balance" );
		fscanf( cfPtr, "%d%29s%lf", &account, name, &balance );

		// while not end of file

		while (!feof( cfPtr )) {
			printf( "%-10d%-13s%7.2f\n", account, name, balance );
			fscanf( cfPtr, "%d%29s%lf", &account, name, &balance );
		} // end while

		/*use rewind if you want to read again from the beginning
		 of the file
		*/
		rewind( cfPtr ); // return cfPtr to beginning of file
		fscanf( cfPtr, "%d%29s%lf", &account, name, &balance );
		printf( "%-10d%-13s%7.2f\n", account, name, balance );

		fclose( cfPtr ); // fclose closes file
	} //end else

	return EXIT_SUCCESS;
} //end main

