#include <iostream>
using namespace std;

class allocatememory{
public:
	allocatememory(){  // constructor
		char *ptr = new char[9999999999999999999];  // allocate memory and delete
		delete [] ptr;
		cout << "Constructor called" << endl;
	}
};


int main(){
	try{
		allocatememory a;	
	}
	catch(bad_alloc e){
		cout << "Exception is: " << e.what() << endl;
	}
	

	return 0;
}