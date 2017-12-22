/*
/ Writing to output files
*/

#include <iostream>
#include <fstream>  // this is for file stream (header file)

using namespace std;
int main(){
	//ofstream outfile; // ofstream: output file stream class in fstream header

	//#2 Second method
	fstream outfile;

	string name = "PersonalData.txt";
	//outfile.open(name.c_str());
	
	// #2
	outfile.open(name.c_str(),  ios::out);

	if(outfile.is_open()){
		outfile << "Printing some data" << endl;
		for (int i=1; i<=10; i++){
			for (int j=1; j<=i; j++)
			{
				outfile << j << "\t";
			}
			outfile << endl; 
		}
		outfile.close();
	}else{
		cout << "Could not open " << name << endl;
	}
	return 0;
}