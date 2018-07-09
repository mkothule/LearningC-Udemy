#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int compare_with = 50;

bool check(int val) {  // This function should return bool annd take integer as input
	return val > compare_with;
}


class Test {
public: 
	bool operator()(int a) { // Overloading round brackets make a functor
		return a > compare_with;
	}
};


class Add {
public:
	double operator()(double a, double b) {
		return a + b;
	}
};



void run(function<bool(int)> check) { // run function is similar to count_if
	// it take lambda or function pointer or functor as input 
	// run any of that by passing test variable and outputs the result
	// Now to take any calling argument as input we use function<> syntax
	// function<bool(int)> : bool is return type and () brackets has argument list
	int test = 1;
	cout << check(test) << endl;
}

int main()
{
	vector<int> numbers{12, 45, 77, 21, 65, 100};  // 3 values are greater than 50 here

	// function pointer paased here
	int count = count_if(numbers.begin(), numbers.end(), check); // Count_if is a function from algorithm library
	// 1st arg is starting of list
	// 2nd arg is end of list
	// 3rd is function or functor or lambda expression or anything that is callable
	// return the count of varibale which satisfy the condition

	cout << count << endl;


	// Lambda expression passed here
	auto lambda = [](int val) {return val > compare_with;};
	count = count_if(numbers.begin(), numbers.end(), lambda);
	cout << count << endl;

	// functor paased here
	Test t1;
	count = count_if(numbers.begin(), numbers.end(), t1);
	cout << count << endl;


	run(lambda); // Lambda expression
	run(check); // Function pointer
	run(t1); // t1 is object of class Test but since operator() is overloaded it is functor

	// One more example of standard functio type

	function<int(int, int)> add = [](int a, int b) {return a + b;};

	cout << add(6, 8) << endl;


	Add a1;
	cout << a1(56, 89) << endl;
	
	while (1);
	return 0;
}

