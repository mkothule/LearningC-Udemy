#include <iostream>
using namespace std;

void myfunction();

class test{
public:
	int a;
	test(int in){
		a = in;
	}
};

void nestExp(){
	try{
		myfunction();	
	}
	catch (int e){
		cout << "Experiment: " << e << endl;
	}

	cout << "this will not get executed" << endl;   // Will not run as we dont use try catch in this function
}

void myfunction(){
	bool error =  true;
	bool error2 = false;
	bool error3 = false;

	if (error){
		throw test(9);  // We can use object of a user defined class 
		//throw 8;   // Throwing integer here
	}
	if (error2){
		throw "error2 was true"; // we are sending a character array here
	}
	if (error3){
		throw string("String class object"); // we are instantiating a new class object here 
		// we dont use new like command for doing this in case of exception
		// Compiler knows that this object needs to be created in heap so that is will be available in main
	}

	cout << "Function which throws error will not run after throwing exception" << endl;
}

int main(){
	try{
		myfunction();
	}
	// there can be multiple catch for one try statement
	catch(int e){  // Catching integer here
		cout << "Catching integer: " << e << endl;
	}
	catch(char const * e){ // We can name the variable as "e" here as well because scope of int e in earlier catch statement was limited to that loop only
		cout << "Catching character array:  " << e << endl;
	}
	catch(string &e){  // Always catch reference to object of any class
		cout << "Catching class object:  " <<  e << endl;
	}
	catch (test &e){
		cout << "Catching test class:  " << e.a << endl;
	}

	cout << "This function will run even after exception" << endl;
}
