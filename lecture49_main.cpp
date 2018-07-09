#include <iostream>

using namespace std;

void test(void (*pf)()) {
	pf();
}


int main() {
	[](){};  // this is a valid lambda expression

	[]() {cout << "Hello" << endl;};  // Last curly brackets are for code code will not be called

	[]() {cout << "Hello" << endl;}();  // Here we are calling lambda expression

	void (*pf)() = []() {cout << "Hello" << endl;};  // Assign a function pointer to lambda expression

	pf(); // Call the code using function pointer
	
	test(pf); // Passing function pointer to test and invoking the pf call from test function

	while (1);
	return 0;
}