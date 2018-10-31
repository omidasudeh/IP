class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function       
        vector<vector<int> > triangle(2, vector<int>(rowIndex + 1));
        for (int i = 0; i <= rowIndex; ++i) {
            triangle[i % 2][0] = 1;
            for (int j = 1; j < i; ++j) {
                triangle[i % 2][j] = triangle[(i - 1) % 2][j - 1] + triangle[(i - 1) % 2][j];
            }
            triangle[i % 2][i] = 1;
        }
        return triangle[rowIndex % 2];
    }
};
