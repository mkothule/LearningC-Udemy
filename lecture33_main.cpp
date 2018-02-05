#include <iostream>
#include <string>

using namespace std;


template<class T> // We can use typename keyword instead of class
void print(T var) {
	cout << "Template version: " << var << endl;
}

void print(int val) {
	cout << "Non- template version: " << val << endl;
}


template<typename T>
void show() { // Here show does not have any argument
	cout << T() << endl; 
}

int main() {
	print<string>("Hello");
	print<int>(10);

	print(20); //Non template version matches best to this function call
	print<>(70); // Putting <> brackets will indicate compiler to use template version


	// show(); // This will not work as the compiler can not infer the type as there is no argument to show function call
	show<int>(); // this will work and value printed will be default value for int
	// So above is the case where you have to specify the datatype to template function as there is no way for compiler to infer
	// Hence empty datatype will not work this case
	while (1);
	return 0;
}