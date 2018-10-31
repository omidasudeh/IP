class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ans(n, vector<int>(n));
        int num = 1;
        for (int l = 0; l < (n + 1) / 2; ++l) {
            int i = l, j = l;
            for (; j <= n - 1 - l; ++j) {
                ans[i][j] = num++;
            }
            --j;
            if (i + 1 > n - l - 1) continue;
            for (i = i + 1; i < n - l; ++i) {
                ans[i][j] = num++;
            }
            --i;
            for (j = j - 1; j >= l; --j) {
                ans[i][j] = num++;
            }
            ++j;
            for (i = i - 1; i > l; --i) {
                ans[i][j] = num++;
            }
        }
        return ans;
    }
};
