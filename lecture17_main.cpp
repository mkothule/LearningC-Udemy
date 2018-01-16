#include <iostream>
#include <string>
#include <map>

using namespace std;


class Person {
private:
	int age;
	string name;
public: 
	Person() : name(""), age(0) {  // default constructor with no arguments
		// This constructor is must for map to use this class value otherwise map implementation will not work
	}

	Person(string name, int age) : name(name), age(age) {
		cout << "normal constructor is called " << " name: " << name << " age:" << age << endl;
	}
	// A copy constructor is a member function which initializes an object using another object of the same class.
	// Compiler generally generate copy constructor (copies all variables from other object) and this usually works fine if the class variables dont have pointers

	Person(const Person &other) { // Copy constructor: this allows map to copy data from other person objects
		cout << "Copy constructor is called" << " name: " << name << " age:" << age << endl;
		age = other.age;
		name = other.name;
	}

	void print() {
		cout << " age: " << age << " name: " << name << endl;
	}
};


int main() {
	map<int, Person> my_map;

	// Map key values are sorted in ascending order..
	my_map[98] = Person("mangesh", 34); // this will call normal constructor
	my_map[17] = Person("kothule", 12); // this will call normal constructor
	my_map.insert(make_pair(23, Person("erlangen", 275))); // this will call normal constructor
	Person p1 = Person("Germ", 40);
	my_map.insert(make_pair(0, p1)); // This should call copy constructor as p1 object is already created 

	for (map<int, Person>::iterator it = my_map.begin(); it != my_map.end(); it++) {
		cout << "idx: " << it->first << "  " << flush;
		it->second.print();  // This function will anyway print those values
	}
	while (1);
	return 0; 
}