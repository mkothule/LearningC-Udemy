/* << - left bit shift operator has left right associativity
* Should return reference to "ostream" as cout is of object of ostream class
* 2 parameters should be passed cout and test class object 
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

	// friend is necessary to access member variables of the function
	// Although this function is a member function of the class, friend keyword is necessary here 
	friend ostream &operator<<(ostream &cout, const Test& other){  // If we dont specify friend keyword here then compiler will not allow this operator to use id and name 
		cout << other.id << ": " << other.name;
	}

};

int main() {
	Test t1(67, "Jack");  

	cout << t1 << endl;
	// To make above statement work we need to overload the left bit shift operator
	// cout is a object of class ostream
	// Our overloaded operator should return reference to ostream class
 	
 	Test t2(89, "Bob");
 	cout << t1 << t2 << endl;
 	//<< operator has left to right associativity
 	// so cout << t1 is executed 1st and then on the return object of this methos we pass t2 and so on
	
	return 0;
}