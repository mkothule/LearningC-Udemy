/*
/ Code to parse a text file
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	string name = "Info.txt";  // Double quotes for string
	ifstream infile;

	infile.open(name.c_str());

	if(infile.is_open()){
		string line;
		string value;
		while (!infile.eof()){
			getline(infile, line, ':');  // Single quote for character
			infile >> value;
			infile  >> ws; // ws is inbuilt keyword in C++ 11 for white spaces. This statement reads white spaces from infile and we are not using them
			// 2nd option
			// infile.get();  // this method return one character from file but it there are multiple white spaces after the text content and then new line character then this will not work


			cout << "'" << line << "'-----'" << value << "'" << endl;
		}
	
	infile.close();
	}else{
		cout << "unable to open file: " << name << endl; 
	}
	return 0;
}