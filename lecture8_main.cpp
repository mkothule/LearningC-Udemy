#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	string name = "PersonalData.txt";  // Always use double quotes for string and single quote for one character
	ifstream infile;
	//fstream infile;

	infile.open(name.c_str());
	//infile.open(name.c_str(), ios::in);

	if (infile.is_open()){
		string line;
		cout << "reading file now" << endl;
		while (!infile.eof())
		{
			getline(infile, line);
			cout << line << endl;
		}
	infile.close();
	}else{
		cout << "Could not open the file: " << name << endl;
	}

	return 0;
}