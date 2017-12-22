/*
/ Copied from lecture 10
/ Writing binary file
*/

#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1) // use 1 byte alignment in the memory
// if we use 128 here then compiler will allocate 128 bytes for struct
// Alignment should be small and power of 2

struct Person{
	char name[50];   // Dont use string class here as string class stores pointer to memory location where the string is stored and not the actual string
	int age;
	double weight;
};  // total byte count here is 50 + 4 + 8 = 62
// Without progma statements, compiler will do padding and show 64

#pragma pack(pop)  // enable optimization again


/*
/ char: 1 bytes
/ int: 2 bytes
/ double: 4 bytes
*/

int main(){

	Person p1 = {"Mangesh", 27, 65.9};  // quickest way to initialise a struct
	string filename = "test.bin";

	ofstream outfile;
	outfile.open(filename.c_str(), ios::binary);  // must specify that this is binary file. C++ by default consider this as text file

	if (outfile.is_open()){
		outfile.write(reinterpret_cast<char *>(&p1), sizeof(Person));
		outfile.close();
	}else{
		cout << "Could not open file for write: " << filename << endl;
	}

	ifstream infile;
	Person p2 = {};   // Empty structure
	infile.open(filename.c_str(), ios::binary);  // must specify that this is binary file. C++ by default consider this as text file

	if (infile.is_open()){
		infile.read(reinterpret_cast<char *>(&p2), sizeof(Person));
		cout << p2.name << "\t" << p2.age << "\t" << p2.weight << endl;
		infile.close();
	}else{
		cout << "Could not open file for read: " << filename << endl;
	}
	
	return 0;
}