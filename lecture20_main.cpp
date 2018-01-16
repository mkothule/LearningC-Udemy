#include <iostream>
#include <string>
#include <set>

using namespace std;

class info {
private:
	int age;
	string name;
public:
	info(int age, string name) : age(age), name(name) {}
	void print() const{  // without const we get error
		//Error	C2662	'void info::print(void)': cannot convert 'this' pointer from 'const info' to 'info &'
		cout << "age: " << age << " name: " << name << flush;
	}


	// without this we also get error
	// Error	C2678	binary '<': no operator found which takes a left - hand operand of type 'const info' (or there is no acceptable conversion)	
	bool operator<(const info &other) const {
		if (age < other.age) {
			return age < other.age;
		}
		else {
			return name < other.name;
		}
	
	}
};


int main() {
	/*
	set<double> numbers; // Adds the elemensta and also sort them (even strings are sorted)

	numbers.insert(12.098);
	numbers.insert(5866.326);
	numbers.insert(741596);
	numbers.insert(741596); // only keep unique values
	numbers.insert(0.0003);

	// Accessing ascending set
	for (auto it = numbers.begin(); it != numbers.end(); it++){
		cout << *it << endl;  // If the standard template class has single values <int> in this case. Then directly use * operator to access the value
		// In case of map we get 2 values to we use -> operator to access first and second value
	}

	cout << endl;
	auto itFind = numbers.find(741596);
	if (itFind != numbers.end()) {
		cout << "Found: " << *itFind << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	// other way of doing this
	if (numbers.count(0.00030)) { // returns either 1 or 0 
		cout << "Found " <<  endl;
	}

	cout << endl;
	// Accessing descending set
	for (auto rit = numbers.rbegin(); rit != numbers.rend(); rit++) {  // reverse iterator
		cout << *rit << endl;
	}
	*/
	set<info> data;
	data.insert(info(40, "Homr"));
	data.insert(info(13, "Bart"));
	data.insert(info(20, "Lucy"));
	data.insert(info(20, "Lucy"));  // Since we have our < operator which take into account both age and name
	// if both are equal then only set library will not make duplicate entry for it
	// If we change only 1 value at a time then set will make a new entry
	data.insert(info(10, "Bart"));
	data.insert(info(20, "Marley"));



	for (set<info>::iterator it = data.begin(); it != data.end(); it++) {
		it->print();  // iterator always return const object but it does not know if print also return const hence it needs const ketwork after function name
		cout << endl;
	}

	while (1);
	return 0;
}