#include <iostream>
#include <vector>
using namespace std;

vector<int> cate;
vector<vector<int> > cn;

int ncents(int n, int c) {
	for (int i = 0; i < c; ++i) {
		cn[i][0] = 1;
		for (int j = 1; j <= n; ++j) {
			cn[i][j] = 0;
			if (i == 0) {
				cn[i][j] = 1;
				continue;
			}
			for (int k = 0; k * cate[i] <= j; ++k) {
				cn[i][j] += cn[i - 1][j - k * cate[i]];
			}
			cout << i << " " << j << " " << cn[i][j] << endl;
		}		
	}
	return cn[c - 1][n];
}

int main() {
	cate.push_back(1), cate.push_back(2), cate.push_back(5), cate.push_back(10);
	int n = 5;
	cn = vector<vector<int> >(cate.size(), vector<int>(n + 1));
	cout << ncents(n, cate.size()) << endl;
	return 0;
}
	