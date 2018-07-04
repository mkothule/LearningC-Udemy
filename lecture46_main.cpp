//C++11 initialization
// {} are overloaded to allow initialization

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	// No need to use = sign as in case of C++98
	int arr[]{ 1,2,3 }; // array of 3 elements 
	int arr1[5]{}; // array of 5 elements with all elements set to 0

	cout << arr[2] << endl;
	cout << arr1[3] << endl;

	int value{10};

	string text{"text"};

	cout << text << endl;


	vector<int> numbers{1,2,3,4,5,6};

	cout << numbers[5] << endl;

	int *ptr{}; // this set the pointer to nullptr
	// nullptr is a new keyword added to C++11

	int *ptr1{&value};
	cout << *ptr1 << endl;

	int *ptr3 = new int[3]{ 9,8,7 };

	while (1);
	return 0;

}