class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        ans.push_back(vector<int>());
        int n = S.size();
        for (int i = 0; i < n; ++i) {
            int size = ans.size();
            for (int j = 0; j < size; ++j) {
                vector<int> cur = ans[j];
                if (cur.empty() || cur.back() < S[i]) cur.push_back(S[i]);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
