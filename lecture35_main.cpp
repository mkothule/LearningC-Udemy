#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // this header file has counf_if function


using namespace std;

// match is function which counts the size of the string
// if size is 3 terurns true else false
bool match(string name) {
	return name.size() == 3;  // Function terurn true = 1 is string has size 3 else false = 0
}


// countThree takes vector as input and pointer to another function which it needs to evaulate the text size()
// Iterate over all values in vector and call match for every string and return the final count
int countThree(vector<string> &texts, bool(*pmatch)(string)) {
	int cnt = 0;
	for (vector<string>::iterator it = texts.begin(); it != texts.end(); it++) {
		cnt += pmatch(*it);
	}
	return cnt;
}


int main() {
	vector<string> texts;
	texts.push_back("One");
	texts.push_back("Two");
	texts.push_back("Three");
	texts.push_back("Four");
	texts.push_back("Five");
	texts.push_back("Six");
	texts.push_back("Seven");

	// count_if function is in-built function in algorithm header files which returns how many times function match evaluated true on texts vector
	//cout <<count_if(texts.begin(), texts.end(), match) << endl;

	// writing our own function to do same task as count_if

	cout << countThree(texts, match) << endl; // or  countThree(texts, &match): this is also work 


	while (1);
	return 0;
}
