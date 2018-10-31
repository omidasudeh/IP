class Solution {
public:
    void comb(int n, int k, int i, vector<bool> &hasused, vector<vector<int> > &ans, vector<int> cur) {
        if (i == k) {
            ans.push_back(cur);
            return;
        }
        vector<int> tmp;
        for (int j = i + 1; j <= n - k + i + 1; ++j) {
            if (!hasused[j]) {
                tmp = cur;
                if (!tmp.empty() && j < tmp.back()) continue;
                hasused[j] = true;
                tmp.push_back(j);
                comb(n, k, i + 1, hasused, ans, tmp);
                hasused[j] = false;
            }
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<bool> hasused(n + 1, false);
        comb(n, k, 0, hasused, ans, vector<int>());
        return ans;
    }
};
