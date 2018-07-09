#include <iostream>
#include <string>

using namespace std;

// default: keywork allows use to specify compiler to add default constructors and operators after we add a constructor for our use
// delete: will allow use to delete the defaults and ask compiler to create error while compiling when we use them

class Test {
	int id{87};
	string str{"Constant"};
public:

	Test(int id) : id(id) {} // Once we define this we lose default constructor
	Test() = default; // This will again make default constructor available to us

	Test(const Test &other) = default; // if we Delete this, copy constructor on line 26 initialization wont work
	Test &operator=(const Test &other) = default; // if we Delete this, assignment on line 30 wont work

	void print() const {
		cout << "id: " << id << " str: " << str << endl;
	}
};

int main() {

	Test t1;
	t1.print();

	Test t2 = t1; // This will call copy constructor
	t2.print();

	t2 = t1;
	t2.print();

	while (1);
	return 0;
}