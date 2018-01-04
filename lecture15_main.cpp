#include <iostream>
#include <fstream>
#include <string>
#include <list>  // List is doubly link list implementation
// Memory is not allocated in consecutive location
// rather forward and backward pointers are maintained

using namespace std;

void printMenu() {
	cout << endl << endl;
	cout << "1. Create a new list" << endl;
	cout << "2. Remove element from start of list" << endl;
	cout << "3. Remove element from end of list" << endl;
	cout << "4. Add element at the start of the list" << endl;
	cout << "5. Add element at the end of the list" << endl;
	cout << "6. Save the list" << endl;
	cout << "7. Print the list" << endl;
	cout << "8. Exit the program" << endl;
}

void printList(list<int> &numbers) {
	cout << "Current list is " << endl;
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << "\t";
	}
	cout << endl;
}

int main() {
	list<int> numbers;
	int input, value;
	while (1)
	{
		printMenu();
		cin >> input;
		switch (input) {
		case 1: {
			cout << "1. Create new list" << endl;
			cout << "2. Load for the file" << endl;
			cin >> value;
			numbers.clear();
			if (value == 1) {
				for (int i = 0; i < 10; i++) {
				numbers.push_back(i);
				}
			printList(numbers);
			}
			else if (value == 2) {
				ifstream infile;
				infile.open("Saved_list.txt"); //, ios::binary);
				if (infile.is_open()) {
					int length;
					string line;
					getline(infile, line);
					length = stoi(line, nullptr, 10);
					for (int i = 0; i < length; i++) {
						getline(infile, line);
						numbers.push_back(stoi(line, nullptr, 10));
					}
					cout << "1st value is " << length <<  endl;
					printList(numbers);
					infile.close();
				}
				else {
					cout << "Could not open file for reading" << endl;
				}
			}
			else
				cout << "Invalid choice" << endl;
			break;
		}
		case 2: {
			numbers.pop_front();
			printList(numbers);
			break;
		}
		case 3: {
			numbers.pop_back();
			printList(numbers);
			break;
		}
		case 4: {
			cout << "Enter that value to be added" << endl;
			cin >> value;
			numbers.push_front(value);
			printList(numbers);
			break;
		}
		case 5: {
			cout << "Enter that value to be added" << endl;
			cin >> value;
			numbers.push_back(value);
			printList(numbers);
			break;
		}
		case 6: {
			ofstream outfile;
			outfile.open("Saved_list.txt"); //, ios::binary);
			if (outfile.is_open()) {
				outfile << numbers.size() << endl;
				for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
					outfile << *it << endl;
				}
				outfile.close();
				cout << "File saved!!" << endl;
			}
			else {
				cout << "Could not open the file for writing" << endl;
			}
			break;
		}
		case 7: {
			printList(numbers);
			break;
		}
		case 8: {
			exit(0);
		}
		default: {
			cout << "Invalid input" << endl;
			break;
		}
		}
	}
	return 0;
}