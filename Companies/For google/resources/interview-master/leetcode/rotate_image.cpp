class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        for (int l = 0; l < n / 2; ++l) {
            for (int i = l; i < n - l - 1; ++i) {
                int start = matrix[l][i];
                matrix[l][i] = matrix[n - 1 - i][l];
                matrix[n - 1 - i][l] = matrix[n - 1 - l][n - 1 - i];
                matrix[n - 1 - l][n - 1 - i] = matrix[i][n - 1 - l];
                matrix[i][n - 1 - l] = start;
            }
        }
    }
};
