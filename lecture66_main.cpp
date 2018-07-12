#include <iostream>

using namespace std;

class Test {
};

void check(Test &arg) {
	cout << "lvalue" << endl;
}

void check(Test &&arg) {
	cout << "rvalue" << endl;
}

template <typename T>
void call(T &&arg) { // here we define this template function to take rvalue as input but when main paases lvalue reference collapses and lvalue can also be handled
	check(arg);
}

template <typename T>
void call_forward(T &&arg) { // here we define this template function to take rvalue as input but when main paases lvalue reference collapses and lvalue can also be handled
	check(forward<T>(arg)); // forward keyword allows proper mapping of lvalue and rvalue
}



int main() {

	Test test; // test object is lvalue

	call(test); // lvalue function called
	call(Test()); // lvalue function called although Test() is a rvalue this is also because of reference collapsing

	call_forward(test); // lvalue
	call_forward(Test()); // rvalue

	while (1);
	return 0;
}