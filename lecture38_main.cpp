// Functors: A class or struct which has overloaded round bracket operator()
// It may or may not have any object or other functions but overloading () operator is must
// It is similar to function pointer but have some advance functionality and can be useful in many cases

#include <iostream>
#include <string>

using namespace std;

// base/super/parent class
// Test is an abstract class and allows base class objects to be passed to other functions
class Test {
public:
	virtual bool operator()(string txt) = 0; // This pure virtual function making this class abstract
};


// Below is an example for Functor
struct MatchTest: public Test{ // Structure is similar to class but all obejcts and functions are public
	virtual bool operator()(string txt) { // This overloading definition makes this struct (/class) a functor
		return txt == "lion";
	}
};

// Function to which we are passing functor object
void checkMatch(string txt, Test &t1) {// Passing reference of base class so if we have multiple derived classes correct virtual function gets called
	if (t1(txt)) { // Again here it looks like we are calling a function name t1 and passing strin txt as argument
		// But actually we are calling overloaded operator of object t1 with an argument txt
		cout << "Matching" << endl;
	}
	else {
		cout << "Not Matching" << endl;
	}
}


int main() {
	MatchTest mt1;
	cout << mt1("Hello") << endl; // This here looks like a function call but we are calling an overloaded operator of an object mt1

	MatchTest mt2;

	checkMatch("lion", mt2); // Pass derived class as argument

	while (1);
	return 0;
}