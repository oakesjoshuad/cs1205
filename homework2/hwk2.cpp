// Beginning of Source
// Name: Joshua Oakes
// ID No: 2411639
// Course Number and Section: 1205-601
// Date: 06/02/2011
// Assignment: CHANGETHIS

#include <iostream>
#include <cmath>
using namespace std;

// Calculating whether the equation has real roots or not
bool hasRealRoots( int a, int b, int c ){		
	return (b*b-4*a*c >= 0);
}

// Get the user input for coefficients, using a prompt and an integer to signify which coefficient is being recieved
int getCoefficient( string prompt, int coefficient ){
	int result;
	cout << prompt << endl;
	cin >> result;
	
	// Checking if the first coefficient is 0 and setting to 1 if so
	if( coefficient == 1 && result == 0 ){
		cout << "		A coefficient improperly set to 0, setting to 1..." << endl << endl;
		return 1;
	}
	else {
		return result;
	}
}

// Calculate the positive root and return a double
double getPosRoot( int a, int b, int c ){
	return ((-b+sqrt(b*b-4*a*c))/(2*a));
}

// Calculate the negative root and return a double
double getNegRoot( int a, int b, int c ){
	return ((-b-sqrt(b*b-4*a*c))/(2*a));
}

// Printing the equation and their respective roots
void printRoots( int a, int b, int c, double posRoot, double negRoot ){
	cout << "The polynomial " << a << "X**2";
	
	// Checking if the coefficients are positive, negative or if they exist to correctly form the equation
	if( b > 0 ) {
		cout << "+" << b << "X";
	}
	if( b < 0 ){
		cout << b << "X";
	}
	if( c > 0 ) {
		cout << "+" << c;
	}	
	if( c < 0){
		cout << c;
	}
	
	// Checking if there is only one real root
	if( posRoot == negRoot ){
		cout << " has one real root. The root is " << posRoot << "." << endl;
	}
	// Printing the two real roots
	else {
		cout << " has two real roots. The roots are " << posRoot << " and " << negRoot << "." << endl;
	}
}

// Print the equation and notify there are no real roots
void noRoots( int a, int b, int c ){
	cout << "The polynomial " << a << "X**2";
	
	// Checking if coefficients are positive, negative or if they exist to correctly form the equation
	if( b > 0 ) {
		cout << "+" << b << "X";
	}
	if( b > 0 ) {
		cout << b << "X";
	}
	if( c > 0 ) {
		cout << "+" << c;
	}	
	if( c < 0 ){
		cout << c;
	}
	
	cout << " has no real roots." << endl;
}

int main(){
	// Initilizing variables
	int a;
	int b;
	int c;
	double posRoot;
	double negRoot;
	
	// Getting the coefficients of the quadratic equation 
	a = getCoefficient("Enter the A coefficient", 1);
	b = getCoefficient("Enter the B coefficient", 2);
	c = getCoefficient("Enter the C coefficient", 3);
	
	// If the equation has real roots, calculate the roots and print the results
	if( hasRealRoots(a, b, c) ){
		posRoot = getPosRoot( a, b, c );
		negRoot = getNegRoot( a, b, c );
		printRoots( a, b, c, posRoot, negRoot );
	}
	// If the equation does not have real roots, print the equation and notify for no real roots
	else {
		noRoots( a, b, c );
	}
	
	return 0;
}