class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = candidates.size();
        typedef vector<int> comb;
        typedef vector<comb> combset;
        vector<vector<combset>> f(2, vector<combset>(target + 1));
        
        sort(candidates.begin(), candidates.end());
        
        for (int i = 0; i <= 1; ++i) {
            f[i % 2][0].push_back(comb());
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                f[i % 2][j] = f[(i - 1) % 2][j];
                int ci = candidates[i - 1];
                if (ci <= j) {
                    for (comb x : f[i % 2][j - ci]) {
                        x.push_back(ci);
                        f[i % 2][j].push_back(x);
                    }
                }
            }
        }
        return f[n % 2][target];
    }
};
