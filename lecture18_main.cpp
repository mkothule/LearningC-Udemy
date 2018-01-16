#include <iostream>
#include <map>
#include <string>

using namespace std;

// Using user defined class as key in map
// Requirements:
// Print function should be const and shouldnot change class variable
// Need to overload < operator in class so that map can sort out values


class Person {
private:
	int age;
	string name;
	// 3 constructors
public:
	Person() :age(0), name("") {}

	Person(int age, string name) : age(age), name(name) {}

	Person(Person &other) {   // Copy constrauctor
		name = other.name;
		age = other.age;
	}
	
	void print() const {  // without this print as const compilerf throws an error: 
//		Error	C2662	'void Person::print(void)': cannot convert 'this' pointer from 'const Person' to 'Person &'	Lecture18_main.cpp
		cout << "age: " << age << " name: " << name << flush;  // In classes we should only flush the data the user should later decide whether to add endl or not
	}

	bool operator<(const Person &other) const { // Function is not changing membewr variables to function is constant
		//Input argument is also not changing hence parameter passed to function is also constant
		if (age != other.age) {
			return age < other.age;
		}
		else {
			return name < other.name;
		}
	}
};


int main() {
	map <Person, int> people;
	people[Person(100, "Nv")] = 100;
	people[Person(30, "Mike")] = 100;
	people[Person(40, "Ash")] = 11;
	people[Person(35, "Bob")] = 321;

	for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
		 it->first.print();
		 cout << " " <<it->second << endl;
	}
	while (1);
	return 0;
}
