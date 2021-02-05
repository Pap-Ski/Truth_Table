#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	char on = '1', off = '0';
	int numOfVariables;
	
	cout << "How many variables are you working with: ";
	cin >> numOfVariables;
	int tTableRows = pow(2, numOfVariables);
	int tTableCols = numOfVariables;
	char truthTable[tTableRows+1][tTableCols+1];
	char input = off;
	int inputStep = tTableRows/2;
	truthTable[0][tTableCols] = 'X';
	
	for(int i = 0, a = 65; i < tTableCols; ++i,++a){
		truthTable[0][i] = (char)a;
	}
	
	for(int i = 0; i < tTableCols; ++i){
		int count = 0;
		for(int j = 1; j < tTableRows+1; ++j){
			truthTable[j][i] = input;
			count++;
			if(count == inputStep && input == off) {
				input = on;
				count = 0;
			} else if(count == inputStep && input == on){
				 input = off;
				 count = 0;
			}
		}
		inputStep/=2;
	}
	cout << endl;
	
	cout << "Enter the respective outputs of the combinations: \n";
	
	for(int i = 0; i < tTableCols+1; ++i){
		cout << truthTable[0][i] << " ";
	}
	cout << endl;
	for(int i = 1; i < tTableRows+1; ++i){
		for(int j = 0; j < tTableCols; ++j){
			cout << truthTable[i][j] << " ";
		}
		cin >> truthTable[i][tTableCols];
	}
	
	/*for(int i = 0; i < tTableRows+1; ++i){
		for(int j = 0; j < tTableCols; ++j){
			cout << truthTable[i][j] << " ";
		}
		cout << endl;
	}*/
	
	return 0;
}
