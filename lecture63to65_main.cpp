#include <iostream>

//static_cast: compile time casting
//dynamic_cast: dynamic cast -> check cast at runtime to check if casting is valid
//reiterprete_cast: less checking than static cast (Best to avoid this)
using namespace std;

class Parent {
public:
	virtual void speak() {
		cout << "Parent" << endl;
	}
};

class Brother : public Parent {};
class Sister : public Parent {};

int main ()
{
	
	Parent p1;
	Brother b1;
	Sister s1;

	Parent *ptr = &p1; //Valid assignment of pointer
	Parent *ptr1 = &b1; //Also valid assignment which is possible in C++
	// Super class pointer pointing to subclass object is valid

	//Brother *ptrbro = ptr1;  // this is not valid and compiler will throw a error
	Brother *ptrbro = static_cast<Brother *>(ptr1); // but in case if we have to cast oit then use static_cast

	ptrbro->speak();
	//static_cast will check is above statement make sense at compile time 
	// so suppose ptr1 is pointing to parent object at compile time but in runtime it might happen it may pointer to sister
	// in that case this cast will not valid and will give unexpected results or crash
	// to avoid this use dynamic cast

	ptr1 = &s1; // with this statement output is nullptr 

	ptrbro = dynamic_cast<Brother *>(ptr1);
	if (ptrbro)
		cout << ptrbro << endl; // Print valid address
	else
		cout << "nullptr" << endl;
	// Gives null if cast is not valid

	// reiterprete_cast: blindly cast the object. Risky and should be always avoided

	while (1);
	return 0;
}