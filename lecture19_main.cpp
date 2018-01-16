// Mutlimap exercise
#include <iostream>
#include <string>
#include <map>

// Multimap allows multiple entries with same key

using namespace std;

int main() {
	multimap<int, string> data;
	//For multimap sqaure brackets cant be used for adding elements
	//.insert should be used

	data.insert(make_pair(30, "Mike"));
	data.insert(make_pair(40, "Bob"));
	data.insert(make_pair(30, "Alice"));
	data.insert(make_pair(20, "Intruder"));

	for (multimap<int, string>::iterator it = data.begin(); it != data.end(); it++) {
		cout << it->first << ": " << flush;
		cout << it->second << endl;
	}
	cout << endl;

	for (multimap<int, string>::iterator it = data.find(30); it != data.end(); it++) {  // Search for elements with same key
		// but this will print all values after that key
		cout << it->first << ": " << flush;
		cout << it->second << endl;
	}
	// To avoid above problem. we can also use following method
	data.insert(make_pair(30, "Homer"));

	cout << endl;
	//data.equal_range(30) // this function returns 2 iterators 1st to start of the 1st element ad second to last elemets
	// Below defination is as per c98 standard
	// pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = data.equal_range(30);

	// better it to use auto keywork and avoid such delcarations
	auto its = data.equal_range(30);

	for (auto it = its.first; it != its.second; it++) {
		cout << it->first << ": " << flush;
		cout << it->second << endl;
	}	
	while (1);
	return 0;
}