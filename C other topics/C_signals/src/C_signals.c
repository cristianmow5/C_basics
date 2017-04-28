/*
 ============================================================================
 Name        : C_signals.c
 Author      : Cristian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signalHandler( int signalValue ); // prototype

int main(void) {

	int i; // counter used to loop 100 times
	int x; // variable to hold random values between 1-50

	signal( SIGINT, signalHandler ); // register signal handler
									// SIGINT = Receipt of an interactive
									// attention signal.
	srand( time( NULL ) );

	// output numbers 1 to 100
	for ( i = 1; i <= 100; ++i ) {
		x = 1 + rand() % 50; // generate random number to raise SIGINT
		// raise SIGINT when x is 25
		if ( x == 25 ) {
			raise( SIGINT );
		} // end if
		printf( "%4d", i );
		// output \n when i is a multiple of 10
		if ( i % 10 == 0 ) {
			printf( "%s", "\n" );
		} // end if
	} // end for

	return EXIT_SUCCESS;
} //end main

void signalHandler( int signalValue )
{
	int response; // user's response to signal (1 or 2)
	printf( "%s%d%s\n%s",
			"\nInterrupt signal ( ", signalValue, " ) received.",
			"Do you wish to continue ( 1 = yes or 2 = no )? " );
	scanf( "%d", &response );
	// check for invalid responses
	while ( response != 1 && response != 2 ) {
		printf( "%s", "( 1 = yes or 2 = no )? " );
		scanf( "%d", &response );
	} // end while
	// determine whether it's time to exit
	if ( response == 1 ) {
		// reregister signal handler for next SIGINT
		signal( SIGINT, signalHandler );
	} // end if
	else {
		exit( EXIT_SUCCESS );
	} // end else
} // end function signalHandler
