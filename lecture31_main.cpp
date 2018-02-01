#include <iostream>
#include <string>

using namespace std;

template<class T>  // this class takes one datatype as input
class Test {
private:
	T obj;
public:
	// Constructor
	Test(T obj) {
		this->obj = obj;
	}
	void print() {
		cout << obj << endl; // To make this print work the datatype use speficies should have operator << define
		// In our case we are using string since string it in built datatype operator is already defined
		// So our template class makes this assumption and it is fine to make certain assumptions
	}

	// Copy constructor
	Test(Test<T> &other) {
		obj = other.getObj();
	}

	T getObj() const {
		return obj;
	}

	Test<T> operator+(const Test<T> &other) const {
		return Test<T>(obj + other.getObj());
	}
};


int main() {
	//Test<int> t1(14);
	Test<string> t1("Hello");
	//Test<int> t1(1);
	t1.print();
	Test<string> t2("World");
	//Test<int> t2(4);
	t2.print();
	Test<string> t3("Should change");  // Must have something as null constructor is not possible to define without knowing the datatype
	//Test<int> t3(0);
	t3 = t1 + t2;
	t3.print();
	while (1);
	return 0;
}