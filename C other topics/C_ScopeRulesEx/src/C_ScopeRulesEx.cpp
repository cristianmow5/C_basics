//============================================================================
// Name        : C_ScopeRulesEx.cpp
// Author      : Cristian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void useLocal( void ); // function prototype
void useStaticLocal( void ); // function prototype
void useGlobal( void ); // function prototype

int x = 1; // global variable

int main() {

	int x = 5; // local variable to main

	cout << "local x in outer scope of main is " <<  x << endl;

	{ // start new scope
		int x = 7; // local variable to new scope
		cout << "local x in inner scope of main is " << x << endl;
	} // end new scope

	cout << "local x in outer scope of main is " << x << '\n' << endl;

	useLocal(); // useLocal has automatic local x
	useStaticLocal(); // useStaticLocal has static local x
	useGlobal(); // useGlobal uses global x
	useLocal(); // useLocal reinitializes automatic local x
	useStaticLocal(); // static local x retains its prior value
	useGlobal(); // global x also retains its value

	cout << "local x in main is " << x << endl;

	return 0;
}

// useLocal reinitializes local variable x during each call
void useLocal( void )
{
	int x = 25; // initialized each time useLocal is called
	cout << "local x in useLocal is " << x << " after entering useLocal" << endl;
	++x;
	cout << "local x in useLocal is " << x << " before exiting useLocal" << '\n' << endl;
} // end function useLocal

// useStaticLocal initializes static local variable x only the first time
// the function is called; value of x is saved between calls to this
// function
void useStaticLocal( void )
{
	// initialized once before program startup
	static int x = 50;
	cout << "local static x is " << x << " on entering useStaticLocal" << endl;
	++x;
	cout << "local static x is " << x << " on exiting useStaticLocal" << '\n' << endl;
} // end function useStaticLocal

// function useGlobal modifies global variable x during each call
void useGlobal( void )
{
	cout << "global x is " << x << " on entering useGlobal" << endl;
	x *= 10;
	cout << "global x is " << x << " on exiting useGlobal" << '\n' << endl;
} // end function useGlobal
