class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = candidates.size();
        typedef vector<int> comb;
        typedef vector<comb> combset;
        vector<vector<combset>> f(n + 1, vector<combset>(target + 1));
        
        sort(candidates.begin(), candidates.end());
        
        for (int i = 0; i <= n; ++i) {
            f[i][0].push_back(comb());
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                f[i][j] = f[i - 1][j];
                int ci = candidates[i - 1];
                if (ci <= j) {
                    for (comb x : f[i][j - ci]) {
                        x.push_back(ci);
                        f[i][j].push_back(x);
                    }
                }
            }
        }
        return f[n][target];
    }
};
