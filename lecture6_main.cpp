/*
/ Exception catching in right order 
/ Catch sub classes exception 1st and then parent class exception
*/
#include <iostream>
#include <exception>

using namespace std;

void goesWrong(){
	bool error1 = true;
	bool error2 = false;
	if(error1){
		throw bad_alloc();
	}
	if(error2){
		throw exception();
	}
}

int main(){
	try{
		goesWrong();
	}
	catch(bad_alloc &e){  // this is the correct order for catching exception
		// if we put exception class here instead of bad alloc then since bad alloc derives from parent class exception
		// Polymorphism allows that throw as exception and all catch statement for sub classes later is useless
		// To avoid this always use subclasses 1st then parent class
		cout << " In bad alloc: Got " << e.what()<< endl;	
	}
	catch(exception &e){
		cout << "In exception: got " << e.what()<< endl;
	}

	return 0;
}