class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> q(n);
        vector<bool> c(n, false);
        vector<bool> d1(n + n - 1, false);
        vector<bool> d2(n + n - 1, false);
        vector<vector<string>> ans;
        search(0, n, q, c, d1, d2, ans);
        return ans;
    }
    
    void search(int r, int n, vector<int> &q, vector<bool> &c, vector<bool> &d1, vector<bool> &d2, vector<vector<string> > &ans) {
        if (r == n) {
            string s = "";
            vector<string> res;
            for (int i = 0; i < n; ++i) {
                s += '.';
            }
            for (int i = 0; i < n; ++i) {
                s[q[i]] = 'Q';
                res.push_back(s);
                s[q[i]] = '.';
            }
            ans.push_back(res);
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (c[i] || d1[r + i] || d2[n - r - 1 + i]) continue;
                q[r] = i;
                c[i] = d1[r + i] = d2[n - r - 1 + i] = true;
                search(r + 1, n, q, c, d1, d2, ans);
                c[i] = d1[r + i] = d2[n - r - 1 + i] = false;
            }
        }
    } 
};

