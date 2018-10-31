class Solution {
public:
    bool match(char a, char b) {
        if (a == b || b == '.') return true;
        return false;
    }
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ls = strlen(s);
        int lp = strlen(p);
        vector<vector<bool>> h(ls + 1, vector<bool>(lp + 1, false));
        h[0][0] = true;
        for (int i = 0; i <= ls; ++i) {
            for (int j = 0; j <= lp; ++j) {
                if (!i && !j) continue;
                if (j > 0 && i > 0) {
                    if (match(s[i - 1], p[j - 1]) && h[i - 1][j - 1]) h[i][j] = true;
                }
                if (i > 0 && j > 1) {
                    if (p[j - 1] == '*' && match(s[i - 1], p[j - 2]) && h[i - 1][j]) h[i][j] = true;
                }
                if (j > 1) {
                    if (p[j - 1] == '*' && h[i][j - 2]) h[i][j] = true;
                }
            }
        }
        return h[ls][lp];
    }
};
