#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
	Test() {
		cout << "Constructor" << endl;
	}

	~Test() {
		cout << "Destructor" << endl;
	}

	void greet() {
		cout << "Hello" << endl;
	}
};


int main() {

	{// brackets restricts the scope of variables
		// Mmeory allocation done dynamically
		unique_ptr<int> ptr(new int); // unique_ptr is a  template takes template class as input
		// Need not to worry about deallocation

		*ptr = 90;
		cout << *ptr << endl;


	}

	// Below wont compile
	//cout << *ptr << endl; // deleted internally as scope of ptr is finished

	{
		unique_ptr<Test> tptr(new Test); // this is similar to auto_ptr
		// but auto_ptr is depreciated and cant handle array

		tptr->greet();

		unique_ptr<Test[]> tptrarr(new Test[2]); // array declaration
		tptrarr[1].greet();

	}

	cout << "Finished" << endl; // desctrutor will be called before finished

	// lecture 69 : shared pointer
	// shared pointer does not delete memory until all variables point to it are out of scope
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	shared_ptr<Test> p1(nullptr);
	{
		shared_ptr<Test> p2(new Test);
		p1 = p2; // p2 is assigned to p1
	} // at this point p2 goes out of scope but memory is not deleted as p1 is still pointing to it

	cout << "Finished" << endl;
	// after finished is printed the destructor will be called

	while (1);
	return 0;
}