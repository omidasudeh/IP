class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minsum(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) minsum[i][j] = grid[m - 1 - i][n - 1 - j];
                else if (i == 0 || j == 0) {
                    if (i > 0) minsum[i][j] = grid[m - 1 - i][n - 1 - j] + minsum[i - 1][j];
                    else minsum[i][j] = grid[m - 1 - i][n - 1 - j] + minsum[i][j - 1];
                }
                else {
                    minsum[i][j] = min(minsum[i - 1][j], minsum[i][j - 1]);
                    minsum[i][j] += grid[m - 1 - i][n - 1 - j];
                }
            }
        }
        return minsum[m - 1][n - 1];
    }
};
