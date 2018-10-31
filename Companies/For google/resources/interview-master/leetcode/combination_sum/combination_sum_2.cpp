class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        typedef vector<int> comb;
        typedef vector<comb> combset;
        
        int n = num.size();
        vector<combset> f(target + 1);
        sort(num.begin(), num.end());
        f[0].push_back(comb());
        
        for (int j = 0; j < n; ++j) {
            int cj = num[j];
            for (int i = target; i >= cj; --i) {
                for (comb x : f[i - cj]) {
                    x.push_back(cj);
                    f[i].push_back(x);
                }
            }
        }
        combset answer = f[target];
        sort(answer.begin(), answer.end());
        combset::iterator it = unique(answer.begin(), answer.end());
        answer.resize(distance(answer.begin(), it));
        return answer;
    }
};
