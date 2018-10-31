class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        vector<vector<int> > minsum(2, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                minsum[i % 2][j] = triangle[i][j] + min(minsum[(i + 1) % 2][j], minsum[(i + 1) % 2][j + 1]); 
            }
        }
        return minsum[0][0];
    }
};
