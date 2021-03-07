// Name: Joshua Oakes
// ID No: 2411639
// Course Number and Section: 1205-601
// Date: 06/02/2011
// Assignment: Homework 6

#include <iostream>
using namespace std;

int getNumber(){
	int number(0);
//	cout << "--> ";
	cin >> number;
	return number;
}

int tableMax(int table[], int length){
	int max = table[0];
	for(int index=1; index < length; index++){
		if(table[index] > max)
			max = table[index];
	}
	return max;
}

int tableMin(int table[], int length){
	int min = table[0];
	for(int index=1; index < length; index++){
		if(table[index] < min)
			min = table[index];
	}
	return min;
}

int sumTable(int table[], int length){
	int sum(0);
	for(int index=0; index < length; index++)
		sum = sum + table[index];
	return sum;
}

void range(int table[], int length, int &min, int &max){
	min = tableMin(table, length);
	max = tableMax(table, length);
}

int search(int table[], int length, int key){
	int numberOfMatches(0);
	for(int index=0; index < length; index++){
		if(table[index] == key)
			numberOfMatches = numberOfMatches + 1;
	}
	return numberOfMatches;
}

void readIntegers(int table[], int size, int &length){
	int index(0);
	int number = getNumber();
	
	while(number != 0 && index < size){
		table[index] = number;
		index = index + 1;
		if( index < size )
			number = getNumber();
	}
	length = index;
}

void displayTable(int table[], int length){
	for(int index=0; index < length; index++)
		cout << "table[" << index << "]: " << table[index] << endl;
}

void process(){
	int size(20);
	int table[size];
	int length;
	int key(0);
	
	readIntegers(table, size, length);
	displayTable(table, length);
	cout << endl << "Number of entries in table: " << length << endl;
	cout << "Sum: " << sumTable(table, length) << endl;
	cout << "Range: (";
	cout << tableMin(table, length) << " -- ";
	cout << tableMax(table, length) << ")" << endl;
	
	cout << endl << "Enter a number: ";
	key = getNumber();
	while(key !=0 ){
		cout << endl << key << " Appears " << search(table, length, key) << " time(s)" << endl << endl;
		cout << "Enter another number: ";
		key = getNumber();
	}
	
}

void instructions(){
	cout << "Enter between 1 and 20 positive integers, 0 ends input:" << endl;
}

int main(){
	instructions();
	process();
	return 0;
}