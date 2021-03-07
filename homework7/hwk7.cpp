// Name: Joshua Oakes
// ID No: 2411639
// Course Number and Section: 1205-601
// Date: 07/01/2011
// Assignment: Homework 7

#include <iostream>
using namespace std;
const int SIZE = 20;

int getNumber();
void swap(int &alpha, int &beta);
void removePosition(int table[], int &length, int position);
void bubbleSort(int table[], int &length, bool removeDuplicate);
void readIntegers(int table[], int size, int &length);
void displayTable(const int table[], int length, string prompt);
void process();
void instructions();

int main(){
	instructions();
	process();
	return 0;
}

int getNumber(){
	int number(0);
	cin >> number;
	return number;
}

void swap(int &alpha, int &beta){
	int gamma = alpha;
	alpha = beta;
	beta = gamma;
}

void removePosition(int table[], int &length, int position){
	length = length-1;
	for(int index = position; index < length; index++)
		table[index] = table[index+1];	
}

void bubbleSort( int table[], int &length, bool removeDuplicate){
	bool swapped = true;
	for(int end = 0; length - end > 0 && swapped; end++){
		bool swapping = false;
		for(int index = 1; index < length - end; index++){
			if(table[index-1] > table[index]){
				swap(table[index-1], table[index]);
				swapping = true;
			}
			else if(table[index] == table[index-1] && removeDuplicate){
				removePosition(table, length, index);
				index = index-1;
			}
		}
		swapped = swapping;
	}
}

void readIntegers(int table[], int size, int &length){
	int index(0);
	int number = getNumber();
	
	while(number > -1 && index < size){
		table[index] = number;
		index = index + 1;
		if( index < size )
			number = getNumber();
	}
	length = index;
}

void displayTable(const int table[], int length, string prompt){
	cout.width(24);
	cout << right << prompt;
	for(int index=0; index < length; index++){
		cout.width(2);
		cout << right <<  table[index] << " ";
	}
	cout << endl;
}

void process(){
	int table[SIZE];
	int length;
	
	readIntegers(table, SIZE, length);
	cout << endl;
	displayTable(table, length, "Original values: ");
	bubbleSort(table, length, false);
	displayTable(table, length, "Sorted w/ duplicates: ");
	bubbleSort(table, length, true);
	displayTable(table, length, "Sorted w/o duplicates: ");
	cout << endl;
}

void instructions(){
	cout << "Enter between 1 and 20 positive integers, a negative integer ends input:" << endl;
}