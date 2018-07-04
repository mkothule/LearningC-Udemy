// C++98 initializations using curly brackets

#include <iostream>
#include <string>
using namespace std;

int main() {
	int array[] = {1, 4, 6};
	cout << array[0] << endl;

	class C {
	public:  // Only public varaibales can be intialised using this
		string s;
		int i;
	};
	C c1 = {"Hello", 9};  // order should be same as the variables declared in the class
	//C c1 = { "Hello"}; // only string initialization also work
	//C c1 = { 9}; // This will not work as 1st variable is string
	cout << c1.s << endl;

	struct S {
		int i;
		int j;
	}s2 = { 787.990 }, s3 = {145, 632};

	S s1 = {87, 90};


	cout << s2.i << endl;
	while (1);
}