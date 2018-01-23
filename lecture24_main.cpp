/* C++ provide default implementation of assignment operator (Shallow copy)
* We are overloading assignment operator here
* Care should be taken to define 3 things when we overload assignment operator
* 1. Copy constructor
* 2. Assignment operator
* 3. Destructor
*/

#include <iostream>
#include <string>

using namespace std;

class Test {
private:
	int id;
	string name;
public:
	// Constructor
	Test(int id, string name): id(id), name(name) {}
	Test(): id(0), name(""){}
	void print (){
		cout << id << ": " << name << endl;
	}

	Test(const Test &other) {
		cout << "Copy constructor is called" << endl;
		*this = other; // this is what compiler does --> Shallow copy
	}

	//Assignment operator will return const reference of object
	const Test &operator=(const Test &other){
		cout << "Assignment operator overloaded" << endl;
		id = other.id;
		name = other.name;
		return *this; // this pointer is a pointer to current object
		// We should return reference hence we need to de-reference pointer and return it 
	}
};

int main() {
	Test t1(67, "Jack");  
	// Test t1; // This will call constructor
	// Since we overwrite the default constructor 
	// Compiler will throw warning if null constructor is not defined
	t1.print();

	Test t2; // Null constructor
	// Compiler implicitly has assignment operator which does the shallow copy of the object
	t2 = t1;

	t2.operator=(t1); // This is another way of writing the same thing

	t2.print();

	Test t3 = t1; // Now this type of object initialization calls copy constructor and not assignment operator
	t3.print();
	
	return 0;
}