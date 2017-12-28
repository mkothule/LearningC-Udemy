#include <iostream>
#include <vector>
using namespace std;

void PrintMatrix(vector< vector<int> > &matrix){
	cout << "Printing matrix: " << endl;
	for (int r=0; r<matrix.size(); r++){
		for (int c=0; c<matrix[0].size(); c++){
			cout << matrix[r][c] << "\t" << flush;
		}
		cout << endl;
	}
}

void GetCoFactor(vector< vector<int> > &in_matrix, vector< vector<int> > &temp, int row_num){
	int temp_r = 0, temp_c = 0;
	bool flag = false;
	for (int r=0; r<in_matrix.size(); r++){
		for (int newname=1; newname<in_matrix.size(); newname++){
			//cout << "temp_r " << temp_r << " temp_c " << temp_c << "  |||||||| r " << r << " newname " << newname;
			if (r!=row_num)
			{
				temp[temp_r][temp_c] = in_matrix[r][newname];
				//cout << " --> Element added " << endl;
				if (temp_c == temp.size()-1){
					temp_c = 0;
					temp_r++;
					flag = true;
				}
				else
					temp_c++;
			}			
		}
	}
}

float ComputeDeterminant(vector< vector<int> > &matrix){ // Passing  reference better than using pointer. Also this way is prefered in C++
	if (matrix.size() == 2)
		return ((matrix[0][0]*matrix[1][1]) - (matrix[0][1]*matrix[1][0]));
	else if (matrix.size() == 1)
		return matrix[0][0];
	else{
		float det = 0, sign = 1;
		vector < vector<int> > temp(matrix.size()-1, vector<int>(matrix.size()-1));
		for(int r=0; r<matrix.size(); r++){
			GetCoFactor(matrix, temp, r);
			//cout << "Line number " << r << " Element " << matrix[r][0] << endl;
			//PrintMatrix(temp);
			//cout << ComputeDeterminant(temp);
			det += sign * matrix[r][0] * ComputeDeterminant(temp);
			sign *= -1;
		}
		return det;
	}
}



int main (){

	int size=4;
	vector< vector<int> > matrix(size, vector<int>(size));  // No need to have square matrix 
	// Also there is no restriction on number of elements in a row
	// One row may have 10 elemenst while all others have 3 only. Use push_back function to achieve this
    int mat[4][4] = {
    	{1, 0, 2, -1},
    	{3, 0, 0, 5},
    	{2, 1, 4, -3},
    	{1, 0, 5, 0}};

	cout << "Program to compute determinant of 2x2 matrix" << endl;
	int i = 0;
	for (int r=0; r< matrix.size(); r++){
		for (int c=0; c< matrix[0].size(); c++){
			//matrix[r][c] = ++i;
			matrix[r][c] = mat[r][c]; 
		}
	}
	//	matrix[size-1][size-1] = 10;
	PrintMatrix(matrix);	
	cout << "Determinant is: " << ComputeDeterminant(matrix) << endl;


	return 0;
}