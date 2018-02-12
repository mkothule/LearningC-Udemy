//Object slicing, variable up casting

#include <iostream>

using namespace std;

class parent { // Parent class or superclass
private: 
	int one;
public:

	parent(const parent &other): one(0) {
	}

	parent(): one(0) {
		cout << "Null constructor in parent" << endl;
	}

	virtual void print() { // Virtual allows child classes to overwrite the 
		// Virtual allows compiler to create table of function pointer and call appropriate function at runtime
		cout << "Parent" << endl;
	}
};


class child : public parent { // Child class, subclass
private:
	int two;
public:
	child() : two(0) {
		cout << "Null construcotr in child" << endl;
	}
	void print() {
		cout << "Child" << endl;
	}

};

int main() {
	child c1;  // creating object of the subclass calls constructor of both super class and that subclass
	// calling print using reference 
	parent &p1 = c1;   // reference to parent object
	p1.print();  // Without virtual keyword this call print function in parent class

	//Calling print using pointer
	//parent *p1 = &c1;
	//p1->print();

	parent p2 = child();  // uses copy constructor
	// p2 variable will do object slicing/ type upcasting
	// two variable in class child will not be throw away after this assignment as parent class copy constructor cant account for initilising that variable
	// Parent class constructor does not know what varibale child class has
	p2.print();
	while (1);
	return 0;
}
