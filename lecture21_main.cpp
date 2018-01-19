#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;


class Test {
private:
	string name;

public: 
	Test(string name) : name(name) {}
	~Test() {}
	
	void print () const {  // Print function is not changing any member variable
		cout << name << endl;
	}
};

int main() {
	stack<int> intStack;
	intStack.push(10);
	intStack.push(100);
	intStack.push(1000);

	// We generally do not iterate through stack or queue
	int var = intStack.top();  // Returns the last added object from stack. Does not remove it from stack
	cout << var << endl;
	intStack.pop();  // Remove the latest added object.. returns void
	int &refer = intStack.top();  // This is a reference to the top object.
	cout << refer << endl;
	
	intStack.pop(); // Now refer still points to top object while top is already removed
	// Dont use refer variable now as the code will be invalid in that case

	cout << endl; 
	intStack.push(562);
	intStack.push(185);

	while (intStack.size() > 0) {
		int &i = intStack.top();
		cout << i << endl;
		intStack.pop();
	}


	cout << endl;

	queue<Test> testQueue;

	testQueue.push(Test("Mangesh"));
	testQueue.push(Test("Madan"));
	testQueue.push(Test("Kothule"));

	Test f1 = testQueue.front(); // New copy of front element is saved in f1
	f1.print();
	Test &b1 = testQueue.back(); // Only reference to back element no new copy generated
	b1.print();


	testQueue.pop(); // Front object is removed

	cout << endl;

	while (testQueue.size() > 0)
	{
		testQueue.front().print();
		testQueue.pop();
	}

	while (1);

	return 0;
}