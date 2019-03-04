#include<iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int special = n * 2 + 2;
	int size = special + 1;
	char print[size][size];
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j){
			print[i][j] = '.';
		}
	}
	
	int i = special, j = special;
	print[i][j] = print[i][j-1] = print[i][j-2] = print[i-1][j] = print[i-2][j] = '$';
	
	int length = 3;
	
	for (i = i-4; i >= 0; i -= 2) {
		for (int l = 0; l < length; ++l) {
			print[j-l][i] = print[i][j-l] = '$';
		}
		length += 2;
	}
	int x = special;
	while ((x = x - 2) > 0) {
		print[x][x] = print[x-1][x] = print[x][x-1] = '$';
	}
	
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size; ++j) {
			cout << print[i][j];
		}
		for (j = size -2 ; j >= 0; --j) {
			cout << print[i][j];
		}
		cout << endl;
	}
	
	for (i = size - 2; i >=0 ; --i) {
		for (j = 0; j < size; ++j) {
			cout << print[i][j];
		}
		for (j = size -2 ; j >= 0; --j) {
			cout << print[i][j];
		}
		cout << endl;
	}
	
	return 0;
} 
