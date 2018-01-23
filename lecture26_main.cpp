/* Complex number class
*/

#include <iostream>

using namespace std;
class Complex_num {
private: 
	double real;
	double imag;
public:
	// Constructor with 2 agrs
	Complex_num(double real, double imag): real(real), imag(imag){}
	// null constructor
	Complex_num(): real(0), imag(0){}
	// Copy constructor
	Complex_num(Complex_num &other){
		*this = other;
	}
	
	void print () const {
		cout << "real part is: " << real << " Imaginary part is: " << imag << endl;
	}

	// Overloading the operator + here
	// this way works
	// We can't return the reference here because as soon as we exit this function  reference wont be valid
	// Compiler will give warning functin still might work but the code will be invalid later
	// So we return the work class object and not reference to it
	Complex_num operator+(const Complex_num &other) const{
		Complex_num res;
		res.real = real + other.real;
		res.imag = imag + other.imag;
		return res; 
	}

	Complex_num operator-(const Complex_num &other) const{
		Complex_num res;
		res.real = real - other.real;
		res.imag = imag - other.imag;
		return res; 
	}

	// This is similar to what we did in previous assisgnment 
	friend ostream &operator<<(ostream &cout, Complex_num &other){
		if (other.imag > 0) 
		cout << "Complex number is: " << other.real << "+" << other.imag << "i" ;
		else
		cout << "Complex number is: " << other.real << other.imag << "i" ;
		
	}

	// Multiplication 
	Complex_num operator*(const Complex_num &other) const{
		Complex_num res;
		res.real = (real * other.real) - (imag * other.imag);
		res.imag = (real * other.imag) + (imag * other.real);
		return res; 
	}

	//Assignment
    // Should return reference to the same object otherwise the program will go in infinite loop
	const Complex_num &operator=(const Complex_num &other) {
		//cout << "Assignement operator is called " << endl;
		real = other.real;
		imag = other.imag;
		return *this;
	}

	// Can be used in division
	const Complex_num get_conjugate() const {
		Complex_num res;
		res = *this;
		res.imag = -1*imag;
		return res;
	}

	// multiplication logic using 2 different methods
	Complex_num operator/(const Complex_num &other) const {
		Complex_num conju;
		conju = other.get_conjugate();
		// Method 1
		//Without using overloaded division operator 
		//Complex_num denominator((conju.real * other.real) - (conju.imag * other.imag), (conju.real * other.imag) + (conju.imag * other.real));
		//Complex_num numerator((conju.real * real) - (conju.imag * imag), (conju.real * imag) + (conju.imag * real));
		

		// Method 2
		Complex_num denominator;
		denominator = conju * other;
		Complex_num numerator;
		numerator = *this * conju;
		
		numerator.real /= (denominator.real + denominator.imag); 
		numerator.imag /= (denominator.real + denominator.imag);
		return numerator;
	}
};



 int main () {
 	Complex_num c1(3, 0);
 	Complex_num c2(2, 1);
/*
 	c1.print();
 	c2.print();

 	Complex_num c3;
 	c3 = c1 + c2;
 	cout << "Addition results: " << c3 << endl;

 	Complex_num c4;
 	c4 = c1*c2;

 	cout << "Multiplication results: " << c4 << endl;

 	Complex_num c5;
 	c5 = c3;
 	cout << "Assignment results: " <<  c5 << endl;

 	c5 = c1- c2;
 	cout << "Subtraction results: " << c5 << endl;

 	c4 = c3.get_conjugate();
 	*/
 	Complex_num c6;
 	c6 = c1 / c2;
 	cout << "Division: " << c6 << endl;
 	return 0;
 }


