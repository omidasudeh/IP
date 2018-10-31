class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        int layer = min(m, n);
        for (int l = 0; l < (layer + 1) / 2; ++l) {
            int i = l, j = l;
            for (; j < n - l; ++j) {
                ans.push_back(matrix[i][j]);
            }
            --j;
            if (i + 1 >= m - l) continue;
            for (i = i + 1; i < m - l; ++i) {
                ans.push_back(matrix[i][j]);
            }
            --i;
            if (j - 1 < l) continue;
            for (j = j - 1; j >= l; --j) {
                ans.push_back(matrix[i][j]);
            }
            ++j;
            for (i = i - 1; i > l; --i) {
                ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};
