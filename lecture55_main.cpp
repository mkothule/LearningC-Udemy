#include <iostream>
//delegating constructor
// we can call one constructor from another constructor
using namespace std;

class Test {
	int val;
	string s1;
public:
	Test() : Test("Hello") {  // this is delegating constructor feature in C++11
		// in C++98 we will get error for this
		cout << "Constructor with no parameters" << endl;
	}

	Test(string str): s1(str) {
		cout << "Constructor with string parameter" << endl;
	}
};

class Child : public Test {
	//Child() = default; 
};


int main() {
	Test t1;
	Child c1;

	while (1);
	return 0;
}