#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, int> empid; // like dictionary in python (key, value)
	// key can be anything not string only
	// Same for value it can be float double or string again

	// One way to add elements
	empid["M"] = 23;
	empid["A"] = 56;
	empid["N"] = 9;  // We can't add duplicate entries

	// for checking if a key is present or not use find function otherwise the element with 0 value is created
	cout << empid["G"] << endl;  // intension here was to check if G exist but this will create a G with value as 0
	if (empid.find("S") == empid.end()) {  // find function returns iterator to value if key is found else it point to end of map
		cout << "Key is not present" << endl;
	}
	else {
		cout << "Key is present" << endl;
	}

	// Accessing elements using iterator and -> operator
	cout << "map values are: " << endl;
	for (map<string, int>::iterator it = empid.begin(); it != empid.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}


	// map inherit pair class and each element is a pair
	// another way to add elements
	pair<string, int> newid = { "E", 12 };
	empid.insert(newid);

	// on more way to add elements
	empid.insert(pair<string, int>("H", 521)); // without declaring pair variable
	empid.insert(make_pair("K", 646)); // using in built function to avoid specifies types

	// Another way to access elements
	cout << "map values are: " << endl;
	for (map<string, int>::iterator it = empid.begin(); it != empid.end(); it++) {
		pair<string, int> obj = *it;
		cout << obj.first << ": " << obj.second << endl;
	}
	while (1) {  // manually has to exit this while 1 loop
		string line;
		cout << "Enter the key to be search " << endl;
		cin >> line;
		if (empid.find(line) == empid.end()) {
			cout << "Employee name not found" << endl;
		}
		else {
			cout << "Employee found" << endl << "Details: " << " Name: " << line << " EmpId: " << empid[line] << endl;
		}
	}
	return 0;
}