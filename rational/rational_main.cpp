#include "rational.h"

using namespace std;

int main(){
	try {
		rational r1(10, 1);
		rational r2(5, 3);
		//r2 = r1.reciprocal();
		cout << r1 << endl << r2 << endl;
		rational r3;
		r3 = r2--;
		//r1 = r2
		//cout << r1 << endl;
		bool flag = r1 == r1;

		cout << endl;
		cout << r3 << "	" << r2 <<endl;
	}
	catch (invalid_argument &e){
		cout << e.what() << endl;
	}
	while (1);
	return 0;
} 