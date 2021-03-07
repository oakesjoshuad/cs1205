// Beginning of Source
// Name: Joshua Oakes
// ID No: 2411639
// Course Number and Section: 1205-601
// Date: 06/02/2011
// Assignment: Bonus Homework 4

#include <iostream>
using namespace std;

void printMinimum(int minimum){
	cout << "Minimum of sequence is: " << minimum << endl;
}

int getNumber(){
	int result(0);
	cout << "--> ";
	cin >> result;
	return result;
}

int checkMinimum(int minimum, int number){
	if(number < minimum && number > 0)
		return number;
	else
		return minimum;
}

void process(){
	int number(0);
	int minimum = number;
	
	cout << "Enter a sequence of positive integers, zero terminates the sequence:" << endl;
	number = getNumber();
	minimum = number;
	while( number != 0 ){
		number = getNumber();
		minimum = checkMinimum(minimum, number);
	}
	
	printMinimum(minimum);
}

bool cont(){
	// Declaring int variable done to hold user input
	int done(0);
	// Prompting the user for integer input to indicate continue or exit
	cout << endl << endl << "   Enter 1 to continue or 0 to exit: ";
	cin >> done;
	cout << endl << endl;
	
	// If user input is not zero, return true to continue execution of the program
	return (done == 0);
}

int main(){
	// Declaring the continuation boolean variable and initializing to false.
	bool done(false);
	
	// While not done, continue executing the program
	while( !done ){
		// Calling the processing function that gets user input for the polynomial and then calculates the roots.
		process();
		// Calling the cont() function to ask the user to continue or exit.
		done = cont();
	}
	
	return 0;
}