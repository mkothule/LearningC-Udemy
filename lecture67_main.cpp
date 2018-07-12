// Bind

#include <iostream>
#include <functional> // for bind to work

using namespace std;
using namespace placeholders;  // used for passing arguments

// function
int add(int a, int b, int c)
{
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	return a + b + c;
}

int run(function<int(int, int, int)> func) {
	return func(23, 56, 9);
}

class Test {
public:
	int add(int a, int b) {
		return a + b;
	}
};


	
int main() {
	auto calc = bind(&add, 10, 20, 30);  // arguments are directly provided here
	cout << calc() << endl;

	auto calc1 = bind(&add, _1, _2, _3);   // _1 is a place holder
	cout << calc1(5, 8, 6) << endl;  // 5 is mapped to _1 i.e. sent as arguemnt a to add function
	
	// Changing order of argument is also possible
	auto calc2 = bind(&add, _3, _1, _2);   // _1 is a place holder
	cout << calc2(5, 8, 6) << endl;  // 5 is mapped to _1 but sent as arguemnt b to add function

	// One default arument and others from arguments
	auto calc3 = bind(&add, 100, _1, _2);
	cout << calc3(5, 8) << endl;

	//calc function can also be sent to another function
	cout << run(calc1) << endl;;

	// bind can also be used on methods of class
	Test test; // we need a object of the class to call the method
	auto calc4 = bind(&Test::add, test, _1, _2);  // Test::add should be public

	cout << calc4(100, 800) << endl;

	while (1);
	return 0;
}