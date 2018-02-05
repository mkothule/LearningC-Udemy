#include <iostream>

using namespace std;

// Function pointers
void test() {  // Function defination
	// test is just a lable to the hex code os this function
	cout << "Test" << endl;
}

void test(int a) {
	cout << a << endl;
}

int addition(int a, int b) {
	return a + b;
}

int main() {
	
	/*Method 1
	void (*ptest)(); // this is declaration of function ponter
	// ptest will point to test
	// test function has return type as void hence ptest declaration also has void as return type
	// void * signifies the function tghat return void pointer
	// hence we need to define function pointer as void (*ptest)(--argu list)
	// Since test dont have argument list this part is blank

	ptest = &test;  // Assign value to function pointer

	(*ptest)(); // de-refernce pointer and make call to that location
	*/

	// Method 2
	void (*ptest)() = &test;
	ptest(); // This way also works as test is already a address and ptest is also address


	void (*pntest)(int) = &test; // Since this test function has argument list. We should specify that while declaring a function pointer
	// pntest is a pointer to the function which takes int as argument and returns void
	pntest(23);


	int(*padd)(int, int) = &addition;
	cout << padd(5, 6) << endl;

	while (1);
	return 0;
}