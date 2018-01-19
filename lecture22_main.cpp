/* Sorting vector
* If you always need a sorted array we should use set
* but if you just want to sort the array once then how this can be done
*/
#include <iostream>
#include <algorithm>  // Needed for sort function
#include <string>
#include <vector>

using namespace std;

class Test {
private:
	int id;
	string name;
public:
	Test(int id, string name) : id(id), name(name) {}
	void print() const {
		cout << id << ": " << name << endl;
	}
	/* 
	// required for method 1
	bool operator<(const Test &other) const {
		return id < other.id;
	}*/

	// required for method 2
	friend bool compare(Test &a, Test &b);  // Declare a function here. Friend keyword allows function to access class variables
};

//Function defination
// required for method 2
bool compare(Test &a, Test&b) {
	return a.id < b.id;
};


int main() {
	vector<Test> testVector;

	testVector.push_back(Test(10, "Jack"));
	testVector.push_back(Test(30, "Mery"));
	testVector.push_back(Test(167, "Rock"));
	testVector.push_back(Test(1, "Zoo"));

	// std::sort is a function which can be used for sorting 
	// Method 1: Using operator overloading
	// sort(testVector.begin(), testVector.end());  // This way of calling the function needs < operator to be overloaded in the class defination

	// Method 2: using friend function and passing function to function
	sort(testVector.begin(), testVector.end(), compare); // Passing compare function as an argument to sort function 

	for (int i = 0; i < testVector.size(); i++) {
		testVector[i].print();
	}

	while (1);
	return 0;
}
