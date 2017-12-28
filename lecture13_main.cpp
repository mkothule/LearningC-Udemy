#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<float> numbers(10, 0); // initially there are 10 elements in the array all initialised to 0

	int capacity = numbers.capacity();  // Not same as size. Capacity is the size decided by compiler
	for (int i=0; i<10000; i++)
	{
		numbers.push_back(i);
		if (capacity != numbers.capacity()){
			capacity = numbers.capacity();
			cout << "capacity: " << capacity;  // internal size: increases exponentially to avoid rellocation of memory everytime
			cout << "  Size : " << numbers.size() << endl; // number of elements which were actually added to the vector 
		}
	}

	numbers.clear(); // this will clear all the elements so size will be 0 but capacity will be same
	cout << "capacity: " << capacity;  // internal size: increases exponentially to avoid rellocation of memory everytime
	cout << "  Size : " << numbers.size() << endl; // number of elements which were actually added to the vector 

	numbers.reserve(1000); // we will the compiler to reserve 1000 bytes but size is still 0 
	cout << "capacity: " << capacity;  // internal size: increases exponentially to avoid rellocation of memory everytime
	cout << "  Size : " << numbers.size() << endl; // number of elements which were actually added to the vector 

	return 0;
}