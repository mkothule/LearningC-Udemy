#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

class rational {
private:
	int m_num;
	int m_den;
public:
	rational(int num, int den)  // parameter constructor
	{
		if (den == 0)
			throw invalid_argument("Denominator can't be zero");
		else {
			if (num == 0) {  // Numerator is 0 so my find_factors and find_GCD will not work for this input hencecheking that condition here
				m_num = 0;
				m_den = den;
			}
			else {  // Numberator is not zero
				int gcd = find_GCD(num, den);
				if (den < 0) {
					m_num = -num/gcd;
					m_den = -den/gcd;
				}
				else {
					m_num = num/gcd;
					m_den = den/gcd;
				}
			}
		}		
	}
	rational(rational &other) : m_num(other.m_num), m_den(other.m_den) {}  // Copy constructor
	rational() : m_num(0), m_den(1) {} // Null constructor

	void print() const;
	vector<int> &find_factors(const int number, vector<int> &res) const;  // Find prime factors of a number 
	void print_vector(vector<int> &vect);
	int find_GCD(int, int) const;  // Find GCD from factors of 2 numbers
	
	int getNum() const; // get numerator
	int getDenom() const; // get denominator
	
	rational reciprocal() const;  // return reciprocal
	friend ostream &operator<<(ostream &cout, rational &other);

	// For addition
	rational operator+(const rational &other) const;
	friend rational operator+(const rational &input, const int &other);
	friend rational operator+(const int &other, const rational &input);

	// For substraction
	rational operator-(const rational &other) const;
	friend rational operator-(const rational &input, const int &other);
	friend rational operator-(const int &other, const rational &input);

	// For multiplication
	rational operator*(const rational &other) const;
	friend rational operator*(const rational &input, const int &other);
	friend rational operator*(const int &other, const rational &input);

	//Division
	rational operator/(const rational &other) const;

	//Compound assigment operators
	rational &operator+=(const rational &other);
	rational &operator-=(const rational &other);
	rational &operator*=(const rational &other);
	rational &operator/=(const rational &other);

	//Comaprison operators
	bool operator<(const rational & other) const;
	bool operator>(const rational & other) const;
	bool operator>=(const rational & other) const;
	bool operator<=(const rational & other) const;
	bool operator!=(const rational & other) const;
	bool operator==(const rational & other) const;

	//Pre-increment - returns reference to variable after it has been incremented
	rational & operator++();

	//post-increment - to distinguish between pre and post we pass dummy int argument to post
	// dont use this argument
	const rational & operator++(int);

	//pre-decrement
	rational & operator--();

	//Post-decrement
	const rational & operator--(int);

};