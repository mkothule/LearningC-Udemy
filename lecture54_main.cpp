#include <iostream>
// use of keywork mutable in lambda expression


using namespace std;

int main() {
	
	int count = 90;

	// pass count by value
	[count]() mutable{  
		count = 50;  // with mutable keyword we can change the value here
		cout << count << endl;
	}();// calling a lambda expression

	// value of count in main scope is not change
	cout << count << endl;

	while (1);
	return 0;
}