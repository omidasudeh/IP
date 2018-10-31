class Solution {
public:
    void subset(int start, int n, vector<int> &S, vector<int> &cur, vector<vector<int> > &ans) {
        if (start == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i < n; ++i) {
            if (i > start && S[i] == S[i - 1]) continue;
            cur.push_back(S[i]);
            subset(i + 1, n, S, cur, ans);
            cur.pop_back();
        }
        subset(n, n, S, cur, ans);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function       
        int n = S.size();
        vector<vector<int> > ans;
        vector<int> current;
        if (n == 0) return ans;
        sort(S.begin(), S.end());
        subset(0, n, S, current, ans);
        return ans;
    }
};
