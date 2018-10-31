class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    if (obstacleGrid[m - 1 - i][n - 1 - j] != 1) {
                        if (i > 0) path[i][j] = path[i - 1][j];
                        else if (j > 0) path[i][j] = path[i][j - 1];
                        else path[i][j] = 1;
                    }
                    else path[i][j] = 0;
                }
                else {
                    if (obstacleGrid[m - 1 - i][n - 1 - j] != 1) 
                        path[i][j] = path[i - 1][j] + path[i][j - 1];
                    else path[i][j] = 0;
                }
            }
        }
        return path[m - 1][n - 1];
    }
};
