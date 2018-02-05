#include <iostream>
#include <string>

using namespace std;

template<class T>  // This make print function a template function
void print(T var) {
	cout << var << endl;
}

template<class T, class K>
class test{
private:
	T obj;
	K name;
public:
	test(T obj, K name): obj(obj), name(name) {} // Constructor
	T getObj() const {
		return obj;
	}
	K getString() const {
		return name;
	}
};


int main() {
	print<string>("Hello");
	print<int>(456);
	print<float>(14.8);
	print<double>(1234567.0765);
	
	// With below way there is no need to have a print function for all classes
	// A template function will print all characters one by one
	test<int, string> t1(12, "Homer");
	print<int>(t1.getObj());
	print<string>(t1.getString());

	print("This will also work"); // C++ infer the datatype from argument and can work with it
	while (1);
	return 0;
}