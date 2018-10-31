class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> q(n);
        vector<bool> c(n, false);
        vector<bool> d1(n + n - 1, false);
        vector<bool> d2(n + n - 1, false);
        ans = 0;
        search(0, n, q, c, d1, d2);
        return ans;
    }
private:
    int ans;
    void search(int r, int n, vector<int> &q, vector<bool> &c, vector<bool> &d1, vector<bool> &d2) {
        if (r == n) {
            ++ans;
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (c[i] || d1[r + i] || d2[n - r - 1 + i]) continue;
                q[r] = i;
                c[i] = d1[r + i] = d2[n - r - 1 + i] = true;
                search(r + 1, n, q, c, d1, d2);
                c[i] = d1[r + i] = d2[n - r - 1 + i] = false;
            }
        }
    } 
};

