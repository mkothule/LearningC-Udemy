#include <iostream>
#include <string>
using namespace std;

// tutorial on argument list to lambda expression
void testpf(void (*pf) (string)) {
	pf("Bingo");
}


void testpDiv(double (*pDiv) (double a, double b)) {
	cout << pDiv(101.85, 56.12) << endl;
}

int main ()
{
	//void (*pf) (string) = [](string name){cout << name << endl;};

	// Same as above
	auto  pf = [](string name) {cout << name << endl;};
	pf("Bob");
	testpf(pf);

	//double (*pDiv) (double, double) = [](double a, double b) {
	auto pDiv = [](double a, double b) -> double { // trailing return type is required otherwise program wont compile
		if (b == 0)
			return 0; // Here we return int
		return a / b;  // Here we return double
	};
	
	cout << pDiv(10.0, 9.0) << endl;
	testpDiv(pDiv);


	while (1);
	return 0;
}