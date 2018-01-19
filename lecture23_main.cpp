/* Building complex STL */
#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, list<int>> scores;
	// 2 Students A and B have scores as follows
	// A gave 3 exams so has 3 score and only 1 for B
	scores["A"].push_back(100);
	scores["A"].push_back(97);
	scores["A"].push_back(61);
	scores["B"].push_back(30);

	// Now to iterate through all the data we will need 2 for loops 
	// One for iterating over all map keys
	// One for iterating over all values for that key

	for (map<string, list<int> >::reverse_iterator rit = scores.rbegin(); rit != scores.rend(); rit++) {
		// To access map we use ->first and ->second
		cout << rit->first  << "  " << flush;

		for (list<int>::iterator it = rit->second.begin(); it != rit->second.end(); it++) {
			// To access value of list item we use overloaded star * operator 
			cout << *it << "  " << flush;
		}
		cout << endl;
	}

	while (1);

	return 0;
}

