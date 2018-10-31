#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        vector<int> R, C;
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) 
                if (matrix[i][j] == 0) R.push_back(i), C.push_back(j);
                
        for (int i = 0; i < R.size(); ++i) 
            for (int j = 0; j < col; ++j) 
                matrix[R[i]][j] = 0;
                
        for (int j = 0; j < C.size(); ++j) 
            for (int i = 0; i < row; ++i)
                matrix[i][C[j]] = 0;
    }
};

int main() {
	
}