/*
/ Struct padding 
/ Compiler does the padding on struct for effienctly access/work with structures
/ So if you have your structire with 62 bytes the compiler will pad it to make 64 bytes
/ Writing a binary file in this way will not result in storing correct information
/ So we need to disable this padding
*/

#include <iostream>

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
	cout << sizeof(Person) << endl;
	return 0;
}