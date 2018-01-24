#include "rational.h"


void rational::print() const {
	cout << "Numerator is: " << m_num << " Denominator is: " << m_den << endl;
}

vector<int> & rational::find_factors(const int number, vector<int> &res) const{
	int value = number;
	bool flag = true;
	while (value != 1 ) {
		flag = true;
		for (int i = 2; i <= value && flag; i++) {
			if ((value % i) == 0)
			{
				value = value/ i;
				res.push_back(i);
				flag = false;
			}
		}
	}	
	return res;
}

void rational::print_vector(vector<int> &vect) {
	cout << "Vector is " << flush;
	for (auto it = vect.begin(); it != vect.end(); it++){
		cout << *it << " " << endl;
	}
}

int rational::find_GCD(int num, int den) const{
	int gcd = 1;
	vector<int> res1, res2;
	res1 = find_factors(abs(num), res1);
	res2 = find_factors(abs(den), res2);
	for (vector<int>::iterator it = res1.begin(); it != res1.end(); it++) {
		auto loc = find(res2.begin(), res2.end(), *it);
		if (loc != res2.end()){	
			gcd *= *loc;
			res2.erase(loc);
		}
	}
	return gcd;
}


int rational::getNum() const // get numerator
{
	return m_num;
}

int rational::getDenom() const // get denominator
{
	return m_den;
}

rational rational::reciprocal() const // return reciprocal
{
	if (m_num == 0)
		throw invalid_argument("Reciprocal: Numerator of original number is 0");
	else
		return rational(m_den, m_num);
}

ostream &operator<<(ostream &cout, rational &other) {
	if (other.getDenom() == 1)
		cout << "Rational number is: " << other.getNum() << flush;
	else 
		cout << "Rational number is: " << other.getNum() << "/" << other.getDenom() << flush;
	
	return cout;
}

//Addition
rational rational::operator+(const rational &other) const {
	int res_num = m_num*other.getDenom() + m_den * other.getNum();
	int res_den = m_den * other.getDenom();
	return rational(res_num, res_den);
}

rational operator+(const rational &input, const int &other){
	int res_num = input.getNum() + input.getDenom()*other;
	return rational(res_num, input.getDenom());
}

rational operator+(const int &other, const rational &input) {
	return (input + other);
}

//Subtraction
rational rational::operator-(const rational &other) const {
	int res_num = m_num*other.getDenom() - m_den * other.getNum();
	int res_den = m_den * other.getDenom();
	return rational(res_num, res_den);
}

rational operator-(const rational &input, const int &other) {
	int res_num = input.getNum() - input.getDenom()*other;
	return rational(res_num, input.getDenom());
}

rational operator-(const int &other, const rational &input) {
	return (input - other);
}


//Mutliplication
rational rational::operator*(const rational &other) const {
	return rational(m_num*other.getNum(), m_den*other.getDenom());
}

rational operator*(const rational &input, const int &other) {
	return rational(other*input.getNum(), input.getDenom());
}
rational operator*(const int &other, const rational &input) {
	return (input*other);
}

//Division
rational rational::operator/(const rational &other) const {
	return *this*other.reciprocal();
}


// Compund assigment operators
//addition
rational & rational::operator+=(const rational &other) {
	*this = (other + *this);
	return *this;
}

rational & rational::operator-=(const rational &other) {
	*this = (*this - other);
	return *this;
}
rational & rational::operator*=(const rational &other) {
	*this = (other * *this);
	return *this;
}

rational & rational::operator/=(const rational &other) {
	*this = (*this /other);
	return *this;
}

//Comparison operators
bool rational::operator<(const rational & other) const{
	return (double(m_num) / double(m_den)) < (double(other.getNum()) / double(other.getDenom()));
}


bool rational::operator>(const rational & other) const {
	return (double(m_num) / double(m_den)) > (double(other.getNum()) / double(other.getDenom()));
}

bool rational::operator>=(const rational & other) const {
	return (double(m_num) / double(m_den)) >= (double(other.getNum()) / double(other.getDenom()));
}

bool rational::operator<=(const rational & other) const {
	return (double(m_num) / double(m_den)) <= (double(other.getNum()) / double(other.getDenom()));
}

bool rational::operator!=(const rational & other) const {
	return (double(m_num) / double(m_den)) != (double(other.getNum()) / double(other.getDenom()));
}


bool rational::operator==(const rational & other) const {
	return (double(m_num) / double(m_den)) == (double(other.getNum()) / double(other.getDenom()));
}

//Pre-increment
rational & rational::operator++() {
	*this = *this + 1;
	return *this;
}

//post-increment
const rational & rational::operator++(int) {
	rational ret = *this;
	*this = *this + 1;
	return ret;
}

//pre-decrement
rational & rational::operator--() {
	*this = *this - 1;
	return *this;
}

//Post-decremnt
const rational & rational::operator--(int) {
	rational ret = *this;
	*this = *this - 1;
	return ret;
}