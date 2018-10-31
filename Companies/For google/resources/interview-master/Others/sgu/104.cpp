#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > table;

int main() {
	int f, v;
	cin >> f >> v;
	table = vector<vector<int> >(f + 1, vector<int>(v + 1));
	for (int i = 1; i <= f; ++i) {
		for (int j = 1; j <= v; ++j) {
			cin >> table[i][j];
		}
	}
	vector<vector<int> > value(f + 1, vector<int>(v + 1));
	
	for (int i = 1; i <= f; ++i) {
		value[i][i] = value[(i - 1)][i - 1] + table[i][i];
		for (int j = i + 1; j <= v; ++j) 
				value[i][j] = max(value[i][j - 1], value[(i - 1)][j - 1] + table[i][j]);
	}
		
	cout << value[f][v] << endl;
	vector<int> vases(f + 1);
	for (int i = f, j = v; i >= 1 && j >= 1;) {
		if (value[i][j] == value[i - 1][j - 1] + table[i][j])
			vases[i--] = j--;
		else j--;
	}
	for (int i = 1; i <= f; ++i) {
		cout << vases[i] << " ";
	}
	cout << endl;
	return 0;
}