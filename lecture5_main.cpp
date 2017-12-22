/*
/ This code for creating your own exception class which is derived from exception base class in C++
*/
#include <iostream>
#include <exception>

using namespace std;

class MyException: public exception{ // exception is class already defined in C+
public:
	// Below is the virtual function defined in exception class
	// Each derived class overwrites it
	// const throw() : mean this function can't throw any exception --> Helps compiler to optimize
	// if what function throws 3 exception list them all down in the round brackets
	virtual const char* what() const throw(){
		return "MyException occured";
	}
};


class Test{
public:
	void testfunction(){
		throw MyException();
	}
};


int main(){
	Test t;
	try{
		t.testfunction();
	}catch(MyException &e){
		cout << "Exception returned from test is: " << e.what() << endl;
	}
	return 0;
}