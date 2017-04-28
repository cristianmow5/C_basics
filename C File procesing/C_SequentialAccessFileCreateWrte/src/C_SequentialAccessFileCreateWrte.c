/*
 ============================================================================
 Name        : C_SequentialAccessFileCreateWrte.c
 Author      : Cristian Mosquera
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	unsigned int account; // account number
	char name[ 30 ]; // account name
	double balance; // account balance

	FILE *cfPtr; // cfPtr = clients.dat file pointer

	setbuf(stdout, NULL); //disable the buffer

	// fopen opens file. Exit program if unable to create file
	if ( ( cfPtr = fopen( "clients.dat", "w" ) ) == NULL ) {
		puts( "File could not be opened" );
	} // end if
	else {
		puts( "Enter the account, name, and balance." );
		puts( "Enter EOF to end input." );
		printf( "%s", "? " );
		scanf( "%d%29s%lf", &account, name, &balance );

		// write account, name and balance into file with fprintf
		while (!feof( stdin )) {
			fprintf( cfPtr, "%d %s %.2f\n", account, name, balance );
			printf( "%s", "? " );
			scanf( "%d%29s%lf", &account, name, &balance );
		} // end while

		fclose( cfPtr ); // fclose closes file
	} //end else

	return EXIT_SUCCESS;
} //end main

/*
 * 	100 Jones 24.98
	200 Doe 345.67
	300 White 0.00
	400 Stone -42.16
	500 Rich 224.62
	-> PRESS ^Z (Ctrl + Z)
 *
 *
 *
 * */
