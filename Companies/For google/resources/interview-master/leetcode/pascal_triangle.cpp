#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > triangle(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i) {
            triangle[i] = vector<int>(i + 1);
            triangle[i][0] = 1;
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle[i][i] = 1;
        }
        return triangle;
    }
};

int main() {
	Solution s;
	int n = 28;
	vector<vector<int> > triangle = s.generate(n);
	for (int i = 0; i < triangle.size(); ++i) {
		cout << "[";
		for (int j = 0; j < triangle[i].size(); ++j) {
			cout << triangle[i][j] << " ";
		}
		cout << "]\n";
	}
	return 0;
}