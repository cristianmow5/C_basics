/*
 ============================================================================
 Name        : C_exit_aexit.c
 Author      : Cristian
 Version     :
 Copyright   : Your copyright notice
 Description :	The program prompts the user to determine whether the
 	 	 	 	program should be terminated with exit or by reaching
 	 	 	 	the end of main. Function print is executed at program
 	 	 	 	termination in each case.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print( void ); // prototype
void print2( void ); // prototype
void print3( void ); // prototype

int main(void) {

	setbuf(stdout,NULL);

	int answer; // user's menu choice

	atexit( print ); // register function print
	atexit( print2 ); // register function print
	atexit( print3 ); // register function print

	puts( "Enter 1 to terminate program with function exit"
			"\nEnter 2 to terminate program normally" );
	scanf( "%d", &answer );

	// call exit if answer is 1
	if ( answer == 1 ) {
		puts( "\nTerminating program with function exit" );
		exit( EXIT_SUCCESS );
	} // end if

	puts( "\nTerminating program by reaching the end of main" );

	return EXIT_SUCCESS;
}

// display message before termination
void print( void )
{
	puts( "Executing function print at program");
} // end function print

// display message before termination
void print2( void )
{
	puts( "Executing function print2 at program");
} // end function print2

// display message before termination
void print3( void )
{
	puts( "Program terminated");
} // end function print3
