#include <iostream>

using namespace std;

int main() {
	// loca variables of main and not available to lambda expression until passed using capture variables
	int one = 1;
	int two = 2; 
	int three = 3;
	
	[]() {}; // Empty lambda expression
	[]() {}(); // Calling a empty labda expression
	
	//[]() {cout << one << " " << two << endl;}(); // this will not compile

	// Capture one and two by value
	[one, two]() {cout << one << " " << two << endl;}();

	// Default capture all by value
	[=]() {cout << one << " " << two << endl;}();
	
	// Default capture all by value but three by reference
	[=, &three]() {three = 300; cout << one << " " << two << endl;}();
	cout << three << endl;  // changed in lambda expression as it was passed by reference

	// Default capture all by reference
	[&]() {three = 300; two = 200; cout << one << " " << two << endl;}();
	cout << two << endl;  // changed in lambda expression as it was passed by reference

	// Default capture all by reference but one by value
	[&, one]() {three = 300; two = 200; cout << one << " " << two << endl;}();
	cout << two << endl;  // changed in lambda expression as it was passed by reference

	while (1);
	return 0;
}