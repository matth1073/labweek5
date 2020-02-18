#include <iostream>
#include <vector>

using namespace std;
void displayVector(vector<vector<int>> vect);
vector<vector<int>> create2dVector();
char menu();
bool canAdd(vector<vector<int>> matrix1, vector<vector<int>> matrix2);
void addMatrices(vector<vector<int>> m1, vector<vector<int>> m2);
bool canMult(vector<vector<int>> matrix1, vector<vector<int>> matrix2); 
void multMatrices(vector<vector<int>> m1, vector<vector<int>> m2);

int main() {
	vector<vector<int>> matrixOne, matrixTwo; 
	int matrixSelection; 
	char sel; 

	while (true) {
		sel = menu(); 
		if (sel == 'q') {
			cout << "Closing program" << endl;
			break; 
		}
		switch (sel) {
		case 'd':
			cout << "Matrix One" << endl; displayVector(matrixOne); cout << endl;
			cout << "Matrix Two" << endl; displayVector(matrixTwo); cout << endl;
			break;

		case 'c':
			cout << "Which matrix (1) or (2) ==> "; cin >> matrixSelection; cout << endl;
			if (matrixSelection == 1) {
				matrixOne = create2dVector();
			}
			else if (matrixSelection == 2) {
				matrixTwo = create2dVector();
			}
			else {
				cout << "Invalid matrix selected" << endl;
			}
			break;

		case 'a':
			if (canAdd(matrixOne, matrixTwo)) {
				addMatrices(matrixOne, matrixTwo); 
			}
			break;
		case 'm':
			if (canMult(matrixOne, matrixTwo)) {
				multMatrices(matrixOne, matrixTwo);
			}  
		}
	}
}

void displayVector(vector<vector<int>> vect)
{
	for (int i = 0; i < vect.size(); ++i) {
		for (int j = 0; j < vect.at(i).size(); ++j) {
			cout << vect.at(i).at(j) << " "; 
		}
		cout << endl; 
	}
}

vector<vector<int>> create2dVector()
{
	vector<vector<int>> vect;
	int insertNumber, row, col;
	
	cout << "Number of rows ==> "; cin >> row; cout << endl; 
	cout << "Number of cols ==> "; cin >> col; cout << endl; 

	vect.resize(row);
	
	for (int i = 0; i < row; ++i) {
		vect.at(i).resize(col);
		for (int j = 0; j < col; ++j) {
			cout << "Please enter a number at " << i << j << "==> "; cin >> insertNumber;
			vect.at(i).at(j) = insertNumber; 
			cout << endl; 
		}
	}
	return vect;
}

char menu()
{
	char sel = '#';
	while (true) {
		cout << "Menu options" << endl; 
		cout << "===========================" << endl; 
		cout << "(D)isplay Matrices" << endl; 
		cout << "(C)reate or (C)hange Matrix" << endl;
		cout << "(A)dd matrices" << endl; 
		cout << "(M)ultipy matrices" << endl; 
		cout << "(Q)uit program" << endl; 
		cout << "===========================" << endl; 
		cout << "Enter choice ==> "; cin >> sel; cout << endl; 
		sel = tolower(sel);
		if (sel == 'd' || sel == 'c' || sel == 'a' || sel == 'm' || sel == 'q') {
			return sel; 
		}
		else {
			cout << "Invalid option, please try again" << endl; 
		}

	}
	return 0;
}

bool canAdd(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	if (matrix1.size() == NULL || matrix2.size() == NULL) {
		return false; 
	}
	if (matrix1.size() != matrix2.size()) {
		cout << "Unable to add" << endl; 
		return false; 
	}
	if (matrix1.at(0).size() != matrix2.at(0).size()) {
		cout << "Unable to add" << endl; 
		return false; 
	}
	return true; 
}

void addMatrices(vector<vector<int>> m1, vector<vector<int>> m2)
{
	vector<vector<int>> sumMatrix; 
	sumMatrix.resize(m1.size());
	for (int i = 0; i < m1.size(); ++i) {
		sumMatrix.at(i).resize(m1.at(i).size());
		for (int j = 0; j < m1.at(i).size(); ++j) {
			sumMatrix[i][j] = m1[i][j] + m2[i][j]; 
		}
	}
	displayVector(sumMatrix); 
}

bool canMult(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{

	if (matrix1.size() == NULL || matrix2.size() == NULL) {
		cout << "Unable to multiply" << endl; 
		return false;
	}
	if (matrix1.at(0).size() != matrix2.size()) {
		cout << "Unable to multiply" << endl; 
		return false; 
	}
	cout << "Multiplication valid" << endl; 
	return true; 

}

void multMatrices(vector<vector<int>> m1, vector<vector<int>> m2)
{
	vector<vector<int>> multMatrix;
	int total = 0; 

	multMatrix.resize(m1.size());
	for (int i = 0; i < m1.size(); ++i) {
		multMatrix.at(i).resize(m2.at(0).size());
		for (int j = 0; j < m2.at(0).size(); ++j) {
			multMatrix[i][j] = 0;
		}
	}

	for (int row = 0; row < m1.size(); ++row) {
		for (int col = 0; col < m2.at(0).size(); ++col) {
			total = 0;
			for (int k = 0; k < m1.at(0).size(); ++k) {
				total += m1[row][k] * m2[k][col];
			}
			multMatrix[row][col] = total;
			
		}
	}

	displayVector(multMatrix);

}

