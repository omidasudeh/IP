class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = candidates.size();
        typedef vector<int> comb;
        typedef vector<comb> combset;
        vector<combset> f(target + 1);
        
        sort(candidates.begin(), candidates.end());

        f[0].push_back(comb());
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                int ci = candidates[i - 1];
                if (ci <= j) {
                    for (comb x : f[j - ci]) {
                        x.push_back(ci);
                        f[j].push_back(x);
                    }
                }
            }
        }
        return f[target];
    }
};
