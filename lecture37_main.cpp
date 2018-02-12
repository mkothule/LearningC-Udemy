#include <iostream>

using namespace std;

class Animal { // if a class a single pure virtual function then that class is called as abstract class
	// We are not allowed to create object of this class. COmpiler will throw an error
public:	
	virtual void run() = 0;
	virtual void speak() = 0; // pure virtual function
};

class Dog: public Animal { // This is still abstarct class as defination of function run is not know at this class
public:
	void speak() {
		cout << "Woof!" << endl;
	}
};

class Labrador : public Dog { // Now this is a concrete class as both speak and run are defined at this level
public:
	void run() {
		cout << "Labrador running" << endl;
	}
};


void test(Animal &a1) { // pass by reference of abstract class is possible
	a1.speak();
}

int main() {
	//Animal a1; // not allowed
	//Dog d1; // not allowed

	Labrador lab; // Allowed as labrador is a concrete class. All function are properly defined 
	lab.run();
	lab.speak();

	// Uses of abstract class
	// We can create pointer and references of abstract class and assign tehn to appropriate object of child classes
	Animal *a1[5]; // creating an array of pointers of abstract class is allowed
	// We are just creating pointers
	
	//Animal a[5]; // Not allowed as this create 5 object of animal class

	a1[0] = &lab;
	a1[0]->run(); // this will work

	// We can also pass parameter to the function which are  of type abstract class

	test(lab);

	while (1);
	return 0;
}