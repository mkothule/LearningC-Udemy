#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<string> strings;
	//vector<string> strings(5);  // Note for defining vector we use "()" round brackets not square brackets
	strings.push_back("mangesh");  // This function pushes the string onto vector
	// Vector is resized internally to store the element
	strings.push_back("madan");
	strings.push_back("kothule");

	// Modifiers
	//strings.pop_back();  // will remove the last element from the vector

 	//capacity
 	cout << "Max size: " << strings.max_size() << endl; // Actual size of the vector is usually higher than 
 	//the elements we have in the strings. this is to avoid reloc call every time the elements is push 

	cout << "Method 1: " << endl;
	for(int i=0; i<strings.size(); i++) // accessing the string vector using integer
		cout << strings[i] << endl;  // "[]" operator is overloaded for vector strings

	vector<string>::iterator it = strings.begin();  // strings.begin() returns a iterator pointing to the start location of the vector
	// "it" iterator is like a pointer
	cout << "Method 2 using iterator" << endl; 
	for(;it != strings.end(); it++) // strings.end() points to location afterthe last element of the array
		cout << *it << endl;  // "*" operator is overloaded for iterator 


	return 0;
}