#include <iostream>
#include <vector>

using namespace std;

class Test{
	static const int SIZE = 100;
	int * _pbuf{nullptr};
public:
	Test() {
		cout << "No param constructor" << endl;
		_pbuf = new int[SIZE] {}; // Empty curly brackets will initialize the array to 0
	}

	Test(int i) {
		cout << "param constructor" << endl;
		_pbuf = new int[SIZE];
		for (i = 0;i < SIZE;i++)
			_pbuf[i] = 7 * i;
	}

	Test(Test &other) {
		cout << "Copy constructor" << endl;
		memcpy(_pbuf, other._pbuf, SIZE*sizeof(int));
	}

	~Test() {
		cout << "Destructor" << endl;
		delete [] _pbuf;
	}

	Test(Test &&other) { // move constructor - takes rvalue as input
		// other can not be const as we change it in the code
		cout << "Move constructor" << endl;
		_pbuf = other._pbuf; // other is temporary object as it is rvalue
		other._pbuf = nullptr; // set that pointer to 0 so now when we call destructor for that we will not delete memory _pbuf is pointing to now
	}

	Test &operator=(const Test &other) { // Assignment operator - lvalue reference
		_pbuf = new int[SIZE];
		memcpy(_pbuf, other._pbuf, SIZE*sizeof(int));
		return *this;
	}

	Test &operator=(Test &&other) { // Move assignment operator - rvalue reference
		cout << "move assignment operator" << endl;
		delete [] _pbuf;
		_pbuf = other._pbuf;
		other._pbuf = nullptr;
		return *this;
	}

	friend ostream &operator<<(ostream &out, const Test &other);
};

ostream &operator<<(ostream &out, const Test &other){
	out << "Hello from << operator";
	return out;
}

Test getTest()
{
	return Test();
}

// 2 overloaded functions check taking lvalue and rvalue reference

void check(const int &a) {
	cout << "lvalue reference" << endl;
}

void check(int &&a) {
	cout << "Rvalue reference" << endl;
}

int main()
{
	//lecture 57
	Test test1 = getTest();
	cout << test1 << endl;


	//lecture 58
	// example 
	// int x = 7+9;
	// x is Lvalue and 3+4 is Rvalue
	// Lvalue if value persists beyond expression that defines it. We can take address of them.
	// Rvalue  it evaluates to a temporary value that does not persist beyond the expression that defines it. We cant take address of them

	// IMPORTANT : WE CANT ASSIGN POINTERS TO Rvalues

	//int *x = (7+9); // not possible
	int x = 9;
	int * ptr = &x; // this is fine as x i lvalue
	
	Test *ptest = &test1; // this is also fine

	//Test *ptest = &getTest();  // not valid statement


	//lecture 59: lvalue references in C++11
	Test &refTest1 = test1; //mutable lvalue reference pointing to lvalue

	const Test &refTest2 = getTest(); //const lvalue reference pointing to Rvalue
	// here scopy of the temporary object is extended till its reference is valid


	//lecture 60: rvalue references
	Test &&rTest1 = getTest();  // use double & to define rvalue reference
	
	check(x++);  // Rvalue
	check(++x);  // Lvalue

	//lecture 61: move constructor
	vector<Test> vec;
	vec.push_back(Test()); // move constructor
	// Test() // default no param constructor is called for creating this object temporarily
	// Once pushback is called Test() object will be deleted but since we assign _pbuf to nullptr memory assign will not be deleted
	
	//lecture 62: move assignent operator
	Test test;
	test = getTest(); // rvalue assignment so move assignment operator


	while (1);
	return 0;
}