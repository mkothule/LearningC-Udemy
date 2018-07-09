#include <iostream>

using namespace std;

class Test {

	// instance variable of the class
	int one{1};
	int two{2};

public:
	void run() {
		int three{ 3 };
		int four{ 4 };

		auto plambda = [&, this](){ // [&] this will pass references of local variables three and four only and bot one and two
			// this argument in capture variable will pass one and two
			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
			cout << four << endl;

		};
		plambda();
	}
};

int main(){
	
	Test t1;
	t1.run();

	while (1);
	return 0;
}