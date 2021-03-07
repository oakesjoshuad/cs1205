// Beginning of Source
// Name: Joshua Oakes
// ID No: 2411639
// Course Number and Section: 1205-601
// Date: 06/02/2011
// Assignment: Homework 5

#include <iostream>
using namespace std;

bool isLeap(int year){
    return (year%4==0 && year%400==0) || (year%4==0 && year%100!=0);
}

int daysInMonth(int month, int year){
	if(month == 2 && isLeap(year))
		return 29;
	else if(month == 2 && !(isLeap(year)))
		return 28;
	else if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
}

bool isEndOfMonth(int day, int month, int year){
	return (day == daysInMonth(month, year));
}

bool isEndOfYear(int month){
	return (month == 12);
}

int incrementYear(int year){
	return year + 1;
}

int incrementMonth(int month){
	if(isEndOfYear(month))
		return 1;
	else
		return month + 1;
}

void incrementDay(int &year, int &month, int &day){
	if(isEndOfMonth(day, month, year)){
		day = 1;
		if(isEndOfYear(month)){
			month = incrementMonth(month);
			year = incrementYear(year);
		}
		else
			month = incrementMonth(month);
	}
	else
		day = day + 1;
}

void printDate(int year, int month, int day){
	cout << month << "/" << day << "/" << year << endl;
}

bool isValid(int day, int month, int year){
	return !(day < 1 || day > daysInMonth(month, year) || 
					 month < 1 || month > 12 || 
					 year < 1800 || year > 2100);
}

void process(){
	int year(0);
	int month(0);
	int day(0);
	
	while( day != -1 ){
		cout << "Enter a date (day, month, year): ";
		cin >> day;
		if( day != -1 ){
			cin >> month;
			cin >> year;
			if(isValid(day, month, year)){
				incrementDay(year, month, day);
				printDate(year, month, day);
			}
			else
				cout <<"Invalid Date, ";
		}
	}
}

int main(){

	process();

	return 0;
}