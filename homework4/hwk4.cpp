// Beginning of Source
// Name: Joshua Oakes
// ID No: 2411639
// Course Number and Section: 1205-601
// Date: 06/02/2011
// Assignment: Homework 4

#include <iostream>
using namespace std;

bool isLeap(int year){
    return (year%4==0 && year%400==0) || (year%4==0 && year%100!=0);
}

int getYear(){
	int year(0);
	while( year < 1900 || year > 2100 ){
		cout << "Enter the year (an integer between 1900 .. 2100) : ";
		cin >> year;
	}
	return year;
}

int getMonth(){
	int month(0);
	while( month < 1 || month > 12 ){
		cout << "Enter month of year (an integer between 1 .. 12) : ";
		cin >> month;
	}
	return month;
}

int getDay(int year, int month){
	bool leap = isLeap(year);
	int day;
	string prompt("Enter day of month (an integer between 1 .. ");
	
	if( month == 2 && leap )
		while( day < 1 || day > 29 ){
			cout << prompt << "29) : ";
			cin >> day;
		}
	else if( month == 2 && !leap )
		while( day < 1 || day > 28 ){
			cout << prompt << "28) : ";
			cin >> day;
		}
	else if( month == 4 || month == 6 || month == 9 || month == 11 )
		while( day < 1 || day > 30 ){
			cout << prompt << "30) : ";
			cin >> day;
		}
	else
		while( day < 1 || day > 31 ){
			cout << prompt << "31) : ";
			cin >> day;
		}
		
	return day;
}

void printDate(int year, int month, int day){
	cout << month << "/" << day << "/" << year;
}

void process(){
	int year(0);
	int month(0);
	int day(0);
	
	year = getYear();
	month = getMonth();
	day = getDay(year, month);
	
	printDate(year, month, day);
}

bool cont(){
	// Declaring int variable done to hold user input
	int done(0);
	// Prompting the user for integer input to indicate continue or exit
	cout << endl << endl << "   Enter 1 to continue or 0 to exit: ";
	cin >> done;
	cout << endl << endl;
	
	// If user input is not zero, return true to continue execution of the program
	if( done != 0 )
		return false;
	// Exit the program
	return true;
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