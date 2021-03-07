// Beginning of source
// ID No: 2411639
// Course Number and Section: 1205-601
// Date: 06/02/2011

#include <iostream>
using namespace std;

int main(){
	// Variable declaration
	int length, width, height, volume;
	
	// Recieve length input
	cout << "Enter the length: " << endl;
	cin >> length;
	
	// Recieve width input
	cout << "Enter the width: " << endl;
	cin >> width;
	
	// Recieve height input
	cout << "Enter the height: " << endl;
	cin >> height;
	
	// Calculate and display volume
	volume = length * width * height;
	cout << "The volume is: " << volume << endl;
	
	return 0;
}
// Ending of source