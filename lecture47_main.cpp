#include <iostream>
#include <string>
#include <vector>
#include <initializer_list> // header files which allows iterable input in constructor and functions
using namespace std;

template <typename T>
class Test {
public:
	Test(initializer_list<T> data) { // Array as input to constructor.. Array can have any number of elelments
		for (auto d : data)
			cout << d << endl;
	}

	void print(initializer_list<T> data) const {
		for (auto d : data)
			cout << d << endl;
	}

};


template <typename T>
class Ring {
	int pos;
	int size;
	T * ring_buf;
public:
	Ring(initializer_list<T> data): size(data.size()), pos(data.size()-1) {
		ring_buf = new T[data.size()];
		int idx = 0;
		for (auto d : data) {
			ring_buf[idx++] = d;
		}
	}

	void print() const {
		cout << "Printing ring content" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << ring_buf[i] << endl;
		}
	}
	
	void add(initializer_list<T> data) {
		for (auto d: data) {
			pos = (pos == size - 1) ? 0 : pos + 1;
			ring_buf[pos] = d;
		}
	}
};

int main()
{
	vector<int> numbers{1,2,3,4}; // C++ way of initialization

	for (auto i : numbers)
		cout << i << endl;

	// user defined class initialize in this way
	Test<string> t1{"Row", "Col", "Image"};
	t1.print({ "One", "Two" });

	Ring<string> r1{"Eine", "Zwei", "Drei"};
	r1.print();
	r1.add({"Vier" , "Funf"});
	r1.print();

	while (1);
	return 0;
}